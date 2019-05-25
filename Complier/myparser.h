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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 01/12/19
* Time: 18:55:15
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 119 ".\\myparser.y"

	// place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 134 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif

#line 82 "myparser.h"
#define IF 257
#define MAIN 258
#define FOR 259
#define WHILE 260
#define INT 261
#define CHAR 262
#define VOID 263
#define ID 264
#define NUM 265
#define PLUS 266
#define MINUS 267
#define TIMES 268
#define OVER 269
#define REMI 270
#define DPLUS 271
#define DMINUS 272
#define LT 273
#define LE 274
#define GT 275
#define GE 276
#define EQ 277
#define NEQ 278
#define ASSIGN 279
#define AND 280
#define OR 281
#define NOT 282
#define SEMI 283
#define COMMA 284
#define LP 285
#define RP 286
#define LFP 287
#define RFP 288
#define INPUT 289
#define PRINT 290
#define ELSE 291
#endif
