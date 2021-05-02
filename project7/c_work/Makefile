# Tyler Hansen
# CS333 Spring 2021 -- Programming Languages
# 04/10/2021

# Makefile: A simple Makefile for compiling all of the cstk files for this week's C code. 
# Usage: Run the command "make" in the directory "c_work/", then execute the C file of your choosing! 

CC=gcc
CFLAGS=-I.

# Compile both files.
progs: timetest numtest
	chmod u+x timetest numtest

timetest: timepercall.o
	$(CC) -o timetest timepercall.o

numtest: numberoftimes.o
	$(CC) -o numtest numberoftimes.o

permit: 

.PHONY: clean

clean:
	rm -f timetest timeper.o
	rm -f numtest numberoftimes.o