#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 82 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 01/12/19
# Time: 18:55:15
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : start $end

    1  start : MAIN LP RP comp_stmt

    2  comp_stmt : LFP stmt_list RFP

    3  stmt_list : stmt stmt_list
    4            | stmt

    5  stmt : var_dec
    6       | exp_stmt
    7       | if_stmt
    8       | for_stmt
    9       | while_stmt
   10       | comp_stmt
   11       | input_stmt
   12       | print_stmt

   13  type_spec : INT
   14            | CHAR
   15            | VOID

   16  id_list : exp COMMA id_list
   17          | exp

   18  var_dec : type_spec id_list SEMI

   19  if_stmt : IF LP exp RP stmt
   20          | IF LP exp RP stmt ELSE stmt

   21  for_stmt : FOR LP exp SEMI exp SEMI exp RP stmt
   22           | FOR LP SEMI exp SEMI exp RP stmt
   23           | FOR LP exp SEMI SEMI exp RP stmt
   24           | FOR LP exp SEMI exp SEMI RP stmt
   25           | FOR LP SEMI SEMI exp RP stmt
   26           | FOR LP SEMI exp SEMI RP stmt
   27           | FOR LP exp SEMI SEMI RP stmt
   28           | FOR LP SEMI SEMI RP stmt

   29  while_stmt : WHILE LP exp RP stmt

   30  exp_stmt : exp SEMI
   31           | SEMI

   32  exp : exp ASSIGN exp
   33      | or_exp

   34  or_exp : or_exp OR and_exp
   35         | and_exp

   36  and_exp : and_exp AND exp_equ
   37          | exp_equ

   38  exp_equ : exp_equ EQ simple_exp
   39          | exp_equ LE simple_exp
   40          | exp_equ GE simple_exp
   41          | exp_equ LT simple_exp
   42          | exp_equ GT simple_exp
   43          | exp_equ NEQ simple_exp
   44          | simple_exp

   45  simple_exp : simple_exp PLUS term
   46             | simple_exp MINUS term
   47             | simple_exp TIMES term
   48             | simple_exp OVER term
   49             | simple_exp REMI term
   50             | simple_exp DPLUS
   51             | simple_exp DMINUS
   52             | term

   53  term : LP exp RP
   54       | ID
   55       | NUM
   56       | NOT term

   57  input_stmt : INPUT LP exp RP SEMI

   58  print_stmt : PRINT LP exp RP SEMI


##############################################################################
# States
##############################################################################

state 0
	$accept : . start $end

	MAIN  shift 1

	start  goto 2


state 1
	start : MAIN . LP RP comp_stmt

	LP  shift 3


state 2
	$accept : start . $end  (0)

	$end  accept


state 3
	start : MAIN LP . RP comp_stmt

	RP  shift 4


state 4
	start : MAIN LP RP . comp_stmt

	LFP  shift 5

	comp_stmt  goto 6


state 5
	comp_stmt : LFP . stmt_list RFP

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	stmt_list  goto 24
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 30
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 6
	start : MAIN LP RP comp_stmt .  (1)

	.  reduce 1


state 7
	if_stmt : IF . LP exp RP stmt ELSE stmt
	if_stmt : IF . LP exp RP stmt

	LP  shift 37


state 8
	for_stmt : FOR . LP SEMI SEMI exp RP stmt
	for_stmt : FOR . LP SEMI exp SEMI exp RP stmt
	for_stmt : FOR . LP SEMI exp SEMI RP stmt
	for_stmt : FOR . LP exp SEMI exp SEMI exp RP stmt
	for_stmt : FOR . LP exp SEMI SEMI exp RP stmt
	for_stmt : FOR . LP exp SEMI exp SEMI RP stmt
	for_stmt : FOR . LP exp SEMI SEMI RP stmt
	for_stmt : FOR . LP SEMI SEMI RP stmt

	LP  shift 38


state 9
	while_stmt : WHILE . LP exp RP stmt

	LP  shift 39


state 10
	type_spec : INT .  (13)

	.  reduce 13


state 11
	type_spec : CHAR .  (14)

	.  reduce 14


state 12
	type_spec : VOID .  (15)

	.  reduce 15


state 13
	term : ID .  (54)

	.  reduce 54


state 14
	term : NUM .  (55)

	.  reduce 55


state 15
	term : NOT . term

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 40


state 16
	exp_stmt : SEMI .  (31)

	.  reduce 31


state 17
	term : LP . exp RP

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	exp  goto 41
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 18
	input_stmt : INPUT . LP exp RP SEMI

	LP  shift 42


state 19
	print_stmt : PRINT . LP exp RP SEMI

	LP  shift 43


state 20
	stmt : comp_stmt .  (10)

	.  reduce 10


state 21
	stmt : input_stmt .  (11)

	.  reduce 11


state 22
	stmt : if_stmt .  (7)

	.  reduce 7


state 23
	stmt : exp_stmt .  (6)

	.  reduce 6


state 24
	comp_stmt : LFP stmt_list . RFP

	RFP  shift 44


state 25
	stmt : while_stmt .  (9)

	.  reduce 9


state 26
	stmt : print_stmt .  (12)

	.  reduce 12


state 27
	stmt : var_dec .  (5)

	.  reduce 5


state 28
	stmt : for_stmt .  (8)

	.  reduce 8


state 29
	var_dec : type_spec . id_list SEMI

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	id_list  goto 45
	exp  goto 46
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 30
	stmt_list : stmt . stmt_list
	stmt_list : stmt .  (4)

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19
	.  reduce 4

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	stmt_list  goto 47
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 30
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 31
	exp_stmt : exp . SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 49


state 32
	simple_exp : term .  (52)

	.  reduce 52


state 33
	or_exp : or_exp . OR and_exp
	exp : or_exp .  (33)

	OR  shift 50
	.  reduce 33


state 34
	exp_equ : simple_exp .  (44)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . TIMES term

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 44


state 35
	exp_equ : exp_equ . LT simple_exp
	exp_equ : exp_equ . NEQ simple_exp
	and_exp : exp_equ .  (37)
	exp_equ : exp_equ . GE simple_exp
	exp_equ : exp_equ . GT simple_exp
	exp_equ : exp_equ . EQ simple_exp
	exp_equ : exp_equ . LE simple_exp

	LT  shift 58
	LE  shift 59
	GT  shift 60
	GE  shift 61
	EQ  shift 62
	NEQ  shift 63
	.  reduce 37


state 36
	or_exp : and_exp .  (35)
	and_exp : and_exp . AND exp_equ

	AND  shift 64
	.  reduce 35


state 37
	if_stmt : IF LP . exp RP stmt ELSE stmt
	if_stmt : IF LP . exp RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	exp  goto 65
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 38
	for_stmt : FOR LP . SEMI SEMI exp RP stmt
	for_stmt : FOR LP . SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP . SEMI exp SEMI RP stmt
	for_stmt : FOR LP . exp SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP . exp SEMI SEMI exp RP stmt
	for_stmt : FOR LP . exp SEMI exp SEMI RP stmt
	for_stmt : FOR LP . exp SEMI SEMI RP stmt
	for_stmt : FOR LP . SEMI SEMI RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 66
	LP  shift 17

	exp  goto 67
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 39
	while_stmt : WHILE LP . exp RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	exp  goto 68
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 40
	term : NOT term .  (56)

	.  reduce 56


state 41
	exp : exp . ASSIGN exp
	term : LP exp . RP

	ASSIGN  shift 48
	RP  shift 69


state 42
	input_stmt : INPUT LP . exp RP SEMI

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	exp  goto 70
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 43
	print_stmt : PRINT LP . exp RP SEMI

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	exp  goto 71
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 44
	comp_stmt : LFP stmt_list RFP .  (2)

	.  reduce 2


state 45
	var_dec : type_spec id_list . SEMI

	SEMI  shift 72


state 46
	id_list : exp .  (17)
	id_list : exp . COMMA id_list
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	COMMA  shift 73
	.  reduce 17


state 47
	stmt_list : stmt stmt_list .  (3)

	.  reduce 3


state 48
	exp : exp ASSIGN . exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	exp  goto 74
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 49
	exp_stmt : exp SEMI .  (30)

	.  reduce 30


state 50
	or_exp : or_exp OR . and_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 75


state 51
	simple_exp : simple_exp PLUS . term

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 76


state 52
	simple_exp : simple_exp MINUS . term

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 77


state 53
	simple_exp : simple_exp TIMES . term

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 78


state 54
	simple_exp : simple_exp OVER . term

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 79


state 55
	simple_exp : simple_exp REMI . term

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 80


state 56
	simple_exp : simple_exp DPLUS .  (50)

	.  reduce 50


state 57
	simple_exp : simple_exp DMINUS .  (51)

	.  reduce 51


state 58
	exp_equ : exp_equ LT . simple_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 81


state 59
	exp_equ : exp_equ LE . simple_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 82


state 60
	exp_equ : exp_equ GT . simple_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 83


state 61
	exp_equ : exp_equ GE . simple_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 84


state 62
	exp_equ : exp_equ EQ . simple_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 85


state 63
	exp_equ : exp_equ NEQ . simple_exp

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 86


state 64
	and_exp : and_exp AND . exp_equ

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	term  goto 32
	simple_exp  goto 34
	exp_equ  goto 87


state 65
	if_stmt : IF LP exp . RP stmt ELSE stmt
	if_stmt : IF LP exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 88


state 66
	for_stmt : FOR LP SEMI . SEMI exp RP stmt
	for_stmt : FOR LP SEMI . exp SEMI exp RP stmt
	for_stmt : FOR LP SEMI . exp SEMI RP stmt
	for_stmt : FOR LP SEMI . SEMI RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 89
	LP  shift 17

	exp  goto 90
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 67
	for_stmt : FOR LP exp . SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP exp . SEMI SEMI exp RP stmt
	for_stmt : FOR LP exp . SEMI exp SEMI RP stmt
	for_stmt : FOR LP exp . SEMI SEMI RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 91


state 68
	while_stmt : WHILE LP exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 92


state 69
	term : LP exp RP .  (53)

	.  reduce 53


state 70
	input_stmt : INPUT LP exp . RP SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 93


state 71
	print_stmt : PRINT LP exp . RP SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 94


state 72
	var_dec : type_spec id_list SEMI .  (18)

	.  reduce 18


state 73
	id_list : exp COMMA . id_list

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17

	id_list  goto 95
	exp  goto 46
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 74
	exp : exp ASSIGN exp .  (32)
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	.  reduce 32


state 75
	and_exp : and_exp . AND exp_equ
	or_exp : or_exp OR and_exp .  (34)

	AND  shift 64
	.  reduce 34


state 76
	simple_exp : simple_exp PLUS term .  (45)

	.  reduce 45


state 77
	simple_exp : simple_exp MINUS term .  (46)

	.  reduce 46


state 78
	simple_exp : simple_exp TIMES term .  (47)

	.  reduce 47


state 79
	simple_exp : simple_exp OVER term .  (48)

	.  reduce 48


state 80
	simple_exp : simple_exp REMI term .  (49)

	.  reduce 49


state 81
	exp_equ : exp_equ LT simple_exp .  (41)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . TIMES term

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 41


state 82
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . TIMES term
	exp_equ : exp_equ LE simple_exp .  (39)

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 39


state 83
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	exp_equ : exp_equ GT simple_exp .  (42)
	simple_exp : simple_exp . TIMES term

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 42


state 84
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	exp_equ : exp_equ GE simple_exp .  (40)
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . TIMES term

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 40


state 85
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . TIMES term
	exp_equ : exp_equ EQ simple_exp .  (38)

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 38


state 86
	exp_equ : exp_equ NEQ simple_exp .  (43)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . TIMES term

	PLUS  shift 51
	MINUS  shift 52
	TIMES  shift 53
	OVER  shift 54
	REMI  shift 55
	DPLUS  shift 56
	DMINUS  shift 57
	.  reduce 43


state 87
	and_exp : and_exp AND exp_equ .  (36)
	exp_equ : exp_equ . LT simple_exp
	exp_equ : exp_equ . NEQ simple_exp
	exp_equ : exp_equ . GE simple_exp
	exp_equ : exp_equ . GT simple_exp
	exp_equ : exp_equ . EQ simple_exp
	exp_equ : exp_equ . LE simple_exp

	LT  shift 58
	LE  shift 59
	GT  shift 60
	GE  shift 61
	EQ  shift 62
	NEQ  shift 63
	.  reduce 36


state 88
	if_stmt : IF LP exp RP . stmt ELSE stmt
	if_stmt : IF LP exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 96
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 89
	for_stmt : FOR LP SEMI SEMI . exp RP stmt
	for_stmt : FOR LP SEMI SEMI . RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17
	RP  shift 97

	exp  goto 98
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 90
	for_stmt : FOR LP SEMI exp . SEMI exp RP stmt
	for_stmt : FOR LP SEMI exp . SEMI RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 99


state 91
	for_stmt : FOR LP exp SEMI . exp SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI . SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI . exp SEMI RP stmt
	for_stmt : FOR LP exp SEMI . SEMI RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 100
	LP  shift 17

	exp  goto 101
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 92
	while_stmt : WHILE LP exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 102
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 93
	input_stmt : INPUT LP exp RP . SEMI

	SEMI  shift 103


state 94
	print_stmt : PRINT LP exp RP . SEMI

	SEMI  shift 104


state 95
	id_list : exp COMMA id_list .  (16)

	.  reduce 16


state 96
	if_stmt : IF LP exp RP stmt . ELSE stmt
	if_stmt : IF LP exp RP stmt .  (19)

	ELSE  shift 105
	.  reduce 19


state 97
	for_stmt : FOR LP SEMI SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 106
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 98
	for_stmt : FOR LP SEMI SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 107


state 99
	for_stmt : FOR LP SEMI exp SEMI . exp RP stmt
	for_stmt : FOR LP SEMI exp SEMI . RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17
	RP  shift 108

	exp  goto 109
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 100
	for_stmt : FOR LP exp SEMI SEMI . exp RP stmt
	for_stmt : FOR LP exp SEMI SEMI . RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17
	RP  shift 110

	exp  goto 111
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 101
	for_stmt : FOR LP exp SEMI exp . SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI exp . SEMI RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 112


state 102
	while_stmt : WHILE LP exp RP stmt .  (29)

	.  reduce 29


state 103
	input_stmt : INPUT LP exp RP SEMI .  (57)

	.  reduce 57


state 104
	print_stmt : PRINT LP exp RP SEMI .  (58)

	.  reduce 58


state 105
	if_stmt : IF LP exp RP stmt ELSE . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 113
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 106
	for_stmt : FOR LP SEMI SEMI RP stmt .  (28)

	.  reduce 28


state 107
	for_stmt : FOR LP SEMI SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 114
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 108
	for_stmt : FOR LP SEMI exp SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 115
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 109
	for_stmt : FOR LP SEMI exp SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 116


state 110
	for_stmt : FOR LP exp SEMI SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 117
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 111
	for_stmt : FOR LP exp SEMI SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 118


state 112
	for_stmt : FOR LP exp SEMI exp SEMI . exp RP stmt
	for_stmt : FOR LP exp SEMI exp SEMI . RP stmt

	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	LP  shift 17
	RP  shift 119

	exp  goto 120
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 113
	if_stmt : IF LP exp RP stmt ELSE stmt .  (20)

	.  reduce 20


state 114
	for_stmt : FOR LP SEMI SEMI exp RP stmt .  (25)

	.  reduce 25


state 115
	for_stmt : FOR LP SEMI exp SEMI RP stmt .  (26)

	.  reduce 26


state 116
	for_stmt : FOR LP SEMI exp SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 121
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 117
	for_stmt : FOR LP exp SEMI SEMI RP stmt .  (27)

	.  reduce 27


state 118
	for_stmt : FOR LP exp SEMI SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 122
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 119
	for_stmt : FOR LP exp SEMI exp SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 123
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 120
	for_stmt : FOR LP exp SEMI exp SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 124


state 121
	for_stmt : FOR LP SEMI exp SEMI exp RP stmt .  (22)

	.  reduce 22


state 122
	for_stmt : FOR LP exp SEMI SEMI exp RP stmt .  (23)

	.  reduce 23


state 123
	for_stmt : FOR LP exp SEMI exp SEMI RP stmt .  (24)

	.  reduce 24


state 124
	for_stmt : FOR LP exp SEMI exp SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INT  shift 10
	CHAR  shift 11
	VOID  shift 12
	ID  shift 13
	NUM  shift 14
	NOT  shift 15
	SEMI  shift 16
	LP  shift 17
	LFP  shift 5
	INPUT  shift 18
	PRINT  shift 19

	comp_stmt  goto 20
	input_stmt  goto 21
	if_stmt  goto 22
	exp_stmt  goto 23
	while_stmt  goto 25
	print_stmt  goto 26
	var_dec  goto 27
	for_stmt  goto 28
	type_spec  goto 29
	stmt  goto 125
	exp  goto 31
	term  goto 32
	or_exp  goto 33
	simple_exp  goto 34
	exp_equ  goto 35
	and_exp  goto 36


state 125
	for_stmt : FOR LP exp SEMI exp SEMI exp RP stmt .  (21)

	.  reduce 21


##############################################################################
# Summary
##############################################################################

37 token(s), 20 nonterminal(s)
59 grammar rule(s), 126 state(s)


##############################################################################
# End of File
##############################################################################
