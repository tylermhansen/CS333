# Tyler Hansen
# CS333 Spring 2021 -- Programming Languages
# 04/10/2021

# Makefile: A simple Makefile for compiling all of the cstk files for this week's C code. 
# Usage: Run the command "make" in the directory "c_work/", then execute the C file of your choosing! 

CC = gcc
CFLAGS= -I.
DEPS = mergesortlib.h
OBJ1 = mergesorter.o mergesortlib.o 
OBJ2 = timing_experiments.o mergesortlib.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Mergetest Experiment
	chmod u+x Mergetest Experiment

Mergetest: $(OBJ1)
	gcc -o $@ $^ $(CFLAGS)

Experiment: $(OBJ2)
	gcc -o $@ $^ $(CFLAGS)

permit: 

.PHONY: clean

clean:
	rm -f Mergetest mergesortlib.o
	rm -f Experiment timing_experiments.o