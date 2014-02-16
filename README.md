Binary Tree
===========

Coded in C by Selena

Creates a root node with left and right pointers.

## Structure
The source files are seperated from the compiled output:

	/src 		- source files
	/bin 		- compiled output
	make 		- makefile

## Compiling
*make* is a shell script to compile the C source in ```/src```. Usage:

	./make

## Running
*make* output file is:

	./bin/btree

## .gitignore
We don't want the compiled output tracked by git, so we use a ```.gitignore``` file to get git to ignore the bin folder.