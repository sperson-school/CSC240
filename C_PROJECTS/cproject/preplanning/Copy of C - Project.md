**C Project** – Polynomials  
For this project you will write C code to represent and work with polynomials.  The specific implementation details are up to you, but you must use the names and method signatures given in the requirements and you should make efficient use of memory.  Your code should build with the \--std=c11 \-pedantic \-Wall flags with gcc with no warnings.

1. Create a header file called term.h which defines the following:  
   1. A user-defined type that represents a term in a polynomial called term\_t that contains the following fields:  
      * coefficient: An integer field for the coefficient  
      * var: A character field for the variable (assume the variable is a single character)  
      * exponent: An integer for the exponent

        For example: {3, 'x', 2} would represent the term 3x2.

   2. Any forward declarations required for your functions.  
2. Create a C file called term.c that defines the following function:  
   1. char \* term\_to\_string(const term\_t \* term)  returns a string representation of a term.    
3. Create a header file called polynomial.h which defines the following:  
   1. A user-defined type that represents a polynomial called poly\_t.  The polynomial should contain (at a minimum) a pointer to a list of terms and the degree(highest exponent) of the polynomial.  
      You should **make use of the basiclist from class** \- your struct needs to have a node\_t pointer.  This will save you a lot of time as well.  
   2. Any forward declarations required for your functions.  
4. Create a C file called polynomial.c that defines the following functions:  
   1. poly\_t \* new\_polynomial()  that allocates memory for a new polynomial.    
   2. void print\_polynomial(const poly\_t \* poly)  prints a polynomial.  You do not need to print the terms in any specific order.  
   3. void add\_to\_polynomial(poly\_t \* poly, const term\_t \* term)  adds a term to the polynomial.    
   4. poly\_t \* combine\_like\_terms(const poly\_t \* poly)  returns a new polynomial resulting from combining the like terms in the parameter polynomial poly.    
   5. void delete\_polynomial(poly\_t \*\* poly)  that frees memory allocated for a  polynomial  
5. Complete the provided C program called project.c which reads a set of terms from terms.txt & stores the objects in a basiclist.  You should add the items from the basiclist into a polynomial then print it.   Then, print the result of combining like terms in the polynomial.  **Also, print your name at the start & end of your program’s output**.  You can assume that all terms in the polynomial contain the same variable.

You should use good design principles, including using header/source files and deciding on which data types to use for the data members of your structs.  Use whitespace, comments, and good variable names to improve readability.  Your output should be neat and concise.   Feel free to add additional c/h files as you find appropriate, however **you should not modify the basiclist.c/h files**.  Include a comment with your name at the top of each source file.   **Your code must compile with gcc using the \--std=c11, \-Wall and –pedantic flags.**  Code that fails to compile will receive less than 50% credit *no matter how minor the error is*.  I strongly recommend not using Visual Studio as it is difficult to ensure ANSI-compliant C code.  You can also use the provided makefile to build your code.  That is what I will be using to compile & test your code.  

Submit the **zipped source code** including **all files required to compile and run** your program.  Do **not** include any files in the zip file that are not required to compile your code (eg. .o, .exe, swapfiles, backups, etc.). Your submission should include *at least* the following files:

* project.c  
* term.c / term.h   
* polynomial.c / polynomial.h  
* basiclist.c / basiclist.h / terms.txt (you should **not** modify these)  
* Any other C files you created (optional)  
* The provided makefile 

In addition to your zipped source, **fill in the end of this document & submit a PDF separately from your code**.  Be prepared to demo your programs in class on the due date.  **Start early\!** 

*Briefly* describe your implementation in the box below:   
   
   
*Briefly* describe any issues you ran into (if any) with your implementation in the box below:   
   
   
For each of the following, copy & paste your output or code *without formatting* & *as text*.  **You should not change the formatting inside the boxes.**  Do not paste screenshots.  Each box is formatted for colored, monospaced code, so your submission should be the same if you paste correctly.   The ability to follow these directions will be factored into your grade, so if you do not understand or have difficulty,, you should ask the instructor for help.

Paste the command you used to compile your code *without formatting* in the box below:  
   
   
Paste your **output** in the box below:  
   
   
Paste your *entire* **term.h** file in the box below:  
   
   
Paste your *entire* **polynomial.h** file in the box below:  
   
   
Paste your **term\_to\_string()** method in the box below:  
   
   
Paste your **add\_to\_polynomial()** method in the box below:

   
Paste your **combine\_like\_terms()** method in the box below:  
   
   
Sample Output (user input is bold):  
**$ make clean**  
**rm \-f \*.o \*\~ project.exe**  
**$ make**  
**gcc  \-Wall \-pedantic \--std=c11 \-c term.c**  
**gcc  \-Wall \-pedantic \--std=c11 \-c polynomial.c**  
**gcc  \-Wall \-pedantic \--std=c11 \-c basiclist.c**  
**gcc  \-Wall \-pedantic \--std=c11 project.c term.o polynomial.o basiclist.o \-o project**  
**$ ./project**  
**$ ./project.exe**  
**NAME: SAMPLE OUTPUT**  
**Testing term.c/h:**  
**testterm1: 1**  
**testterm2: 2x**  
**testterm3: 3x^2**

**Testing basic polynomial functions: Adding terms n& testing print\_poly**  
**Polynomial of degree 2: 3x^2 \+ 2x \+ 1**

**Testing polynomial.c/h :**  
**Original: : Polynomial of degree 4: 2 \+ 5x^3 \+ 3x \+ 2x^4 \+ 0 \+ 3x^2 \+ 4 \+ 3x \+ 4x^2 \+ 3x^3 \+ 5x^2**  
**Combined: : Polynomial of degree 4: 2x^4 \+ 8x^3 \+ 12x^2 \+ 6x \+ 6**  
**NAME: SAMPLE OUTPUT**

