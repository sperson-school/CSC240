#include "term.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * term_to_string(const term_t * term) {
    char * termString = malloc(sizeof(char) + 1 + sizeof(int) + sizeof(int));

    if (term->exponent == 0) {
        sprintf(termString, "%d", term->coefficient);
    }
    else if (term->exponent == 1) {
        sprintf(termString, "%dx", term->coefficient);
    }
    else {
        sprintf(termString, "%dx^%d", term->coefficient, term->exponent);
    }
    return termString;
}