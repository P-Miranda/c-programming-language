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
- Exercise4-1: Write a function that prints the index of the rightmost occurence of `t` in `s`.
