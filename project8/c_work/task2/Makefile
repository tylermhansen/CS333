# Tyler Hansen
# CS333 Spring 2021 -- Programming Languages
# 05/10/2021

# Makefile: A simple Makefile for compiling all of the cstk files for this week's C code. 
# Usage: Run the command "make" in the directory "c_work/", then execute "./colorize <image>"

CC=gcc # Sets the default compiler to gcc
CFLAGS=-I. # Sets the list of flags to pass the compilation command
DEPS = ppmIO.h # Defines a rule that describes that the C files are dependent on ppmIO.h

# Standard Makefile business... thanks to Bruce Maxwell for the guide on Makefiles! (https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

colorize: colorize.o ppmIO.o
	$(CC) -o colorize colorize.o ppmIO.o
	chmod u+x colorize

.PHONY: clean

clean:
	rm -f colorize colorize.o ppmIO.o