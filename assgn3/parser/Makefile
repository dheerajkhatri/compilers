# Makefile

OBJS	= bison.o lex.o main.o

CC	= g++
CFLAGS	= -g -Wall -ansi -pedantic

grammar:		$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o grammar -lfl

lex.o:		lex.c
		$(CC) $(CFLAGS) -c lex.c -o lex.o

lex.c:		grammar.lex 
		flex grammar.lex
		cp lex.yy.c lex.c

bison.o:	bison.c
		$(CC) $(CFLAGS) -c bison.c -o bison.o

bison.c:	grammar.y
		bison -d -v grammar.y
		cp grammar.tab.c bison.c
		cmp -s grammar.tab.h goyal.h || cp grammar.tab.h goyal.h

main.o:		main.cc
		$(CC) $(CFLAGS) -c main.cc -o main.o

lex.o yac.o main.o	: heading.h
lex.o main.o		: goyal.h

clean:
	rm -f *.o *~ lex.c lex.yy.c bison.c goyal.h grammar.tab.c grammar.tab.h grammar.output grammar

