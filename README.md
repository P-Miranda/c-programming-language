# C Programming Language
Exercises and examples from the book **C Programming Language** by Brian Kernighan and Dennis Ritchie.

## Organization
The examples and exercises are organized by the book chapters and sections.

## Run example/exercice
To execute an example from top level:
```
make run CHAPTER=X EXAMPLE=X-Y
```
or to execute an exercise from to level:
```
make run CHAPTER=X EXERCISE=X-Y
```

## TODO
- All global make clean
- Chapter 1, Exercise 24
- Example and Exercise Index

* * *

## Examples and Exercise Index

### Chapter 1: A Tutorial Introduction
- Example1-1:
- Example1-2:
- ...
- Exercise1-1:
- ...

### Chapter 2: Type, Operators and Expressions
- Example2-1: Compilation of all small examples throughout the chapter.
    - strlen implementation
    - enums
    - check for leap years
    - atoi
    - lower
    - pseudo random implementation
    - delete all instances of a char from a string
    - strcat, contatenate strings
    - get n bits from position p
    - count 1 bits in x integer
- Exercise2-1: Determine the ranges of various C types: `char`, `short`, `int` and `long`.
    - WIP: Also calculate ranges for `float` and `double`
- Exercise2-2: Write a for loop to read from terminal without using `&&` or `||`.
- Exercise2-3: Write a function `htoi(s)` which converts a string from hex to int.
- Exercise2-4: Write a function that deletes all chars in a string that match the characters in another string.
- Exercise2-5: Write a function that returns the first location where a character of a string appears on another one.
- Exercise2-6: Write a function that set the n bits from p in x according to bits from y.
- Exercise2-7: Write a function that inverts a range of bits from x.
- Exercise2-8: Write a function that returns x rotated by n bit positions.
- Exercise2-9: Write a faster version of bitcount.
- Exercise2-10: Write a version of lower function with conditional expressions.

### Chapter 3: Control Flow
- Example3-1: Compilation of all small examples throughout the chapter.
    - binary search
    - count digits, white spaces and others using a switch-case statement
    - atoi: more general version
    - shell sort
    - reverse string in place
    - itoa
- Exercise3-1: Rewrite binsearch to use only one test inside the loop.
- Exercise3-2: Write a function that converts '\t' and '\n' into visible escape sequences, and a function that performs the opposite.
- Exercise3-3: Write a function that expands shorthand notations: a-z, 1-9, etc.
- Exercise3-4: Write a version o itoa that supports -(2^Wordsize-1).
- Exercise3-5: Write a version of itoa that supports different number basis.
- Exercise3-6: Write a version of itoa that has a minimum field width.

### Chapter 4: Functions and Program Structure
- Example4-1: Program that prints each line that contains a matching string (`grep`-like)
- Example4-2: Compilation of all small examples throughout the chapter.
    - atof: convert strint to double
    - simple calculator
    - atoi implementation based on atof
- Example4-3: Reverse Polish calculator
- Example4-4: Reverse Polish calculator in multiple source files
- Example4-5: Recursive implementation of `printd()`
- Example4-6: Recursive quicksort implementation
- Exercise4-1: Write a function that prints the index of the rightmost occurence of `t` in `s`.
- Exercise4-2: Extend atof to handle scientific notation (123.45e-6)
- Exercise4-3: Extend example4-3 to calculate modulus
- Exercise4-4: Implement function to print stack top, duplicate stack top, swap top two stack itens and clear the stack. Without poping items
- Exercise4-5: Add access to math.h library functions (sin, cos, pow)
- Exercise4-6: Add commands for handling variables. Add a variable for most recently printed value
- Exercise4-7: Write a routine `ungets(s)` that will push back an entire string onto the input.
- Exercise4-8: Modify `getch` and `ungetch` to account for at most one character of pushback.
- Exercise4-9: Handle `EOF` push back in `getch` and `ungetch`
- Exercise4-10: `getline` to read an entire input line instead of `getch` and `ungetch`
- Exercise4-11: Modify `getop` so that it doesn't need to use `ungetch`.
- Exercise4-12: Write a recursive version of `itoa()` from `printd()`.
- Exercise4-13: Write a recursive version of `reverse(s)`, which reverses the string in place.
- Exercise4-14: Define a macro to swap two arguments of the same type.

### Chapter 5: Pointers and Arrays
- Example5-1: getint function that returns integer from input stream.
- Example5-2: strlen v1 and v2.
- Example5-3: rudimentary storage allocator.
- Example5-4: strcpy array subscript version, pointer versions 1, 2 and 3.
- Example5-5: strcmp function array subscript and pointer versions.
- Example5-6: line sorting program (pointers to pointers).
- Example5-7: multidimensional arrays for date convertion.
- Example5-8: command line arguments: echo program versions 1 and 2.
- Example5-9: match pattern from command line.
- Example5-10: match pattern from command line with optional arguments.
- Example5-11: qsort with function pointers.
- Example5-12: `dcl` program. Convert C declaration to a word description. Recursive-descent parser.
- Example5-13: `undcl` program. Convert word description to C declaration.
- Exercise5-1: Fix getint to push back isolated `+` and `-` chars.
- Exercise5-2: Write `getfloat` based on `getint`.
- Exercise5-3: Write a pointer version of  `strcat()`.
- Exercise5-4: Write the function `strend(s,t)`, checks for t at the end of s.
- Exercise5-5: Write a pointer version of `strcpy()`, `strncat()` and `strncmp()`.
- Exercise5-6: **[TODO]** Rewrite pointer versions of previous functions.
- Exercise5-7: Rewrite `readlines`to store lines in an array given by `main`.
- Exercise5-8: Add error checking to `day_of_year` and `month_day`.
- Exercise5-9: Rewrite `day_of_year` and `month_day` with pointers.
- Exercise5-10: Reverse Polish calculator from command line arguments.
- Exercise5-11: **Skipped**
- Exercise5-12: **Skipped**
- Exercise5-13: Write a simple version of `tail` program. 
- Exercise5-14: Add reverse `-r` option to sort program.
- Exercise5-15: Add fold `-f`, so that upper and lower case letters compare equal.
- Exercise5-16: **Skipped**
- Exercise5-17: **Skipped**
- Exercise5-18: **Skipped**
- Exercise5-19: **Skipped**
- Exercise5-20: **Skipped**
