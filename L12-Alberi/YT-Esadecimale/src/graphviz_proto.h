#include "proto.h"
#include <stdio.h>

/**
 * Recursively prints a node and its connections in Graphviz DOT format.
 * @param f Pointer to the output file where the DOT syntax will be written
 * @param n Pointer to the current node being processed
 * 
 * This function generates the DOT syntax for a single node and its connections
 * to its children. It uses the node's memory address as a unique identifier
 * and prints the node's value as its label.
 */
void print_node_recursive(FILE *f, node *n);

/**
 * Creates a visual representation of a binary tree using Graphviz.
 * @param root Pointer to the root node of the tree
 * 
 * This function:
 * 1. Creates a DOT file (tree.dot) containing the tree structure
 * 2. Calls print_node_recursive to generate the DOT syntax
 * 3. Converts the DOT file to an SVG image using the Graphviz 'dot' tool
 * 
 * The resulting SVG file (out.svg) can be viewed in any web browser
 * to see a visual representation of the tree structure.
 */
void print_tree(node *root);