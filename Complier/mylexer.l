%{
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <malloc.h>
#include <stdlib.h>

#include "myparser.h"

enum {StmtK,ExpK,DeclK};
enum {IfK,WhileK,AssignK,ForK,CompK, InputK, PrintK};
enum {OpK,ConstK,IdK,TypeK};
enum {VarK};
enum {Void,Integer,Char};

#define MAXCHILDREN 4
char *Id=new char[10];
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
     int type;/* for type checking of exps */ 
   } ;
int getid(char *text,int leng);
int compute(char* str,int len);
int getNUM(char *text,int leng);
char hash1[1000][10];
extern YYSTYPE yylval;
extern int line;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

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

// place any declarations here
digit		[0-9]
num			{digit}+
newline     [\n]+
letter		[_A-Za-z]
identifier	{letter}({letter}|{digit})*
WS			[ \t\n]*


%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
"if"			{return IF;}
"else"			{return ELSE;}
"for"			{return FOR;}
"while"			{return WHILE;}
"void"			{return VOID;}
"int"			{return INT;}
"char"			{return CHAR;}
"input"         {return INPUT;}
"print"         {return PRINT;}
"main"			{return MAIN;}
"+"				{return PLUS;}	
"-"				{return MINUS;}
"*"				{return TIMES;}
"/"				{return OVER;}
"%"				{return REMI;}
"++"			{return DPLUS;}
"--"			{return DMINUS;}
">="			{return GE;}
"<="			{return LE;}
">"				{return GT;}
"<"				{return	LT;}
"!="			{return NEQ;}
"&&"            {return AND;}
"||"            {return OR;}
"!"             {return NOT;}
"=="			{return EQ;}
"="				{return ASSIGN;}
","				{return COMMA;}
";"				{return SEMI;}		
"("				{return LP;} 
")"				{return RP;} 
"{"		        {return LFP;} 
"}"			    {return RFP;}
{WS}			{/*do nothing*/}

{identifier}	{	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    t->attr.name=hash1[getid(yytext,yyleng)];
					yylval = t;
					return ID;
									}
				
{num}			{	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//number节点
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Void;
			        t->attr.val=getNUM(yytext,yyleng);	
			        yylval =t;	
					return NUM;
				}
%%

/////////////////////////////////////////////////////////////////////////////
// programs section
int getid(char *text,int leng)
{
    int i=0;
    for(i;i<leng;i++)
    {
        Id[i]=*text;
        text++;
    }
    Id[i]='\0';
    int index =compute(Id,leng)%1000;
    if(hash1[index][0]=='\0')
    {
        strcpy(hash1[index],Id);
    }
    else{
        while(hash1[index][0]!='\0'&&strcmp(Id,hash1[index])!=0)
          {
            index++;
          }
        }
    return index;
}
int compute(char* str,int len)
{
    int hash = 0;  
    for (int i=0;str[i]!='\0';i++)
    {
        hash=hash+str[i]-'a';
    }
    return hash;  
}

int getNUM(char *text,int leng){
    int value=0;
    for(int i=0;i<leng;i++)
    {
        value=value*10+*text-'0';
        text++;
    }
    return value;
}