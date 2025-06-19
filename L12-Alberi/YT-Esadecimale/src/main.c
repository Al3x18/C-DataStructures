#include "graphviz_proto.h"  //graphviz_proto.h already includes proto.h
#include <stdio.h>

int main(void) {
    // Primo albero
    node *n1 = new_node(1);
    node *n2 = new_node(2);
    node *n3 = new_node(3);
    node *n4 = new_node(4);
    node *n5 = new_node(5);
    node *n6 = new_node(6);
    node *n7 = new_node(7);
    node *n8 = new_node(8);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n6->right = n7;
    n6->left = n8;

    // Secondo albero (stessa struttura, valori diversi)
    node *m1 = new_node(10);
    node *m2 = new_node(20);
    node *m3 = new_node(30);
    node *m4 = new_node(40);
    node *m5 = new_node(50);
    node *m6 = new_node(60);
    node *m7 = new_node(70);
    node *m8 = new_node(80);

    m1->left = m2;
    m1->right = m3;
    m2->left = m4;
    m2->right = m5;
    m3->left = m6;
    m6->right = m7;
    m6->left = m8;

    // Terzo albero (s)
    node *s1 = new_node(2);
    node *s2 = new_node(3);
    node *s3 = new_node(9);
    node *s4 = new_node(9);
    node *s5 = new_node(9);
    node *s6 = new_node(6);
    node *s7 = new_node(6);


    s1->left = s2;
    s1->right = s3;
    s2->left = s4;
    s2->right = s5;
    s3->left = s6;
    s3->right = s7;


    // Quarto albero (x)
    node *x1 = new_node(2);
    node *x2 = new_node(3);
    node *x3 = new_node(9);
    node *x4 = new_node(9);
    node *x5 = new_node(10);
    node *x6 = new_node(7);
    node *x7 = new_node(8);

    x1->left = x2;
    x1->right = x3;
    x2->left = x4;
    x2->right = x5;
    x3->left = x6;
    x3->right = x7;

    printf("Depth: %d\n", compute_depth(n1));
    printf("Sum: %d\n", compute_sum(n1));
    printf("Leaf nodes: %d\n", child_nodes(n1));
    
    printf("\nTesting foglieK at different heights:\n");
    printf("Altezza 0 (radice): %d foglie\n", foglieK(n1, 0));  // nodo 1
    printf("Altezza 1 (figli radice): %d foglie\n", foglieK(n1, 1));  // nodi 2,3
    printf("Altezza 2 (foglie): %d foglie\n", foglieK(n1, 2));  // nodi 4,5,6
    printf("Altezza 3 (foglie): %d foglie\n", foglieK(n1, 3));  // nodi 7,8

    printf("\nTesting strutturalmente_uguali:\n");
    printf("Gli alberi sono strutturalmente uguali? %s\n", 
           strutturalmente_uguali(n1, m1) ? "Sì" : "No");

    //print_tree(n1);
    //print_tree(m1);

    printf("\nTesting alberi s e x:\n");
    printf("Gli alberi s e x sono strutturalmente uguali? %s\n", 
           strutturalmente_uguali(s1, x1) ? "Sì" : "No");
    //print_tree(s1);
    if (somma_uguale_dx_sx(s1)) {
        printf("La somma dei nodi a sinistra e a destra nell albero S è uguale\n");
    } else {
        printf("La somma dei nodi a sinistra e a destra nell albero S non è uguale\n");
    }

    if (somma_uguale_dx_sx(x1)) {
        printf("La somma dei nodi a sinistra e a destra nell albero X è uguale\n");
    } else {
        printf("La somma dei nodi a sinistra e a destra nell albero X non è uguale\n");
    }

    //print_tree(x1);

    // Deallocazione del primo albero
    del_node(n1);
    del_node(n2);
    del_node(n3);
    del_node(n4);
    del_node(n5);
    del_node(n6);
    del_node(n7);
    del_node(n8);

    // Deallocazione del secondo albero
    del_node(m1);
    del_node(m2);
    del_node(m3);
    del_node(m4);
    del_node(m5);
    del_node(m6);
    del_node(m7);
    del_node(m8);

    // Deallocazione del terzo albero
    del_node(s1);
    del_node(s2);
    del_node(s3);
    del_node(s4);
    del_node(s5);
    del_node(s6);
    del_node(s7);

    // Deallocazione del quarto albero
    del_node(x1);
    del_node(x2);
    del_node(x3);
    del_node(x4);
    del_node(x5);
    del_node(x6);
    del_node(x7);

    return 0;
}