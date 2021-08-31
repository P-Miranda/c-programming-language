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
- Exercise2-1: Determine the ranges of various C types: `char`, `short`, `int` and `long`.
    - WIP: Also calculate ranges for `float` and `double`
- Exercise2-2: Write a for loop to read from terminal without using `&&` or `||`.
- Exercise2-3: Write a function `htoi(s)` which converts a string from hex to int.
- Exercise2-4: Write a function that deletes all chars in a string that match the characters in another string.
- Exercise2-5: Write a function that returns the first location where a character of a string appears on another one.
