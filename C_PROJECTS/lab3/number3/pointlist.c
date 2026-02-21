/* Program to demonstrate basiclist with point_t structures */

#include <stdio.h>
#include <stdlib.h>
#include "basiclist.h"

/* Define point type for Cartesian coordinates */
typedef struct point {
    int x;  /* x-coordinate */
    int y;  /* y-coordinate */
} point_t;

int main(void) {
    /* Initialize empty list (head pointer starts as NULL) */
    node_t * list = NULL;
    
    /* Pointer to traverse the list */
    node_t * curr;
    
    /* Counter variable for numbering points when printing */
    int ii;

    /* ===== Create points and add them to the list ===== */
    
    /* Create point p1 on the stack and add its address to the list */
    point_t p1 = {0, 0};
    list_add(&list, &p1);  /* &p1 passes the address of the stack variable */

    /* Create point p2 on the stack and add its address to the list */
    point_t p2 = {3, 5};
    list_add(&list, &p2);  /* &p2 passes the address of the stack variable */

    /* Create point p3 dynamically on the heap */
    point_t * p3 = (point_t *) malloc(sizeof(point_t));
    p3->x = -1;  /* Set x-coordinate using arrow notation for pointers */
    p3->y = -1;  /* Set y-coordinate using arrow notation for pointers */
    list_add(&list, p3);  /* p3 is already a pointer, so no & needed */

    /* Create point p4 dynamically on the heap */
    point_t * p4 = (point_t *) malloc(sizeof(point_t));
    p4->x = 7;   /* Set x-coordinate */
    p4->y = -3;  /* Set y-coordinate */
    list_add(&list, p4);  /* p4 is already a pointer, so no & needed */

    /* ===== Print the contents of the list ===== */
    printf("Points in the list:\n");
    
    /* Start at the head of the list */
    curr = list;
    ii = 0;
    
    /* Traverse the list until we reach the end (NULL) */
    while (curr != NULL) {
        /* Cast the void pointer to a point_t pointer to access the data */
        point_t * pt = (point_t *) curr->data;
        
        /* Print the point number and its coordinates */
        printf("  Point %d: (%d, %d)\n", ii, pt->x, pt->y);
        
        /* Increment the counter */
        ii++;
        
        /* Move to the next node in the list */
        curr = curr->next;
    }

    /* ===== Clean up dynamically allocated points ===== */
    /* Note: p1 and p2 are stack-allocated, so they don't need to be freed */
    /* Only free p3 and p4 which were allocated with malloc */
    free(p3);
    free(p4);

    return 0;
}
