
# line 2 "m4y_xpg4.y"
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

# line 34 "m4y_xpg4.y"
/*	from OpenSolaris "m4y_xpg4.y	1.4	05/06/10 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)m4y_xpg4.y	1.4 (gritter) 11/27/05
 */
#include <inttypes.h>
extern int32_t	evalval;
#define	YYSTYPE	int32_t
#include "m4.h"
# define DIGITS 257
# define OROR 258
# define ANDAND 259
# define EQ 260
# define NE 261
# define LE 262
# define GE 263
# define LT 264
# define GT 265
# define LSHIFT 266
# define RSHIFT 267
# define POWER 268
# define UMINUS 269

#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#define	YYCONST	const
#else
#include <malloc.h>
#include <memory.h>
#define	YYCONST
#endif

#if defined(__cplusplus) || defined(__STDC__)

#if defined(__cplusplus) && defined(__EXTERN_C__)
extern "C" {
#endif
#ifndef yyerror
#if defined(__cplusplus)
	void yyerror(YYCONST char *);
#endif
#endif
#ifndef yylex
	int yylex(void);
#endif
	int yyparse(void);
#if defined(__cplusplus) && defined(__EXTERN_C__)
}
#endif

#endif

#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256

# line 93 "m4y_xpg4.y"


extern wchar_t *pe;

static int peek(char c, int r1, int r2);
static int peek3(char c1, int rc1, char c2, int rc2, int rc3);

int
yylex(void) {
	while (*pe == ' ' || *pe == '\t' || *pe == '\n')
		pe++;
	switch (*pe) {
	case '\0':
	case '+':
	case '-':
	case '/':
	case '%':
	case '^':
	case '~':
	case '(':
	case ')':
		return (*pe++);
	case '*':
		return (peek('*', POWER, '*'));
	case '>':
		return (peek3('=', GE, '>', RSHIFT, GT));
	case '<':
		return (peek3('=', LE, '<', LSHIFT, LT));
	case '=':
		return (peek('=', EQ, EQ));
	case '|':
		return (peek('|', OROR, '|'));
	case '&':
		return (peek('&', ANDAND, '&'));
	case '!':
		return (peek('=', NE, '!'));
	default: {
		register int32_t	base;

		evalval = 0;

		if (*pe == '0') {
			if (*++pe == 'x' || *pe == 'X') {
				base = 16;
				++pe;
			} else
				base = 8;
		} else
			base = 10;

		for (;;) {
			register int32_t	c, dig;

			c = *pe;

			if (is_digit(c))
				dig = c - '0';
			else if (c >= 'a' && c <= 'f')
				dig = c - 'a' + 10;
			else if (c >= 'A' && c <= 'F')
				dig = c - 'A' + 10;
			else
				break;

			evalval = evalval*base + dig;
			++pe;
		}
		return (DIGITS);
	}
	}
}

static int
peek(char c, int r1, int r2)
{
	if (*++pe != c)
		return (r2);
	++pe;
	return (r1);
}

static int
peek3(char c1, int rc1, char c2, int rc2, int rc3)
{
	++pe;
	if (*pe == c1) {
		++pe;
		return (rc1);
	}
	if (*pe == c2) {
		++pe;
		return (rc2);
	}
	return (rc3);
}

/*ARGSUSED*/
void
yyerror(const char *msg)
{
	;
}
static YYCONST yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 35,
	260, 0,
	261, 0,
	-2, 7,
-1, 36,
	260, 0,
	261, 0,
	-2, 8,
-1, 37,
	262, 0,
	263, 0,
	264, 0,
	265, 0,
	-2, 9,
-1, 38,
	262, 0,
	263, 0,
	264, 0,
	265, 0,
	-2, 10,
-1, 39,
	262, 0,
	263, 0,
	264, 0,
	265, 0,
	-2, 11,
-1, 40,
	262, 0,
	263, 0,
	264, 0,
	265, 0,
	-2, 12,
	};
# define YYNPROD 28
# define YYLAST 331
static YYCONST yytabelem yyact[]={

    26,    20,    27,     1,    52,    24,    22,     0,    23,     0,
    25,    26,    20,     0,     0,     0,    24,    22,     0,    23,
     0,    25,    26,    20,     0,     0,     0,    24,    22,     0,
    23,     0,    25,    26,    20,     0,     0,     0,    24,    22,
     0,    23,     0,    25,    26,    20,     0,     0,     0,    24,
    22,     0,    23,     0,    25,    26,    20,    21,     0,     0,
    24,    22,     0,    23,    26,    25,    26,     0,    21,    24,
    22,    24,    23,     0,    25,    26,    25,     0,     0,    21,
    24,    22,     0,    23,     0,    25,    26,    19,     0,     0,
    21,    24,    22,     0,    23,     0,    25,    26,    19,     0,
     0,    21,    24,    22,     0,    23,     3,    25,     0,    19,
     0,     0,     0,     5,     0,     0,     7,     2,     6,     0,
    19,    28,    29,    30,    31,    32,     0,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     9,    10,    11,    12,    16,    14,    15,    13,    17,
    18,    27,     9,    10,    11,    12,    16,    14,    15,    13,
    17,    18,    27,     0,    10,    11,    12,    16,    14,    15,
    13,    17,    18,    27,     0,     0,    11,    12,    16,    14,
    15,    13,    17,    18,    27,     0,     0,    11,    12,    16,
    14,    15,    13,    17,    18,    27,     0,     0,    11,    12,
    16,    14,    15,    13,    17,    18,    27,    11,    12,    16,
    14,    15,    13,    17,    18,    27,     0,    27,     0,     0,
    16,    14,    15,    13,    17,    18,    27,     0,     0,     0,
     0,     0,     0,     0,     0,    17,    18,    27,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
     8 };
static YYCONST yytabelem yypact[]={

    73,-10000000,   -26,    73,    73,    73,    73,    73,-10000000,    73,
    73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
    73,    73,    73,    73,    73,    73,    73,    73,-10000000,-10000000,
   -37,-10000000,-10000000,   -15,    -4,    38,    38,    49,    49,    49,
    49,    60,    60,     7,    27,    18,    29,    29,  -266,  -266,
  -266,  -266,-10000000 };
static YYCONST yytabelem yypgo[]={

     0,     3,   117 };
static YYCONST yytabelem yyr1[]={

     0,     1,     1,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2 };
static YYCONST yytabelem yyr2[]={

     0,     3,     1,     7,     7,     5,     5,     7,     7,     7,
     7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     7,     7,     7,     7,     7,     5,     5,     3 };
static YYCONST yytabelem yychk[]={

-10000000,    -1,    -2,    33,   126,    40,    45,    43,   257,   258,
   259,   260,   261,   265,   263,   264,   262,   266,   267,   124,
    38,    94,    43,    45,    42,    47,    37,   268,    -2,    -2,
    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
    -2,    -2,    41 };
static YYCONST yytabelem yydef[]={

     2,    -2,     1,     0,     0,     0,     0,     0,    27,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
     0,    25,    26,     3,     4,    -2,    -2,    -2,    -2,    -2,
    -2,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    24,    23 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{
#ifdef __cplusplus
const
#endif
char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"DIGITS",	257,
	"OROR",	258,
	"ANDAND",	259,
	"|",	124,
	"^",	94,
	"&",	38,
	"EQ",	260,
	"NE",	261,
	"LE",	262,
	"GE",	263,
	"LT",	264,
	"GT",	265,
	"LSHIFT",	266,
	"RSHIFT",	267,
	"+",	43,
	"-",	45,
	"*",	42,
	"/",	47,
	"%",	37,
	"POWER",	268,
	"!",	33,
	"~",	126,
	"UMINUS",	269,
	"-unknown-",	-1	/* ends search */
};

#ifdef __cplusplus
const
#endif
char * yyreds[] =
{
	"-no such reduction-",
	"s : e",
	"s : /* empty */",
	"e : e OROR e",
	"e : e ANDAND e",
	"e : '!' e",
	"e : '~' e",
	"e : e EQ e",
	"e : e NE e",
	"e : e GT e",
	"e : e GE e",
	"e : e LT e",
	"e : e LE e",
	"e : e LSHIFT e",
	"e : e RSHIFT e",
	"e : e '|' e",
	"e : e '&' e",
	"e : e '^' e",
	"e : e '+' e",
	"e : e '-' e",
	"e : e '*' e",
	"e : e '/' e",
	"e : e '%' e",
	"e : '(' e ')'",
	"e : e POWER e",
	"e : '-' e",
	"e : '+' e",
	"e : DIGITS",
};
#endif /* YYDEBUG */
# line	1 "../yacc/yaccpar"
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/* Copyright (c) 1988 AT&T */
/* All Rights Reserved */

/*	from OpenSolaris "yaccpar	6.18	05/06/08 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)yaccpar	1.5 (gritter) 11/26/05
 */

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yymaxdepth * sizeof (type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither 
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/ 
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt = 0;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint) || defined(__GNUC__)
/*
	hacks to please C++, lint, and gcc - goto's inside
	switch should never be executed
*/
	static int _yaccpar_lint_hack = -1;
	switch (_yaccpar_lint_hack)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			long yyps_index = (yy_ps - yys);
			long yypv_index = (yy_pv - yyv);
			long yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register YYCONST int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 1:
# line 62 "m4y_xpg4.y"
{ evalval = yypvt[-0]; } break;
case 2:
# line 63 "m4y_xpg4.y"
{ evalval = 0; } break;
case 3:
# line 66 "m4y_xpg4.y"
{ yyval = (yypvt[-2] != 0 || yypvt[-0] != 0) ? 1 : 0; } break;
case 4:
# line 67 "m4y_xpg4.y"
{ yyval = (yypvt[-2] != 0 && yypvt[-0] != 0) ? 1 : 0; } break;
case 5:
# line 68 "m4y_xpg4.y"
{ yyval = yypvt[-0] == 0; } break;
case 6:
# line 69 "m4y_xpg4.y"
{ yyval = ~yypvt[-0]; } break;
case 7:
# line 70 "m4y_xpg4.y"
{ yyval = yypvt[-2] == yypvt[-0]; } break;
case 8:
# line 71 "m4y_xpg4.y"
{ yyval = yypvt[-2] != yypvt[-0]; } break;
case 9:
# line 72 "m4y_xpg4.y"
{ yyval = yypvt[-2] > yypvt[-0]; } break;
case 10:
# line 73 "m4y_xpg4.y"
{ yyval = yypvt[-2] >= yypvt[-0]; } break;
case 11:
# line 74 "m4y_xpg4.y"
{ yyval = yypvt[-2] < yypvt[-0]; } break;
case 12:
# line 75 "m4y_xpg4.y"
{ yyval = yypvt[-2] <= yypvt[-0]; } break;
case 13:
# line 76 "m4y_xpg4.y"
{ yyval = yypvt[-2] << yypvt[-0]; } break;
case 14:
# line 77 "m4y_xpg4.y"
{ yyval = yypvt[-2] >> yypvt[-0]; } break;
case 15:
# line 78 "m4y_xpg4.y"
{ yyval = (yypvt[-2] | yypvt[-0]); } break;
case 16:
# line 79 "m4y_xpg4.y"
{ yyval = (yypvt[-2] & yypvt[-0]); } break;
case 17:
# line 80 "m4y_xpg4.y"
{ yyval = (yypvt[-2] ^ yypvt[-0]); } break;
case 18:
# line 81 "m4y_xpg4.y"
{ yyval = (yypvt[-2] + yypvt[-0]); } break;
case 19:
# line 82 "m4y_xpg4.y"
{ yyval = (yypvt[-2] - yypvt[-0]); } break;
case 20:
# line 83 "m4y_xpg4.y"
{ yyval = (yypvt[-2] * yypvt[-0]); } break;
case 21:
# line 84 "m4y_xpg4.y"
{ yyval = (yypvt[-2] / yypvt[-0]); } break;
case 22:
# line 85 "m4y_xpg4.y"
{ yyval = (yypvt[-2] % yypvt[-0]); } break;
case 23:
# line 86 "m4y_xpg4.y"
{ yyval = (yypvt[-1]); } break;
case 24:
# line 87 "m4y_xpg4.y"
{ for (yyval = 1; yypvt[-0]-- > 0; yyval *= yypvt[-2]); } break;
case 25:
# line 88 "m4y_xpg4.y"
{ yyval = yypvt[-0]-1; yyval = -yypvt[-0]; } break;
case 26:
# line 89 "m4y_xpg4.y"
{ yyval = yypvt[-0]-1; yyval = yypvt[-0]; } break;
case 27:
# line 90 "m4y_xpg4.y"
{ yyval = evalval; } break;
# line	562 "../yacc/yaccpar"
	}
	goto yystack;		/* reset registers in driver code */
}

