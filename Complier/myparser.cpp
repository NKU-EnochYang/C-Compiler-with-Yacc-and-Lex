/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 82 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 01/12/19
* Time: 18:55:15
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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

#line 149 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 124 ".\\myparser.y"

	// place any extra initialisation code here

#line 173 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 129 ".\\myparser.y"

	// place any extra cleanup code here

#line 187 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 166 ".\\myparser.y"
 
			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4);
				ShowTree(yyattribute(4 - 4));
				root = yyattribute(4 - 4);
				//type_check($4);
				ofstream out;
				out.open("output.txt", 'w');
				gen_asm(out, yyattribute(4 - 4));
			
#line 305 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 177 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 3);
			
#line 321 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 183 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr)->sibling=yyattribute(2 - 2);
				(*(YYSTYPE YYFAR*)yyvalptr)= yyattribute(1 - 2);		
			
#line 337 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 188 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1) ;
			
#line 352 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 193 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 367 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 197 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 382 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 201 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 397 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 205 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 412 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 209 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 427 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 213 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 442 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 217 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 457 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 221 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 472 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 226 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//int
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Integer;
                   
			
#line 489 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 232 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//char
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Char;
			
#line 505 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 237 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//void
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Void;
			
#line 521 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 243 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling=yyattribute(3 - 3);
			
#line 537 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 250 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode (VarK);//����һ���µı��������Ľڵ�
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(2 - 3);
			
#line 554 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 258 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                 
#line 570 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 264 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
                 
#line 587 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 271 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
			
#line 606 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 279 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
			
#line 625 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 287 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
			
#line 644 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 295 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(8 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = NULL;
			
#line 663 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 303 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
			
#line 682 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 311 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
			
#line 701 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 319 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
			
#line 720 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 327 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(6 - 6);
			
#line 739 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 336 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
			
#line 756 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 343 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
			
#line 771 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 349 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op = ASSIGN;
			
#line 789 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 356 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 804 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 361 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op =OR;
                (*(YYSTYPE YYFAR*)yyvalptr) ->child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[1] = yyattribute(3 - 3);
            
#line 822 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 368 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 837 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 373 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op = AND;
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[1] = yyattribute(3 - 3);
            
#line 855 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 380 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 870 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 385 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=EQ;
			
#line 888 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 392 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=LE;
			
#line 906 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 399 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=GE;
			
#line 924 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 406 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=LT;
			
#line 942 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 413 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=GT;
			
#line 960 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 420 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=NEQ;
			
#line 978 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 427 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 993 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 432 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = PLUS;

                 
#line 1011 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 439 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = MINUS;

                 
#line 1029 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 446 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = TIMES;
                 
#line 1046 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 452 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = OVER;
                 
#line 1063 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 458 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = REMI;
                 
#line 1080 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 464 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK); 
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = DPLUS;

			
#line 1098 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 471 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK); 
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = DMINUS;

			
#line 1116 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 477 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1129 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 480 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
			
#line 1144 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 484 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1159 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 488 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1174 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 492 ".\\myparser.y"

			   (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
			   (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op = NOT;
			   (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] =yyattribute(2 - 2);
			
#line 1191 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 499 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
                //$$->attr.name = $3->attr.name;
            
#line 1208 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 506 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(PrintK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
                //$$->attr.name = $3->attr.name;
            
#line 1225 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "IF", 257 },
		{ "MAIN", 258 },
		{ "FOR", 259 },
		{ "WHILE", 260 },
		{ "INT", 261 },
		{ "CHAR", 262 },
		{ "VOID", 263 },
		{ "ID", 264 },
		{ "NUM", 265 },
		{ "PLUS", 266 },
		{ "MINUS", 267 },
		{ "TIMES", 268 },
		{ "OVER", 269 },
		{ "REMI", 270 },
		{ "DPLUS", 271 },
		{ "DMINUS", 272 },
		{ "LT", 273 },
		{ "LE", 274 },
		{ "GT", 275 },
		{ "GE", 276 },
		{ "EQ", 277 },
		{ "NEQ", 278 },
		{ "ASSIGN", 279 },
		{ "AND", 280 },
		{ "OR", 281 },
		{ "NOT", 282 },
		{ "SEMI", 283 },
		{ "COMMA", 284 },
		{ "LP", 285 },
		{ "RP", 286 },
		{ "LFP", 287 },
		{ "RFP", 288 },
		{ "INPUT", 289 },
		{ "PRINT", 290 },
		{ "ELSE", 291 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: start",
		"start: MAIN LP RP comp_stmt",
		"comp_stmt: LFP stmt_list RFP",
		"stmt_list: stmt stmt_list",
		"stmt_list: stmt",
		"stmt: var_dec",
		"stmt: exp_stmt",
		"stmt: if_stmt",
		"stmt: for_stmt",
		"stmt: while_stmt",
		"stmt: comp_stmt",
		"stmt: input_stmt",
		"stmt: print_stmt",
		"type_spec: INT",
		"type_spec: CHAR",
		"type_spec: VOID",
		"id_list: exp COMMA id_list",
		"id_list: exp",
		"var_dec: type_spec id_list SEMI",
		"if_stmt: IF LP exp RP stmt",
		"if_stmt: IF LP exp RP stmt ELSE stmt",
		"for_stmt: FOR LP exp SEMI exp SEMI exp RP stmt",
		"for_stmt: FOR LP SEMI exp SEMI exp RP stmt",
		"for_stmt: FOR LP exp SEMI SEMI exp RP stmt",
		"for_stmt: FOR LP exp SEMI exp SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI exp RP stmt",
		"for_stmt: FOR LP SEMI exp SEMI RP stmt",
		"for_stmt: FOR LP exp SEMI SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI RP stmt",
		"while_stmt: WHILE LP exp RP stmt",
		"exp_stmt: exp SEMI",
		"exp_stmt: SEMI",
		"exp: exp ASSIGN exp",
		"exp: or_exp",
		"or_exp: or_exp OR and_exp",
		"or_exp: and_exp",
		"and_exp: and_exp AND exp_equ",
		"and_exp: exp_equ",
		"exp_equ: exp_equ EQ simple_exp",
		"exp_equ: exp_equ LE simple_exp",
		"exp_equ: exp_equ GE simple_exp",
		"exp_equ: exp_equ LT simple_exp",
		"exp_equ: exp_equ GT simple_exp",
		"exp_equ: exp_equ NEQ simple_exp",
		"exp_equ: simple_exp",
		"simple_exp: simple_exp PLUS term",
		"simple_exp: simple_exp MINUS term",
		"simple_exp: simple_exp TIMES term",
		"simple_exp: simple_exp OVER term",
		"simple_exp: simple_exp REMI term",
		"simple_exp: simple_exp DPLUS",
		"simple_exp: simple_exp DMINUS",
		"simple_exp: term",
		"term: LP exp RP",
		"term: ID",
		"term: NUM",
		"term: NOT term",
		"input_stmt: INPUT LP exp RP SEMI",
		"print_stmt: PRINT LP exp RP SEMI"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 3, 2, 2 },
		{ 3, 1, 3 },
		{ 4, 1, 4 },
		{ 4, 1, 5 },
		{ 4, 1, 6 },
		{ 4, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 5, 1, 12 },
		{ 5, 1, 13 },
		{ 5, 1, 14 },
		{ 6, 3, 15 },
		{ 6, 1, -1 },
		{ 7, 3, 16 },
		{ 8, 5, 17 },
		{ 8, 7, 18 },
		{ 9, 9, 19 },
		{ 9, 8, 20 },
		{ 9, 8, 21 },
		{ 9, 8, 22 },
		{ 9, 7, 23 },
		{ 9, 7, 24 },
		{ 9, 7, 25 },
		{ 9, 6, 26 },
		{ 10, 5, 27 },
		{ 11, 2, 28 },
		{ 11, 1, -1 },
		{ 12, 3, 29 },
		{ 12, 1, 30 },
		{ 13, 3, 31 },
		{ 13, 1, 32 },
		{ 14, 3, 33 },
		{ 14, 1, 34 },
		{ 15, 3, 35 },
		{ 15, 3, 36 },
		{ 15, 3, 37 },
		{ 15, 3, 38 },
		{ 15, 3, 39 },
		{ 15, 3, 40 },
		{ 15, 1, 41 },
		{ 16, 3, 42 },
		{ 16, 3, 43 },
		{ 16, 3, 44 },
		{ 16, 3, 45 },
		{ 16, 3, 46 },
		{ 16, 2, 47 },
		{ 16, 2, 48 },
		{ 16, 1, 49 },
		{ 17, 3, 50 },
		{ 17, 1, 51 },
		{ 17, 1, 52 },
		{ 17, 2, 53 },
		{ 18, 5, 54 },
		{ 19, 5, 55 }
	};
	yyreduction = reduction;

	yytokenaction_size = 133;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 30, YYAT_SHIFT, 7 },
		{ 111, YYAT_SHIFT, 118 },
		{ 30, YYAT_SHIFT, 8 },
		{ 30, YYAT_SHIFT, 9 },
		{ 30, YYAT_SHIFT, 10 },
		{ 30, YYAT_SHIFT, 11 },
		{ 30, YYAT_SHIFT, 12 },
		{ 30, YYAT_SHIFT, 13 },
		{ 30, YYAT_SHIFT, 14 },
		{ 124, YYAT_SHIFT, 7 },
		{ 109, YYAT_SHIFT, 116 },
		{ 124, YYAT_SHIFT, 8 },
		{ 124, YYAT_SHIFT, 9 },
		{ 124, YYAT_SHIFT, 10 },
		{ 124, YYAT_SHIFT, 11 },
		{ 124, YYAT_SHIFT, 12 },
		{ 112, YYAT_SHIFT, 13 },
		{ 112, YYAT_SHIFT, 14 },
		{ 86, YYAT_SHIFT, 51 },
		{ 86, YYAT_SHIFT, 52 },
		{ 86, YYAT_SHIFT, 53 },
		{ 86, YYAT_SHIFT, 54 },
		{ 86, YYAT_SHIFT, 55 },
		{ 86, YYAT_SHIFT, 56 },
		{ 86, YYAT_SHIFT, 57 },
		{ 30, YYAT_SHIFT, 15 },
		{ 30, YYAT_SHIFT, 16 },
		{ 101, YYAT_SHIFT, 48 },
		{ 30, YYAT_SHIFT, 17 },
		{ 120, YYAT_SHIFT, 48 },
		{ 30, YYAT_SHIFT, 5 },
		{ 101, YYAT_SHIFT, 112 },
		{ 30, YYAT_SHIFT, 18 },
		{ 30, YYAT_SHIFT, 19 },
		{ 112, YYAT_SHIFT, 15 },
		{ 124, YYAT_SHIFT, 16 },
		{ 120, YYAT_SHIFT, 124 },
		{ 112, YYAT_SHIFT, 17 },
		{ 112, YYAT_SHIFT, 119 },
		{ 124, YYAT_SHIFT, 5 },
		{ 100, YYAT_SHIFT, 110 },
		{ 124, YYAT_SHIFT, 18 },
		{ 124, YYAT_SHIFT, 19 },
		{ 85, YYAT_SHIFT, 51 },
		{ 85, YYAT_SHIFT, 52 },
		{ 85, YYAT_SHIFT, 53 },
		{ 85, YYAT_SHIFT, 54 },
		{ 85, YYAT_SHIFT, 55 },
		{ 85, YYAT_SHIFT, 56 },
		{ 85, YYAT_SHIFT, 57 },
		{ 84, YYAT_SHIFT, 51 },
		{ 84, YYAT_SHIFT, 52 },
		{ 84, YYAT_SHIFT, 53 },
		{ 84, YYAT_SHIFT, 54 },
		{ 84, YYAT_SHIFT, 55 },
		{ 84, YYAT_SHIFT, 56 },
		{ 84, YYAT_SHIFT, 57 },
		{ 83, YYAT_SHIFT, 51 },
		{ 83, YYAT_SHIFT, 52 },
		{ 83, YYAT_SHIFT, 53 },
		{ 83, YYAT_SHIFT, 54 },
		{ 83, YYAT_SHIFT, 55 },
		{ 83, YYAT_SHIFT, 56 },
		{ 83, YYAT_SHIFT, 57 },
		{ 82, YYAT_SHIFT, 51 },
		{ 82, YYAT_SHIFT, 52 },
		{ 82, YYAT_SHIFT, 53 },
		{ 82, YYAT_SHIFT, 54 },
		{ 82, YYAT_SHIFT, 55 },
		{ 82, YYAT_SHIFT, 56 },
		{ 82, YYAT_SHIFT, 57 },
		{ 81, YYAT_SHIFT, 51 },
		{ 81, YYAT_SHIFT, 52 },
		{ 81, YYAT_SHIFT, 53 },
		{ 81, YYAT_SHIFT, 54 },
		{ 81, YYAT_SHIFT, 55 },
		{ 81, YYAT_SHIFT, 56 },
		{ 81, YYAT_SHIFT, 57 },
		{ 34, YYAT_SHIFT, 51 },
		{ 34, YYAT_SHIFT, 52 },
		{ 34, YYAT_SHIFT, 53 },
		{ 34, YYAT_SHIFT, 54 },
		{ 34, YYAT_SHIFT, 55 },
		{ 34, YYAT_SHIFT, 56 },
		{ 34, YYAT_SHIFT, 57 },
		{ 87, YYAT_SHIFT, 58 },
		{ 87, YYAT_SHIFT, 59 },
		{ 87, YYAT_SHIFT, 60 },
		{ 87, YYAT_SHIFT, 61 },
		{ 87, YYAT_SHIFT, 62 },
		{ 87, YYAT_SHIFT, 63 },
		{ 35, YYAT_SHIFT, 58 },
		{ 35, YYAT_SHIFT, 59 },
		{ 35, YYAT_SHIFT, 60 },
		{ 35, YYAT_SHIFT, 61 },
		{ 35, YYAT_SHIFT, 62 },
		{ 35, YYAT_SHIFT, 63 },
		{ 46, YYAT_SHIFT, 48 },
		{ 99, YYAT_SHIFT, 108 },
		{ 98, YYAT_SHIFT, 107 },
		{ 96, YYAT_SHIFT, 105 },
		{ 94, YYAT_SHIFT, 104 },
		{ 46, YYAT_SHIFT, 73 },
		{ 93, YYAT_SHIFT, 103 },
		{ 91, YYAT_SHIFT, 100 },
		{ 90, YYAT_SHIFT, 99 },
		{ 89, YYAT_SHIFT, 97 },
		{ 75, YYAT_SHIFT, 64 },
		{ 74, YYAT_SHIFT, 48 },
		{ 73, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 94 },
		{ 70, YYAT_SHIFT, 93 },
		{ 68, YYAT_SHIFT, 92 },
		{ 67, YYAT_SHIFT, 91 },
		{ 66, YYAT_SHIFT, 89 },
		{ 65, YYAT_SHIFT, 88 },
		{ 45, YYAT_SHIFT, 72 },
		{ 41, YYAT_SHIFT, 69 },
		{ 38, YYAT_SHIFT, 66 },
		{ 36, YYAT_SHIFT, 64 },
		{ 33, YYAT_SHIFT, 50 },
		{ 31, YYAT_SHIFT, 49 },
		{ 24, YYAT_SHIFT, 44 },
		{ 19, YYAT_SHIFT, 43 },
		{ 18, YYAT_SHIFT, 42 },
		{ 9, YYAT_SHIFT, 39 },
		{ 8, YYAT_SHIFT, 38 },
		{ 7, YYAT_SHIFT, 37 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -126, 1, YYAT_ERROR, 0 },
		{ -154, 1, YYAT_ERROR, 0 },
		{ 130, 1, YYAT_ERROR, 0 },
		{ -157, 1, YYAT_ERROR, 0 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -158, 1, YYAT_ERROR, 0 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ -160, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ -161, 1, YYAT_ERROR, 0 },
		{ -162, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -166, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ -257, 1, YYAT_REDUCE, 4 },
		{ -162, 1, YYAT_DEFAULT, 101 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ -161, 1, YYAT_REDUCE, 33 },
		{ -188, 1, YYAT_REDUCE, 44 },
		{ -182, 1, YYAT_REDUCE, 37 },
		{ -161, 1, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ -165, 1, YYAT_DEFAULT, 91 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ -169, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -167, 1, YYAT_ERROR, 0 },
		{ -182, 1, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 73 },
		{ -171, 1, YYAT_DEFAULT, 120 },
		{ -169, 1, YYAT_DEFAULT, 91 },
		{ -170, 1, YYAT_DEFAULT, 101 },
		{ -174, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ -175, 1, YYAT_DEFAULT, 120 },
		{ -176, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ -177, 1, YYAT_DEFAULT, 112 },
		{ -171, 1, YYAT_REDUCE, 32 },
		{ -173, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -195, 1, YYAT_REDUCE, 41 },
		{ -202, 1, YYAT_REDUCE, 39 },
		{ -209, 1, YYAT_REDUCE, 42 },
		{ -216, 1, YYAT_REDUCE, 40 },
		{ -223, 1, YYAT_REDUCE, 38 },
		{ -248, 1, YYAT_REDUCE, 43 },
		{ -188, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -180, 1, YYAT_DEFAULT, 112 },
		{ -178, 1, YYAT_DEFAULT, 101 },
		{ -179, 1, YYAT_DEFAULT, 73 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -180, 1, YYAT_ERROR, 0 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -191, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -187, 1, YYAT_DEFAULT, 120 },
		{ -188, 1, YYAT_DEFAULT, 112 },
		{ -246, 1, YYAT_DEFAULT, 112 },
		{ -252, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -276, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -285, 1, YYAT_DEFAULT, 120 },
		{ -248, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -250, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -248, 1, YYAT_DEFAULT, 91 },
		{ 0, 0, YYAT_REDUCE, 21 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 61;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 124, 20 },
		{ 119, 123 },
		{ 124, 125 },
		{ 124, 29 },
		{ 118, 122 },
		{ 124, 27 },
		{ 124, 22 },
		{ 124, 28 },
		{ 124, 25 },
		{ 124, 23 },
		{ 124, 31 },
		{ 116, 121 },
		{ 73, 95 },
		{ 112, 120 },
		{ 112, 33 },
		{ 112, 36 },
		{ 124, 21 },
		{ 124, 26 },
		{ 73, 46 },
		{ 64, 87 },
		{ 64, 34 },
		{ 63, 86 },
		{ 63, 32 },
		{ 50, 75 },
		{ 50, 35 },
		{ 30, 47 },
		{ 30, 30 },
		{ 110, 117 },
		{ 108, 115 },
		{ 107, 114 },
		{ 105, 113 },
		{ 100, 111 },
		{ 99, 109 },
		{ 97, 106 },
		{ 92, 102 },
		{ 91, 101 },
		{ 89, 98 },
		{ 88, 96 },
		{ 66, 90 },
		{ 62, 85 },
		{ 61, 84 },
		{ 60, 83 },
		{ 59, 82 },
		{ 58, 81 },
		{ 55, 80 },
		{ 54, 79 },
		{ 53, 78 },
		{ 52, 77 },
		{ 51, 76 },
		{ 48, 74 },
		{ 43, 71 },
		{ 42, 70 },
		{ 39, 68 },
		{ 38, 67 },
		{ 37, 65 },
		{ 29, 45 },
		{ 17, 41 },
		{ 15, 40 },
		{ 5, 24 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 59, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, -1 },
		{ 55, 30 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, -1 },
		{ 0, -1 },
		{ 44, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 73 },
		{ 22, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 42, 112 },
		{ 41, 112 },
		{ 40, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 112 },
		{ 38, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 112 },
		{ 0, -1 },
		{ 9, 64 },
		{ 31, -1 },
		{ 30, -1 },
		{ 29, -1 },
		{ 28, -1 },
		{ 27, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 27, 63 },
		{ 26, 63 },
		{ 25, 63 },
		{ 24, 63 },
		{ 23, 63 },
		{ 5, -1 },
		{ 4, 63 },
		{ 0, -1 },
		{ 26, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 124 },
		{ 24, 112 },
		{ 0, -1 },
		{ 23, 112 },
		{ 30, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 124 },
		{ 0, -1 },
		{ 20, 112 },
		{ 19, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 124 },
		{ 0, -1 },
		{ 25, 124 },
		{ 24, 124 },
		{ 0, -1 },
		{ 23, 124 },
		{ 0, -1 },
		{ 1, 50 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 124 },
		{ 0, -1 },
		{ 0, 124 },
		{ -3, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 112 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 512 ".\\myparser.y"


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
