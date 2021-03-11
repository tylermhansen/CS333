# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/10/2021

# Makefile: A simple Makefile for compiling all of the Rust files for this week's Rust code. 
# Usage: Run the command "make" in the directory "rust_work/", then execute whichever executable you want! 

CC=rustc # Sets the default compiler to rustc

%.rs: 
	$(CC) $@

.PHONY: clean

clean:
	rm -f *.exe *.pdb