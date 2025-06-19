#include "prototipi.h"
#include <stdlib.h>

node* createBST() {
    return NULL;
}

node* search(node* T, int key) {
    if (T == NULL || T->key == key) {
        return T;
    }

    if (key < T->key) {
        return search(T->left, key);
    }

    return search(T->right, key);
}

void insert(node** T, int new_key) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = new_key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    if (*T == NULL) {
        *T = new_node;
        return;
    }

    node* current = *T;
    node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (new_key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    new_node->parent = parent;
    if (new_key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

node* findMin(node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void del_node(node** T, int delete_key) {
    if (*T == NULL) return;

    node* current = *T;
    node* parent = NULL;

    // Find the node to delete
    while (current != NULL && current->key != delete_key) {
        parent = current;
        if (delete_key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) return; // Key not found

    // Case 1: Node has no children
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            *T = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }
    // Case 2: Node has one child
    else if (current->left == NULL) {
        if (parent == NULL) {
            *T = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        current->right->parent = parent;
        free(current);
    }
    else if (current->right == NULL) {
        if (parent == NULL) {
            *T = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        current->left->parent = parent;
        free(current);
    }
    // Case 3: Node has two children
    else {
        node* successor = findMin(current->right);
        int temp = successor->key;
        del_node(T, successor->key);
        current->key = temp;
    }
}