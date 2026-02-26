//Seth Person
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "term.h"
#include "basiclist.h"

typedef struct {
    node_t * terms;         /* pointer to data */
    int maxDegree;  /* pointer to the next node */
} poly_t;

poly_t * new_polynomial(void);
void print_polynomial(const poly_t * poly);
void add_to_polynomial(poly_t * poly, const term_t * term);
poly_t * gen_polynomial_from_list(node_t ** term_list);
poly_t * combine_like_terms(const poly_t * poly);
void delete_polynomial(poly_t ** poly);

#endif
