#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>

poly_t * new_polynomial(void){
    poly_t * ret = malloc(sizeof(poly_t));
    ret->terms = NULL;
    ret->maxDegree = 0;
    return ret;

}

void print_polynomial(const poly_t * poly) {
    node_t * curr = poly->terms;
    while (curr != NULL) {
        term_t * this_term = (term_t *) curr->data;
        printf("%s ", term_to_string(this_term));
        if (curr->next != NULL) {
            printf("+ ");
        }
        curr = curr->next;
    }
    printf("\n");

}

poly_t * gen_polynomial_from_list(node_t ** term_list){
    poly_t * bigPolynomial = new_polynomial();
    node_t * curr = *term_list;
    while (curr != NULL) {
        term_t * currentTerm = (term_t *) curr->data;
        add_to_polynomial(bigPolynomial, currentTerm);
        //calculating max degree
        if (currentTerm->exponent > bigPolynomial->maxDegree) {
            bigPolynomial->maxDegree = currentTerm->exponent;
        }
//        printf("Current max degree: %d\n", bigPolynomial->maxDegree);
        curr = curr->next;
//        printf("Added term: %s\n", term_to_string(currentTerm));
    }
    return bigPolynomial;
}

void add_to_polynomial(poly_t * poly, const term_t * term){
    list_add(&poly->terms, term);
    if (term->exponent > poly->maxDegree) {
        poly->maxDegree = term->exponent;
    }
}

poly_t * combine_like_terms(const poly_t * poly){
    poly_t * combinedPoly = new_polynomial();
    node_t * curr = poly->terms;
    node_t * curr2 = poly->terms;
    int processedCoefficients[poly->maxDegree + 1];
    for (int i = 0; i <= poly->maxDegree; i++) {
        processedCoefficients[i] = 0;
    }
    while (curr != NULL) {
        term_t * currentTerm = (term_t *) curr->data;
//        printf("Processing term: %s\n", term_to_string(currentTerm));
        if (processedCoefficients[currentTerm->exponent]) {
            curr = curr->next;
//            printf("Already processed exponent %d, skipping\n", currentTerm->exponent);
            continue;
        }

        processedCoefficients[currentTerm->exponent] = 1;

        int combinedCoefficient = currentTerm->coefficient;

        while (curr2 != NULL) {
            term_t * compareTerm = (term_t *) curr2->data;
//            printf("Comparing with term: %s\n", term_to_string(compareTerm));
            if (currentTerm->exponent == compareTerm->exponent && currentTerm != compareTerm) {
                combinedCoefficient += compareTerm->coefficient;
//                printf("Found like term: %s, new coefficient: %d\n", term_to_string(compareTerm), currentTerm->coefficient);
            }
            curr2 = curr2->next;
        }
        curr2 = poly->terms; // reset curr2 for the next iteration

        term_t * newTerm = malloc(sizeof(term_t));
        newTerm->coefficient = combinedCoefficient;
        newTerm->var = currentTerm->var;
        newTerm->exponent = currentTerm->exponent;
        add_to_polynomial(combinedPoly, newTerm);

        curr = curr->next;
    }


    return combinedPoly;
}

void delete_polynomial(poly_t ** poly) {
    node_t * curr = (*poly)->terms;
    while (curr != NULL) {
        node_t * next = curr->next;
        free((void *) curr->data);  // free the term_t
        free(curr);                  // free the node_t
        curr = next;
    }
    free(*poly);      // free the poly_t struct
    *poly = NULL;     // set pointer to NULL to avoid dangling pointer
}
