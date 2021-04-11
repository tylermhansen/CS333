# Tyler Hansen
# CS333 Spring 2021 -- Programming Languages
# 04/10/2021

# Makefile: A simple Makefile for compiling all of the cstk files for this week's C code. 
# Usage: Run the command "make" in the directory "c_work/", then execute the C file of your choosing! 

CC=gcc
CFLAGS=-I.

# Compile both files.
progs: inttest fpetest segtest
	chmod u+x inttest fpetest segtest

inttest: interrupt.o
	$(CC) -o inttest interrupt.o

fpetest: floatingpointexception.o
	$(CC) -o fpetest floatingpointexception.o

segtest: segfault.o
	$(CC) -o segtest segfault.o

permit: 

.PHONY: clean

clean:
	rm -f inttest interrupt.o
	rm -f fpetest floatingpointexception.o
	rm -f segtest segfault.o