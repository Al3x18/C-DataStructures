#include "graphviz_proto.h"

void print_node_recursive(FILE *f, node *n) {
    if (!n) return;

    /*
     * Each node in the graph is uniquely identified by its memory address.
     * The 'A' prefix is added to the address to create a valid Graphviz identifier,
     * as Graphviz doesn't accept hexadecimal addresses starting with '0x'.
     * 
     * Example of generated DOT syntax:
     * A0x7ffee45506c0[label=1]              // Node with value 1
     * A0x7ffee45506c0 -> A0x7ffee4550680    // Connection to left child
     * A0x7ffee45506c0 -> A0x7ffee4550640    // Connection to right child
     * A0x7ffee4550680[label=2]              // Left child node with value 2
     * A0x7ffee4550680 -> A0x7ffee4550600    // Connection to its child
     */

    // Print current node with its value as label
    fprintf(f, "A%p[label=%d]\n", (void *)n, n->value);

    // Print connection to left child if it exists
    if (n->left) {
        fprintf(f, "A%p -> A%p\n", (void *)n, (void *)n->left);
    }

    // Print connection to right child if it exists
    if (n->right) {
        fprintf(f, "A%p -> A%p\n", (void *)n, (void *)n->right);
    }

    // Recursively process left and right subtrees
    print_node_recursive(f, n->left);
    print_node_recursive(f, n->right);
}


void print_tree(node *root) {
    FILE *f;

    // Open file for writing the DOT syntax
    f = fopen("./tree.dot", "w");

    if (!f) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Write the DOT file header
    fprintf(f, "digraph G {\n");
    // Generate the tree structure in DOT format
    print_node_recursive(f, root);
    // Close the DOT file
    fprintf(f, "}\n");

    fclose(f);

    // Convert DOT file to SVG using Graphviz
    system("/opt/homebrew/bin/dot -Tsvg tree.dot > out.svg");
}