# Tyler Hansen
# CS333 Spring 2021 -- Programming Languages
# 03/14/2021 <- Happy Pi Day!

# Makefile: A simple Makefile for compiling all of the cstk files for this week's C code. 
# Usage: Run the command "make" in the directory "c_work/", then execute the C file of your choosing! 

CC=gcc
CFLAGS=-I.

# Compile both files.
progs: factest qcktest
	chmod u+x factest qcktest

factest: factorial.o
	$(CC) -o factest factorial.o

qcktest: quicksort.o
	$(CC) -o qcktest quicksort.o

permit: 

.PHONY: clean

clean:
	rm -f factest factorial.o
	rm -f qcktest quicksort.o 