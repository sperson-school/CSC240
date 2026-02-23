# CSC240 C Project - Polynomials: Plan of Action

## Project Summary

You are building a C program that represents and manipulates polynomials using
linked lists. A polynomial is made up of terms (e.g. `3x^2`), stored in a
linked list. You will implement functions to create, print, and combine
polynomials, then read terms from a file and demonstrate the results.

**Your code must compile cleanly with:** `gcc --std=c11 -pedantic -Wall`

---

## Phase 0: Prerequisites / What You Need to Learn First

Before writing any code, make sure you are comfortable with these C concepts.
Work through them in order -- each builds on the last.

### Lesson 0.1: C Compilation Basics
- [ ] Understand how `gcc` compiles C code
- [ ] Know the difference between `.c` (source) and `.h` (header) files
- [ ] Understand what `--std=c11`, `-pedantic`, and `-Wall` flags do
  - `--std=c11` : use the C11 standard (no compiler extensions)
  - `-pedantic` : reject all non-standard code
  - `-Wall` : enable all common warnings
- [ ] Learn to use `make` and read a simple `Makefile`
- [ ] Practice: compile a "Hello World" with `gcc -Wall -pedantic --std=c11 hello.c -o hello`

### Lesson 0.2: Structs and Typedef
- [ ] Understand what a `struct` is and how to declare one
- [ ] Understand `typedef` and why we use it (e.g. `typedef struct { ... } term_t;`)
- [ ] Practice creating a struct, assigning values, and printing them
- [ ] Understand the difference between stack-allocated structs and heap-allocated structs

### Lesson 0.3: Pointers
- [ ] Understand what a pointer is (`*`) and the address-of operator (`&`)
- [ ] Understand pointer-to-struct and the arrow operator (`->`)
- [ ] Understand `const` pointers (e.g. `const term_t *term` means you cannot modify what term points to)
- [ ] Understand double pointers (`**`) and why `delete_polynomial` uses `poly_t **poly`
  - This lets the function set the caller's pointer to `NULL` after freeing

### Lesson 0.4: Dynamic Memory Allocation
- [ ] Understand `malloc()`, `calloc()`, and `free()`
- [ ] Know how to allocate a struct on the heap: `term_t *t = malloc(sizeof(term_t));`
- [ ] Understand why you must always `free()` what you `malloc()`
- [ ] Understand memory leaks and how to avoid them
- [ ] Practice: allocate a struct, fill it in, use it, then free it

### Lesson 0.5: Strings in C
- [ ] Understand that C strings are `char` arrays terminated by `'\0'`
- [ ] Know how to use `sprintf()` or `snprintf()` to format a string
- [ ] Understand that `term_to_string` must return a dynamically allocated string
  - Use `malloc` to create the buffer, `snprintf` to fill it, return the pointer
  - The caller is responsible for freeing it
- [ ] Practice: write a function that returns a formatted string from an int

### Lesson 0.6: Linked Lists
- [ ] Understand the concept of a singly linked list
- [ ] Understand nodes: each node holds data + a pointer to the next node
- [ ] Understand how to traverse a linked list
- [ ] Understand how to insert at head, tail, or in order
- [ ] Understand how to free an entire linked list
- [ ] **Study the provided `basiclist.c` / `basiclist.h` files carefully**
  - These are given to you and must not be modified
  - Your `poly_t` struct will use a `node_t *` from the basiclist

### Lesson 0.7: Header Files and Multi-File Projects
- [ ] Understand include guards (`#ifndef TERM_H` / `#define TERM_H` / `#endif`)
- [ ] Understand forward declarations (function prototypes in `.h`, implementations in `.c`)
- [ ] Understand `#include "term.h"` (quotes for your files) vs `#include <stdio.h>` (angle brackets for system)
- [ ] Understand how the linker combines `.o` files into an executable

### Lesson 0.8: File I/O
- [ ] Understand `fopen()`, `fclose()`, `fscanf()`, `fgets()`
- [ ] Know how to read structured data from a text file
- [ ] Study `terms.txt` to see the format of the input data
- [ ] Practice: write a small program that reads integers from a file and prints them

---

## Phase 1: Get the Provided Files

- [ ] Obtain from your instructor (or class materials):
  - `basiclist.c` and `basiclist.h` (the linked list library -- do NOT modify)
  - `terms.txt` (the input data file -- do NOT modify)
  - `project.c` (the partially complete main program)
  - `Makefile` (the provided makefile for building)
- [ ] Read and understand `basiclist.h` -- what types and functions does it provide?
- [ ] Read and understand `basiclist.c` -- how does it implement the linked list?
- [ ] Read `terms.txt` -- what does the data look like?
- [ ] Read the provided `project.c` -- what is already written? What needs completing?
- [ ] Make sure `make` runs (it will fail, but confirm the Makefile works)

---

## Phase 2: Implement `term.h` and `term.c`

### 2.1: Create `term.h`
- [ ] Add a comment with your name at the top
- [ ] Add include guards
- [ ] Define the `term_t` type using `typedef struct`:
  ```
  Fields:
    - coefficient (int)
    - var (char)
    - exponent (int)
  ```
- [ ] Add the forward declaration for `term_to_string`:
  ```c
  char * term_to_string(const term_t * term);
  ```
- [ ] Include any necessary standard headers

### 2.2: Create `term.c`
- [ ] Add a comment with your name at the top
- [ ] `#include "term.h"` and any standard headers you need (`<stdio.h>`, `<stdlib.h>`, `<string.h>`)
- [ ] Implement `term_to_string(const term_t * term)`:
  - Allocate a char buffer with `malloc` (pick a reasonable size, e.g. 64 bytes)
  - Handle special cases for display:
    - Coefficient of 0: just print `"0"`
    - Exponent of 0: just print the coefficient (e.g. `"3"`)
    - Exponent of 1: print coefficient and var (e.g. `"3x"`)
    - Coefficient of 1: don't print the `1` (e.g. `"x^2"` not `"1x^2"`)
    - Coefficient of -1: print just `-` (e.g. `"-x^2"` not `"-1x^2"`)
    - General case: print `"3x^2"`
  - Return the allocated string
- [ ] Test: compile `term.c` alone with `gcc -Wall -pedantic --std=c11 -c term.c`
- [ ] Verify zero warnings

### 2.3: Test term functionality
- [ ] Write a small temporary `main` to test `term_to_string` with different terms:
  - `{1, 'x', 0}` should produce `"1"`
  - `{2, 'x', 1}` should produce `"2x"`
  - `{3, 'x', 2}` should produce `"3x^2"`
- [ ] Compare your output to the sample output in the project instructions

---

## Phase 3: Implement `polynomial.h` and `polynomial.c`

### 3.1: Create `polynomial.h`
- [ ] Add a comment with your name at the top
- [ ] Add include guards
- [ ] `#include "term.h"` and the basiclist header
- [ ] Define the `poly_t` type using `typedef struct`:
  ```
  Fields (minimum):
    - pointer to a list of terms (node_t * from basiclist)
    - degree (int) -- the highest exponent
  ```
- [ ] Add forward declarations for all polynomial functions:
  ```c
  poly_t * new_polynomial();
  void print_polynomial(const poly_t * poly);
  void add_to_polynomial(poly_t * poly, const term_t * term);
  poly_t * combine_like_terms(const poly_t * poly);
  void delete_polynomial(poly_t ** poly);
  ```

### 3.2: Create `polynomial.c` - `new_polynomial()`
- [ ] Add a comment with your name at the top
- [ ] `#include "polynomial.h"` and any needed standard headers
- [ ] Implement `new_polynomial()`:
  - `malloc` a `poly_t`
  - Initialize the list pointer to `NULL`
  - Initialize degree to 0
  - Return the pointer

### 3.3: Implement `add_to_polynomial()`
- [ ] Make a copy of the term (malloc a new `term_t`, copy the values)
- [ ] Add the copied term to the polynomial's linked list (use basiclist functions)
- [ ] Update the degree if the new term's exponent is higher than the current degree
- [ ] Think about memory ownership: the polynomial now owns the copy

### 3.4: Implement `print_polynomial()`
- [ ] Print format: `"Polynomial of degree N: "` followed by terms joined by `" + "`
- [ ] Traverse the linked list
- [ ] For each term, use `term_to_string()` to get the string, print it, then free the string
- [ ] Handle the `" + "` separator (no leading `+` before first term)
- [ ] Print a newline at the end
- [ ] Note: terms do NOT need to be in any specific order

### 3.5: Implement `combine_like_terms()`
- [ ] Create a new polynomial (using `new_polynomial()`)
- [ ] Traverse the original polynomial's terms
- [ ] For each term, check if the new polynomial already has a term with the same exponent
  - If yes: add the coefficients together
  - If no: add a copy of the term to the new polynomial
- [ ] Skip terms with coefficient 0 in the result (optional but cleaner)
- [ ] Return the new polynomial
- [ ] **Important**: the original polynomial must not be modified (`const` parameter)

### 3.6: Implement `delete_polynomial()`
- [ ] Free each term in the linked list
- [ ] Free each node in the linked list
- [ ] Free the `poly_t` struct itself
- [ ] Set the caller's pointer to `NULL`: `*poly = NULL;`
- [ ] This is why the parameter is `poly_t **` -- so you can null out the caller's pointer

### 3.7: Test polynomial functionality
- [ ] Compile: `gcc -Wall -pedantic --std=c11 -c polynomial.c`
- [ ] Verify zero warnings
- [ ] Write a small test main:
  - Create a polynomial
  - Add terms: `{3,'x',2}`, `{2,'x',1}`, `{1,'x',0}`
  - Print it
  - Expected: `Polynomial of degree 2: 3x^2 + 2x + 1` (order may vary)

---

## Phase 4: Complete `project.c`

- [ ] Add a comment with your name at the top
- [ ] Print your name at the start of output
- [ ] Read terms from `terms.txt`:
  - Open the file with `fopen`
  - Read each term's data (coefficient, variable, exponent)
  - Store terms in a basiclist
- [ ] Create a polynomial and add all terms from the basiclist to it
- [ ] Print the original polynomial
- [ ] Call `combine_like_terms()` and print the combined result
- [ ] Free all allocated memory (delete both polynomials, free the basiclist)
- [ ] Print your name at the end of output
- [ ] Close the file

---

## Phase 5: Build, Test, and Compare to Sample Output

- [ ] Run `make clean` then `make` -- confirm zero warnings
- [ ] Run `./project` (or `./project.exe`)
- [ ] Compare your output to the sample output:
  ```
  NAME: SAMPLE OUTPUT
  Testing term.c/h:
  testterm1: 1
  testterm2: 2x
  testterm3: 3x^2

  Testing basic polynomial functions: Adding terms & testing print_poly
  Polynomial of degree 2: 3x^2 + 2x + 1

  Testing polynomial.c/h :
  Original: : Polynomial of degree 4: 2 + 5x^3 + 3x + 2x^4 + 0 + 3x^2 + 4 + 3x + 4x^2 + 3x^3 + 5x^2
  Combined: : Polynomial of degree 4: 2x^4 + 8x^3 + 12x^2 + 6x + 6
  NAME: SAMPLE OUTPUT
  ```
- [ ] Verify the combined polynomial is mathematically correct
- [ ] Check for memory leaks (if you have `valgrind` available: `valgrind ./project`)

---

## Phase 6: Fill in the Design Document

- [ ] **Section 1 - Introduction**: Describe the purpose (polynomial representation/manipulation in C using linked lists), scope, and any terms
- [ ] **Section 2 - Overview**: High-level description of how term.c, polynomial.c, basiclist, and project.c interact
- [ ] **Section 3 - Data Design**: Document your `term_t` and `poly_t` structs with all fields, purposes, and relationships
- [ ] **Section 4 - Algorithm Design**: Pseudocode for each function, especially:
  - `term_to_string` (the special cases)
  - `add_to_polynomial` (copy term, insert into list, update degree)
  - `combine_like_terms` (traverse, find matching exponent, accumulate coefficients)
  - `delete_polynomial` (free terms, free nodes, free struct, null pointer)
  - Main program flow (open file, read, build list, build poly, print, combine, print, cleanup)
- [ ] **Section 5 - Testing Plan**: List test cases:
  - Terms with exponent 0, 1, and > 1
  - Terms with coefficient 0, 1, -1, and general
  - Empty polynomial
  - Polynomial with one term
  - Polynomial with no like terms
  - Polynomial with all like terms
  - Memory cleanup (no leaks)
- [ ] **Section 6 - Appendices**: Any additional notes

---

## Phase 7: Prepare Submission

- [ ] Fill in the implementation description box in the project document
- [ ] Fill in the issues/difficulties box
- [ ] Paste your compile command
- [ ] Paste your program output
- [ ] Paste your `term.h` file
- [ ] Paste your `polynomial.h` file
- [ ] Paste your `term_to_string()` function
- [ ] Paste your `add_to_polynomial()` function
- [ ] Paste your `combine_like_terms()` function
- [ ] Export the project document as PDF and submit separately
- [ ] Create the zip file with ONLY the required files:
  - `project.c`
  - `term.c` / `term.h`
  - `polynomial.c` / `polynomial.h`
  - `basiclist.c` / `basiclist.h` / `terms.txt` (unmodified)
  - `Makefile`
  - Any additional `.c`/`.h` files you created
- [ ] **Do NOT include**: `.o` files, executables, swap files, backups, `.DS_Store`, etc.
- [ ] Verify: unzip into a clean directory, run `make`, run `./project` -- does it work?

---

## Phase 8: Prepare for Demo

- [ ] Be able to explain your `term_t` and `poly_t` struct designs
- [ ] Be able to explain how `combine_like_terms` works step by step
- [ ] Be able to explain your memory management strategy (what gets malloc'd, what gets freed, when)
- [ ] Be able to explain how you used the basiclist
- [ ] Be ready to walk through your code in front of the instructor

---

## Quick Reference: Key Gotchas

| Pitfall | How to Avoid |
|---|---|
| Forgetting to free `term_to_string` result | Always `free()` the returned string after printing |
| Modifying original poly in `combine_like_terms` | Parameter is `const` -- create a new poly, copy data |
| Not setting pointer to NULL in `delete_polynomial` | Use double pointer: `*poly = NULL;` |
| Forgetting include guards | Every `.h` file needs `#ifndef` / `#define` / `#endif` |
| Modifying `basiclist.c/h` | These are provided and must stay unchanged |
| Compiler warnings | Always compile with `-Wall -pedantic --std=c11`, fix ALL warnings |
| Including `.o` or executables in zip | Only include source files, headers, Makefile, and terms.txt |
| Not printing your name | Must appear at both the start and end of output |
