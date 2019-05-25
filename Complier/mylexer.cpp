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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 01/12/19
* Time: 17:49:02
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

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

#line 77 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 52 ".\\mylexer.l"

	// place any extra initialisation code here

#line 101 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 57 ".\\mylexer.l"

	// place any extra cleanup code here

#line 113 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 75 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 184 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 81 ".\\mylexer.l"
return IF;
#line 191 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 82 ".\\mylexer.l"
return ELSE;
#line 198 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 83 ".\\mylexer.l"
return FOR;
#line 205 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 84 ".\\mylexer.l"
return WHILE;
#line 212 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 85 ".\\mylexer.l"
return VOID;
#line 219 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 86 ".\\mylexer.l"
return INT;
#line 226 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 87 ".\\mylexer.l"
return CHAR;
#line 233 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 88 ".\\mylexer.l"
return INPUT;
#line 240 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 89 ".\\mylexer.l"
return PRINT;
#line 247 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 90 ".\\mylexer.l"
return MAIN;
#line 254 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 91 ".\\mylexer.l"
return PLUS;
#line 261 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 92 ".\\mylexer.l"
return MINUS;
#line 268 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 93 ".\\mylexer.l"
return TIMES;
#line 275 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 94 ".\\mylexer.l"
return OVER;
#line 282 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 95 ".\\mylexer.l"
return REMI;
#line 289 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 96 ".\\mylexer.l"
return DPLUS;
#line 296 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 97 ".\\mylexer.l"
return DMINUS;
#line 303 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 98 ".\\mylexer.l"
return GE;
#line 310 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 99 ".\\mylexer.l"
return LE;
#line 317 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 100 ".\\mylexer.l"
return GT;
#line 324 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 101 ".\\mylexer.l"
return	LT;
#line 331 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 102 ".\\mylexer.l"
return NEQ;
#line 338 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 103 ".\\mylexer.l"
return AND;
#line 345 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 104 ".\\mylexer.l"
return OR;
#line 352 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 105 ".\\mylexer.l"
return NOT;
#line 359 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 106 ".\\mylexer.l"
return EQ;
#line 366 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 107 ".\\mylexer.l"
return ASSIGN;
#line 373 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 108 ".\\mylexer.l"
return COMMA;
#line 380 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 109 ".\\mylexer.l"
return SEMI;
#line 387 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 110 ".\\mylexer.l"
return LP;
#line 394 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 111 ".\\mylexer.l"
return RP;
#line 401 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 112 ".\\mylexer.l"
return LFP;
#line 408 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 113 ".\\mylexer.l"
return RFP;
#line 415 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 114 ".\\mylexer.l"
/*do nothing*/
#line 422 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 116 ".\\mylexer.l"
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    t->attr.name=hash1[getid(yytext,yyleng)];
					yylval = t;
					return ID;
									
#line 439 "mylexer.cpp"
		}
		break;
#line 127 ".\\mylexer.l"
				
#line 444 "mylexer.cpp"
	case 36:
		{
#line 128 ".\\mylexer.l"
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//number节点
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Void;
			        t->attr.val=getNUM(yytext,yyleng);	
			        yylval =t;	
					return NUM;
				
#line 459 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 193;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 3 },
		{ 3, 3 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 41, 23 },
		{ 51, 42 },
		{ 31, 4 },
		{ 35, 16 },
		{ 36, 17 },
		{ 52, 42 },
		{ 37, 18 },
		{ 38, 20 },
		{ 42, 23 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 39, 21 },
		{ 40, 22 },
		{ 5, 1 },
		{ 6, 1 },
		{ 32, 6 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 43, 24 },
		{ 13, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 44, 25 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 45, 26 },
		{ 46, 27 },
		{ 47, 29 },
		{ 48, 38 },
		{ 49, 39 },
		{ 50, 40 },
		{ 33, 10 },
		{ 53, 43 },
		{ 54, 44 },
		{ 55, 45 },
		{ 56, 46 },
		{ 57, 48 },
		{ 58, 49 },
		{ 59, 51 },
		{ 60, 53 },
		{ 61, 54 },
		{ 62, 55 },
		{ 63, 56 },
		{ 64, 59 },
		{ 65, 61 },
		{ 66, 63 },
		{ 34, 12 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 20, 1 },
		{ 0, 0 },
		{ 21, 1 },
		{ 22, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 23, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 24, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 26, 1 },
		{ 27, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 19, 66 },
		{ 0, 0 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 },
		{ 19, 66 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 66, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 34 },
		{ 0, -44, 25 },
		{ 0, 0, 15 },
		{ 0, -7, 0 },
		{ 0, 0, 30 },
		{ 0, 0, 31 },
		{ 0, 0, 13 },
		{ 0, 18, 11 },
		{ 0, 0, 28 },
		{ 0, 31, 12 },
		{ 0, 0, 14 },
		{ 0, -43, 36 },
		{ 0, 0, 29 },
		{ 0, -43, 21 },
		{ 0, -42, 27 },
		{ 0, -40, 20 },
		{ 66, 0, 35 },
		{ 66, -82, 35 },
		{ 66, -81, 35 },
		{ 66, -83, 35 },
		{ 66, -87, 35 },
		{ 66, -59, 35 },
		{ 66, -64, 35 },
		{ 66, -56, 35 },
		{ 66, -48, 35 },
		{ 0, 0, 32 },
		{ 0, -67, 0 },
		{ 0, 0, 33 },
		{ 0, 0, 22 },
		{ 0, 0, 23 },
		{ 0, 0, 16 },
		{ 0, 0, 17 },
		{ 0, 0, 19 },
		{ 0, 0, 26 },
		{ 0, 0, 18 },
		{ 66, -39, 35 },
		{ 66, -56, 35 },
		{ 66, -54, 35 },
		{ 66, 0, 1 },
		{ 66, -96, 35 },
		{ 66, -43, 35 },
		{ 66, -42, 35 },
		{ 66, -41, 35 },
		{ 66, -40, 35 },
		{ 0, 0, 24 },
		{ 66, -48, 35 },
		{ 66, -34, 35 },
		{ 66, 0, 3 },
		{ 66, -49, 35 },
		{ 66, 0, 6 },
		{ 66, -41, 35 },
		{ 66, -40, 35 },
		{ 66, -29, 35 },
		{ 66, -36, 35 },
		{ 66, 0, 7 },
		{ 66, 0, 2 },
		{ 66, -43, 35 },
		{ 66, 0, 10 },
		{ 66, -42, 35 },
		{ 66, 0, 5 },
		{ 66, -26, 35 },
		{ 66, 0, 8 },
		{ 66, 0, 9 },
		{ 0, 70, 4 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 139 ".\\mylexer.l"


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
