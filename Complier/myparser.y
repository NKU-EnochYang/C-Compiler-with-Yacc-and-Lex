%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018��11��22��
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

typedef enum {StmtK,ExpK} NodeKind;
typedef enum {IfK,WhileK,ForK,CompK, InputK, PrintK} StmtKind;
typedef enum {OpK,ConstK,IdK,TypeK,VarK,AssignK} ExpKind;
typedef enum {Void,Integer,Char,Boolean} ExpType;
#define MAXCHILDREN 4
int line=0;
int Num=0;
struct TreeNode
   { 
	struct TreeNode * child[MAXCHILDREN];
     struct TreeNode * sibling;
     int lineno;
     int nodekind;
     int kind;
     union{ int op;
             int val;
           char *name; }attr;
     int value;
     int type; /* for type checking of exps */
     int tempid;
   } ;
TreeNode * newStmtNode(int kind)
{ 
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
   printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind = kind;
    t->lineno = line++;
  }
  return t;  
}
TreeNode * newExpNode(int kind)
{
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind = kind;
    t->lineno = line++;
    t->type = Void;
  }
  return t;
}

TreeNode *root;
//tree = (struct TreeNode *) malloc (sizeof(struct TreeNode));
//TreeNode* root;
void ShowTree(struct TreeNode *p);		//��ʾ�﷨��
void ShowNode(struct TreeNode *p);		//��ʾĳ���ڵ�

void type_check(TreeNode *root);
void traverse(TreeNode *root);
void check_node(TreeNode *root);


void gen_asm(ofstream &out, TreeNode *r);
void gen_header(ofstream &out);
void gen_data(ofstream &out, TreeNode *r);
void gen_code(ofstream &out, TreeNode *r);
void gen_code_stmt(ofstream &out, TreeNode *r);
void gen_code_exp(ofstream &out, TreeNode *r);
void gen_plus(ofstream &out, TreeNode *r1, TreeNode *r2);// +
void gen_minus(ofstream &out, TreeNode *r1, TreeNode *r2);// -
void gen_times(ofstream &out, TreeNode *r1, TreeNode *r2);// *
void gen_over(ofstream &out, TreeNode *r1, TreeNode *r2);// /
void gen_remi(ofstream &out, TreeNode *r1, TreeNode *r2);// %
void gen_dplus(ofstream &out, TreeNode *r);// ++
void gen_dminus(ofstream &out, TreeNode *r);// --
void gen_ge(ofstream &out, TreeNode *r1, TreeNode *r2);// >=
void gen_le(ofstream &out, TreeNode *r1, TreeNode *r2);// <=
void gen_gt(ofstream &out, TreeNode *r1, TreeNode *r2);// >
void gen_lt(ofstream &out, TreeNode *r1, TreeNode *r2);// <
void gen_neq(ofstream &out, TreeNode *r1, TreeNode *r2);// !=
void gen_and(ofstream &out, TreeNode *r1, TreeNode *r2);// &&
void gen_or(ofstream &out, TreeNode *r1, TreeNode *r2);// ||
void gen_eq(ofstream &out, TreeNode *r1, TreeNode *r2);// ==
void gen_assign(ofstream &out, TreeNode *r1, TreeNode *r2);// =

int stmn = 0;
int cur_temp = 0;
int labeln = 0;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif
}

// place any declarations here
%token IF MAIN FOR WHILE 
%token INT CHAR VOID 
%token ID NUM
%token PLUS MINUS TIMES OVER REMI DPLUS DMINUS
%token LT LE GT GE EQ NEQ ASSIGN AND OR NOT
%token SEMI COMMA LP RP LFP RFP 
%token INPUT PRINT

%left	COMMA 
%right	ASSIGN 
%left	EQ NEQ 
%left	LT LE GT GE 
%left	PLUS MINUS 
%left   TIMES OVER REMI 
%left   DPLUS DMINUS
%left	LP RP LFP RFP 
%right	ELSE 

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
start		:MAIN LP RP comp_stmt
			{ 
			    $$ = $4;
				ShowTree($4);
				root = $4;
				//type_check($4);
				ofstream out;
				out.open("output.txt", 'w');
				gen_asm(out, $4);
			}
			;
comp_stmt	:LFP  stmt_list RFP
			{	
				$$ = newStmtNode(CompK);
				$$->child[0]=$2;
			}
			;
stmt_list	:stmt stmt_list		
			{
				$$->sibling=$2;
				$$= $1;		
			}
			|stmt						
			{
				$$ = $1 ;
			}
			;
stmt		:var_dec				
			{	
				$$ = $1;
			}
			|exp_stmt					
			{	
				$$ = $1;
			}
			|if_stmt					
			{	
				$$ = $1;
			}
			|for_stmt
			{
				$$ = $1;
			}
			|while_stmt 
			{
				$$ = $1;
			}        
			|comp_stmt					
			{	
				$$ = $1;
			}
            |input_stmt
            {
                $$ = $1;
            }
            |print_stmt
            {
                $$ = $1;
            }
			;			
type_spec	:INT	
			{
				$$ = newExpNode(TypeK);//int
                $$->type=Integer;
                   
			}	
			|CHAR	
			{
				$$ = newExpNode(TypeK);//char
                $$->type=Char;
			}
			|VOID	
			{
				$$ = newExpNode(TypeK);//void
                $$->type=Void;
			}
			;
id_list		:exp COMMA id_list//���ʽ�����ʽ
			{
				$$ = $1;
				$$->sibling=$3;
			}
			|exp
			;			             
var_dec		:type_spec id_list SEMI//�������� int/char a=/a;
			{	
				$$ = newExpNode (VarK);//����һ���µı��������Ľڵ�
				$$->child[0]=$1;
				$$->child[1]=$2;
			}
			;

if_stmt     :IF LP exp RP stmt //if(exp) stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
      
            | IF LP exp RP  stmt ELSE stmt//if (exp) stmt else stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;
for_stmt	:FOR LP exp SEMI exp SEMI exp RP stmt//for(exp;exp;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
                $$->child[3] = $9;
			}
			|FOR LP SEMI exp SEMI exp RP stmt//for(;exp;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = $4;
                $$->child[2] = $6;
                $$->child[3] = $8;
			}
			|FOR LP exp SEMI SEMI exp RP stmt//for(exp;;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
				$$->child[1] = NULL;
                $$->child[2] = $6;
                $$->child[3] = $8;
			}
			|FOR LP exp SEMI exp SEMI RP stmt//for(exp;exp;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $8;
                $$->child[3] = NULL;
			}
			|FOR LP SEMI SEMI exp RP stmt//for(;;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = NULL;
				$$->child[2] = $5;
                $$->child[3] = $7;
			}
			|FOR LP SEMI exp SEMI RP stmt//for(;exp;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = $4;
				$$->child[2] = NULL;
                $$->child[3] = $7;
			}
			|FOR LP exp SEMI SEMI RP stmt//for(exp;;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
				$$->child[1] = NULL;
				$$->child[2] = NULL;
                $$->child[3] = $7;
			}
			|FOR LP SEMI SEMI RP stmt//for(;;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = NULL;
				$$->child[2] = NULL;
				$$->child[3] = $6;
			}
			;
while_stmt	:WHILE LP exp RP stmt//while(exp)
			{
				$$ = newStmtNode(WhileK);
				$$->child[0] = $3;
                $$->child[1] = $5;
			}
			;
exp_stmt	:exp SEMI		//exp;
			{
				$$ = $1;
			}
			|SEMI
			;
exp			:exp ASSIGN exp//exp=exp
			{
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op = ASSIGN;
			}			
			|or_exp
			{
			    $$ = $1;
			}
			;
or_exp      :or_exp OR and_exp
            {
                $$ = newExpNode(OpK);
                $$ -> attr.op =OR;
                $$ ->child[0] = $1;
                $$ -> child[1] = $3;
            }
            |and_exp
            {
                $$ = $1;
            }
            ;
and_exp     :and_exp AND exp_equ
            {
                $$ = newExpNode(OpK);
                $$ -> attr.op = AND;
                $$ -> child[0] = $1;
                $$ -> child[1] = $3;
            }
            |exp_equ
            {
                $$ = $1;
            }
            ;
exp_equ     :exp_equ EQ simple_exp//==
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=EQ;
			}
			|exp_equ LE simple_exp//<=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=LE;
			}
			|exp_equ GE simple_exp//>=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=GE;
			}
			|exp_equ LT simple_exp//<
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=LT;
			}
			|exp_equ GT simple_exp	//>
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=GT;
			}
			|exp_equ NEQ simple_exp	//!=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=NEQ;
			}
			|simple_exp
			{
				$$ = $1;
			}
			;
simple_exp  : simple_exp PLUS term //+ - * / ++ --
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = PLUS;

                 }
            | simple_exp MINUS term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MINUS;

                 } 
            | simple_exp TIMES term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = TIMES;
                 } 
            | simple_exp OVER term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OVER;
                 } 
            | simple_exp REMI term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = REMI;
                 } 
            |simple_exp DPLUS 
			{
				$$ = newExpNode(OpK); 
				$$->child[0] = $1;
                $$->attr.op = DPLUS;

			}
			|simple_exp DMINUS 
			{
				$$ = newExpNode(OpK); 
				$$->child[0] = $1;
                $$->attr.op = DMINUS;

			}
            | term { $$ = $1; }
            ;
term		:LP exp RP				
			{
				$$ = $2;
			}
			|ID					
			{
				$$ = $1;
			}
			|NUM				
			{
				$$ = $1;
			}
			|NOT term
			{
			   $$ = newExpNode(OpK);
			   $$ -> attr.op = NOT;
			   $$ -> child[0] =$2;
			}
			;
input_stmt  :INPUT LP exp RP SEMI
            {
                $$ = newStmtNode(InputK);
                $$ -> child[0] = $3;
                //$$->attr.name = $3->attr.name;
            }
            ;
print_stmt  :PRINT LP exp RP SEMI
            {
                $$ = newStmtNode(PrintK);
                $$ -> child[0] = $3;
                //$$->attr.name = $3->attr.name;
            }
            ;
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

void ShowTree(struct TreeNode *p)
{
	//root=p;
	struct TreeNode *temp ;
	temp =(struct TreeNode *) malloc (sizeof(struct TreeNode));
    for(int i=0;i<MAXCHILDREN;i++)
    {
	   if(p->child[i] != NULL)
	   {
		ShowTree(p->child[i]);
	   }
	}
	ShowNode(p);
	temp=p->sibling;
	if(temp!=NULL){
    	ShowTree(temp);
	}	
	return;		
}

void ShowNode(struct TreeNode *p)
{
    p->lineno=Num++;
	struct TreeNode *temp ;
	temp = (struct TreeNode *) malloc (sizeof(struct TreeNode));
	printf("%d:",p->lineno);
	switch(p->nodekind)
	{
		case StmtK:
		{
			char *names[7] = {"If_statement,",  "While_statement,", "For_statement," , "Compound_statement,","Input_statement,","Print_statement," };
			printf("%s\t\t\t",names[p->kind]);
			break;
		}
			
		case ExpK:
		{
			char *names[5] = {"Expr," , "Const Declaration,", "ID Declaration,","Type Specifier,", "Var Declaration," };
			char *types[3] = {"Void","Integer ","Char"};
			printf("%s\t", names[ p->kind ]);
			
			switch( p->kind )
			{
				case OpK:
					{
					   switch(p->attr.op)
					   {
					       case PLUS:
					       {
					           printf("\top:+\t\t");
					           break;
					       }
					       case MINUS:
					       {
					           printf("\top:-\t\t");
					           break;
					       }
					       case TIMES:
					       {
					           printf("\top:*\t\t");
					           break;
					       }
					       case OVER:
					       {
					           printf("\top:/\t\t");
					           break;
					       }
					       case REMI:
					       {
					           printf("\top:%\t\t");
					           break;
					       }
					       case DPLUS:
					       {
					           printf("\t\top:++\t\t");
					           break;
					       }
					       case DMINUS:
					       {
					           printf("\t\top:--\t\t");
					           break;
					       }
					       case LT:
					       {
					           printf("\t\top:<\t\t");
					           break;
					       }
					       case LE:
					       {
					           printf("\t\top:<=\t\t");
					           break;
					       }
					       case GT:
					       {
					           printf("\t\top:>\t\t");
					           break;
					       }
					       case GE:
					       {
					           printf("\t\top:>=\t\t");
					           break;
					       }	
					       case EQ:
					       {
					           printf("\t\top:==\t\t");
					           break;
					       }
					       case NOT:
					       {
					           printf("\t\top:!=\t\t");
					           break;
					       }
					       case OR:
					       {
					           printf("\t\top:||\t\t");
					           break;
					       }
					       case AND:
					       {
					           printf("\t\top:&&\t\t");
					           break;
					       }
					       case ASSIGN:
					       {
					           printf("\top:=\t\t");
					       }
					   }
					   break;
					}
				case ConstK:
					{
						printf("values: %d\t",p->attr.val);
						break;
					}
				case IdK:
					{
						printf("symbol: %s\t",p->attr.name);
						break;
					}
				case TypeK:
					{
						printf("%s\t", types[ p->type ]);
						break;
					}
				case VarK:
				{
					printf("\t\t");
					break;
				}
			}
			break;
		}
		
	}
	printf("children: ");
	for(int i=0;i<MAXCHILDREN;i++){
	    if(p->child[i] != NULL)
	    {
		    printf("%d  ",p->child[i]->lineno);
		    temp = p->child[i]->sibling;
		
		    while(temp != NULL)
		    {
			    printf("%d  ",temp->lineno);
			    temp = temp->sibling;
		    }
		
	    }
	}
	printf("\n");
	return ;
}

void type_check(TreeNode *root)
{
	traverse(root);
}

void traverse(TreeNode *root)
{
	if(root != NULL)
	{
		for(int i = 0;i<MAXCHILDREN;i++)
		{
			if(root->child[i] != NULL)
				traverse(root->child[i]);
		}
		if(root->sibling != NULL)
			traverse(root->sibling);
		check_node(root);
	}
}

void check_node(TreeNode *root)
{
	root->lineno=Num++;
	struct TreeNode *temp ;
	temp = (struct TreeNode *) malloc (sizeof(struct TreeNode));
	printf("%d:",root->lineno);
	switch(root->nodekind)
	{
		case StmtK:
		{
			char *names[7] = {"If_statement,",  "While_statement,", "For_statement," , "Compound_statement,","Input_statement,","Print_statement," };
			printf("%s\t\t",names[root->kind]);
			switch(root->kind)
			{
			case IfK:
			{
				if(root->child[0]->type != Boolean)
				{
					printf("if test is not boolean. \t\t");
				}
				break;
			}
			case WhileK:
			{
				if(root->child[0]->type != Boolean)
				{
					printf("while test is not boolean. \t\t");
				}
				break;
			}
			case ForK:
			{
				if((root->child[0] != NULL && root->child[0]->type != Integer) || (root->child[1] != NULL && root->child[1]->type != Boolean)
				   || (root->child[2] != NULL && root->child[2]->type != Integer))
				{
					printf("for test error. \t\t");
				}
				break;
			}
			}
			break;
		}
			
		case ExpK:
		{
			char *names[5] = {"Expr," , "Const Declaration,", "ID Declaration,","Type Specifier,", "Var Declaration," };
			char *types[3] = {"Void","Integer ","Char"};
			printf("%s\t", names[ root->kind ]);
			
			switch( root->kind )
			{
				case OpK:
					{
					   switch(root->attr.op)
					   {
					       case PLUS:
					       {
					           printf("\top:+\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case MINUS:
					       {
					           printf("\top:-\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case TIMES:
					       {
					           printf("\top:*\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case OVER:
					       {
					           printf("\top:/\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case REMI:
					       {
					           printf("\top:%\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case DPLUS:
					       {
					           printf("\t\top:++\t\t");
					           if((root->child[0]->type != Integer) && (root->child[0]->type != Char))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case DMINUS:
					       {
					           printf("\t\top:--\t\t");
					           if((root->child[0]->type != Integer) && (root->child[0]->type != Char))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case LT:
					       {
					           printf("\t\top:<\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					           break;
					       }
					       case LE:
					       {
					           printf("\t\top:<=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					           break;
					       }
					       case GT:
					       {
					           printf("\t\top:>\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					           break;
					       }
					       case GE:
					       {
					           printf("\t\top:>=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					           break;
					       }	
					       case EQ:
					       {
					           printf("\t\top:==\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					           break;
					       }
					       case NOT:
					       {
					           printf("\t\top:!=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					           break;
					       }
					       case OR:
					       {
					           printf("\t\top:||\t\t");
					           if((root->child[0]->type != Boolean) || (root->child[1]->type != Boolean))
					           {
					               printf("or test is not boolean.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case AND:
					       {
					           printf("\t\top:&&\t\t");
					           if((root->child[0]->type != Boolean) || (root->child[1]->type != Boolean))
					           {
					               printf("or test is not boolean.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case ASSIGN:
					       {
					           printf("\top:=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Boolean;
					       }
					   }
					   break;
					}
				case ConstK:
					{
						printf("values: %d\t",root->attr.val);
						break;
					}
				case IdK:
					{
						printf("symbol: %s\t",root->attr.name);
						root->type = Integer;
						break;
					}
				case TypeK:
					{
						printf("%s\t", types[ root->type ]);
						break;
					}
				case VarK:
				{
					printf("\t\t");
					break;
				}
			}
			break;
		}
		
	}
	printf("children: ");
	for(int i=0;i<MAXCHILDREN;i++){
	    if(root->child[i] != NULL)
	    {
		    printf("%d  ",root->child[i]->lineno);
		    temp = root->child[i]->sibling;
		
		    while(temp != NULL)
		    {
			    printf("%d  ",temp->lineno);
			    temp = temp->sibling;
		    }
		
	    }
	}
	printf("\n");
}


void gen_asm(ofstream &out, TreeNode *r)
{
    gen_header(out);
    out << endl << endl << "\t.data" << endl;
    out<<"\ttype0 db '%d', 0"<<endl;
    out<<"\ttype1 db '%d ', 0"<<endl;
    out<<"\tindata DWORD ?"<<endl;
    for(int i = 0;i<10;i++)
        out<<"\tt"<<i<<"\tDWORD 0"<<endl;
    gen_data(out, r);
    cur_temp = 0;
    out << endl << endl << "\t.code" << endl;
    out<<"_start:"<<endl;
    gen_code(out, r);
    out << "\tinvoke crt_scanf, addr type0, indata"<<endl;
    out << "\tinvoke ExitProcess, 0" << endl;
    out << "end _start" <<endl;
}

void gen_header(ofstream &out)
{
  out << "\t.586" << endl;
  out << "\t.model flat, stdcall" << endl;
  out << "\toption casemap :none" << endl;
  out << endl;
  out << "\tinclude \\masm32\\include\\windows.inc" << endl;
  out << "\tinclude \\masm32\\include\\user32.inc" << endl;
  out << "\tinclude \\masm32\\include\\kernel32.inc" << endl;
  out << "\tinclude \\masm32\\include\\masm32.inc" << endl;
  out << endl;
  out << "\tincludelib \\masm32\\lib\\user32.lib" << endl;
  out << "\tincludelib \\masm32\\lib\\kernel32.lib" << endl;
  out << "\tincludelib \\masm32\\lib\\masm32.lib" << endl;
  out << endl;
  out << "\tinclude \\masm32\\macros\\macros.asm" << endl;
  out << "\tinclude \\masm32\\include\\msvcrt.inc" << endl;
  out << "\tincludelib \\masm32\\lib\\msvcrt.lib" << endl;
}


void gen_data(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    for(;t != NULL;t = t->sibling)
    {
        switch(t->nodekind)
        {
            case StmtK:
            {
                switch(t->kind)
                {
                    case IfK:
                    {
                        //if(t->child[0]) gen_data(out, t->child[0]);
                        if(t->child[1]) gen_data(out, t->child[1]);
                        if(t->child[2]) gen_data(out, t->child[2]);
                        break;
                    }
                    case WhileK:
                    {
                        //if(t->child[0]) gen_data(out, t->child[0]);
                        if(t->child[1]) gen_data(out, t->child[1]);
                        break;
                    }
                    case ForK:
                    {
                        if(t->child[0]) gen_data(out, t->child[0]);
                        //if(t->child[1]) gen_data(out, t->child[1]);
                        //if(t->child[2]) gen_data(out, t->child[2]);
                        if(t->child[3]) gen_data(out, t->child[3]);
                        break;
                    }
                    case CompK:
                    {
                        if(t->child[0]) gen_data(out, t->child[0]);
                        break;
                    }
                    case InputK:
                    {
                        //out<<t->child[0]->attr.name<<endl;
                        break;
                    }
                    case PrintK:
                    {
                        //out<<t->child[0]->attr.name<<endl;
                        break;
                    }
                }
                break;
            }
            case ExpK:
            {
                switch(t->kind)
                {
                    case OpK:
                    {
                        //if(t->child[0]) gen_data(out, t->child[0]);
                        //if(t->child[1]) gen_data(out, t->child[1]);
                        break;
                    }
                    case IdK:
                    {
                        out<<"\t_"<<t->attr.name<<"\tDWORD 0"<<endl;
                        break;
                    }
                    case ConstK:
                    {
                        break;
                    }
                    case TypeK:
                    {
                        break;
                    }
                    case VarK:
                    {
                        gen_data(out, t->child[1]);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void gen_code(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    while(t != NULL)
    {
        switch(t->nodekind)
        {
            case StmtK:
            {
                gen_code_stmt(out, t);
                break;
            }
            case ExpK:
            {
                gen_code_exp(out, t);
                break;
            }
        }
        t = t->sibling;
    }
}

void gen_code_stmt(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    int mark1, mark2;
    switch(r->kind)
    {
        case IfK:
        {
            mark1 = stmn;
            if(t->child[2])
            {
                mark2 = stmn + 1;
                stmn += 2;
            }
            else
            {
                stmn += 1;
            }
            if(t->child[0]->kind == ConstK)
            {
                if(t->child[0]->attr.val == 0)
                {
                    out<<"\tJMP @"<<mark1<<endl;
                }
            }
            else
            {
                gen_code(out, t->child[0]);
                out<<"\tCMP eax, 0"<<endl;
                out<<"\tJE @"<<mark1<<endl;
            }
            if(t->child[1]) gen_code(out, t->child[1]);
            if(r->child[2]) out<<"\tJMP @"<<mark2<<endl;
            out<<"label"<<labeln+1<<":"<<endl;
            out<<"@"<<mark1<<":"<<endl;
            labeln+=2;
            if(t->child[2])
            {
                gen_code(out, t->child[2]);
                out<<"@"<<mark2<<":"<<endl;
            }
            break;
        }
        case WhileK:
        {
            mark1 = stmn;
            mark2 = stmn + 1;
            stmn += 2;
            out<<"@"<<mark1<<":"<<endl;
            if(t->child[0]->kind == ConstK)
            {
                if(t->child[0]->attr.val == 0)
                {
                    out<<"\tJMP @"<<mark2<<endl;
                }
            }
            else
            {
                gen_code(out, t->child[0]);
            }
            if(t->child[1]) gen_code(out, t->child[1]);
            out<<"\tJMP @"<<mark1<<endl;
            out<<"label"<<labeln+1<<":"<<endl;
            labeln+=2;
            out<<"@"<<mark2<<":"<<endl;
            break;
        }
        case ForK:
        {
            mark1 = stmn;
            mark2 = stmn + 1;
            stmn += 2;
            gen_code(out, t->child[0]);
            out<<"@"<<mark1<<":"<<endl;
            if(t->child[1]->kind == ConstK)
            {
                if(t->child[1]->attr.val == 0)
                {
                    out<<"\tJMP @"<<mark2<<endl;
                }
            }
            else
            {
                gen_code(out, t->child[1]);
            }
            if(t->child[3]) gen_code(out, t->child[3]);
            gen_code(out, t->child[2]);
            out<<"\tJMP @"<<mark1<<endl;
            out<<"label"<<labeln+1<<":"<<endl;
            labeln+=2;
            out<<"@"<<mark2<<":"<<endl;
            break;
        }
        case CompK:
        {
            if(t->child[0]) gen_code(out, t->child[0]);
            break;
        }
        case InputK:
        {
            out<<"\tMOV eax, sval(input(\"Enter a number : \"))"<<endl;
            out<<"\tmov _"<<t->child[0]->attr.name<<", "<<"eax"<<endl;
            break;
        }
        case PrintK:
        {
            out<<"\tinvoke crt_printf, addr type1, _"<<t->child[0]->attr.name<<endl;
            break;
        }
    }
}

void gen_code_exp(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    switch(t->kind)
    {
        case OpK:
        {
            if(t->child[0]->kind == OpK) gen_code(out, t->child[0]);
            if(t->child[1]->kind == OpK) gen_code(out, t->child[1]);
            switch(t->attr.op)
            {
                case PLUS: 
                    gen_plus(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case MINUS: 
                    gen_minus(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case TIMES: 
                    gen_times(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case OVER: 
                    gen_over(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case REMI: 
                    gen_remi(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case GE: 
                    gen_ge(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case LE: 
                    gen_le(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case GT: 
                    gen_gt(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case LT: 
                    gen_lt(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case AND: 
                    gen_and(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case OR: 
                    gen_or(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case EQ: 
                    gen_eq(out, t->child[0], t->child[1]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case ASSIGN: 
                    gen_assign(out, t->child[0], t->child[1]); 
                    break;
                case DPLUS: 
                    gen_dplus(out, t->child[0]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
                case DMINUS: 
                    gen_dminus(out, t->child[0]); 
                    t->tempid = cur_temp;
                    cur_temp++;
                    break;
            }
            break;
        }
        case ConstK:
        {
            out<<"\tMOV eax, "<<t->attr.val<<endl;
            break;
        }
        case IdK:
        {
            out<<"\tMOV eax, _"<<t->attr.name<<endl;
            break;
        }
        case TypeK:
        {
            break;
        }
        case VarK:
        {
            break;
        }
    }
}

void gen_plus(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tADD eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tADD eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tADD eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_minus(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tSUB eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tSUB eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tSUB eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_times(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tIMUL eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tIMUL eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tIMUL eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_over(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tMOV ecx, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tMOV ecx, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tMOV ecx, t"<<r2->tempid<<endl;
    out<<"\tDIV ecx"<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_remi(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    out<<"\tMOV edx, 0"<<endl;
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tMOV ecx, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tMOV ecx, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tMOV ecx, t"<<r2->tempid<<endl;
    out<<"\tDIV ecx"<<endl;
    out<<"\tMOV t"<<cur_temp<<", edx"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_dplus(ofstream &out, TreeNode *r)
{
    if (r->kind == ConstK)
        out<<"\tMOV eax, "<<r->attr.val<<endl;
    else if(r->kind == IdK)
        out<<"\tMOV eax, _"<<r->attr.name<<endl;
    else if(r->kind == OpK)
        out<<"\tMOV eax, t"<<r->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
    out<<"\tINC eax"<<endl;
    out<<"\tMOV _"<<r->attr.name<<", eax"<<endl;
}

void gen_dminus(ofstream &out, TreeNode *r)
{
    if (r->kind == ConstK)
        out<<"\tMOV eax, "<<r->attr.val<<endl;
    else if(r->kind == IdK)
        out<<"\tMOV eax, _"<<r->attr.name<<endl;
    else if(r->kind == OpK)
        out<<"\tMOV eax, t"<<r->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
    out<<"\tDEC eax"<<endl;
    out<<"\tMOV _"<<r->attr.name<<", eax"<<endl;
}

void gen_ge(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    out<<"\tJGE label"<<labeln<<endl;
    out<<"\tJMP label"<<labeln+1<<endl;
    out<<"label"<<labeln<<":"<<endl;
}

void gen_le(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    out<<"\tJLE label"<<labeln<<endl;
    out<<"\tJMP label"<<labeln+1<<endl;
    out<<"label"<<labeln<<":"<<endl;
}

void gen_gt(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    out<<"\tJG label"<<labeln<<endl;
    out<<"\tJMP label"<<labeln+1<<endl;
    out<<"label"<<labeln<<":"<<endl;
}

void gen_lt(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    out<<"\tJL label"<<labeln<<endl;
    out<<"\tJMP label"<<labeln+1<<endl;
    out<<"label"<<labeln<<":"<<endl;
}

void gen_neq(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    out<<"\tJNE label"<<labeln<<endl;
    out<<"\tJMP label"<<labeln+1<<endl;
    out<<"label"<<labeln<<":"<<endl;
}

void gen_eq(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    out<<"\tJE label"<<labeln<<endl;
    out<<"\tJMP label"<<labeln+1<<endl;
    out<<"label"<<labeln<<":"<<endl;
}

void gen_and(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tAND eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tAND eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tAND eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_or(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tOR eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tOR eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tOR eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<cur_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<cur_temp<<endl;
}

void gen_assign(ofstream &out, TreeNode *r1, TreeNode *r2)
{
    if(r2 != NULL) gen_code(out, r2);
    out<<"\tMOV _"<<r1->attr.name<<", eax"<<endl;
}


int main(void)
{
    int n = 1;
    mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}