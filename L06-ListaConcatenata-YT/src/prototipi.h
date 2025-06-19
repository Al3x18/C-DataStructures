struct node {
    int data;
    struct node *next;
};

void list_insert(struct node**, int);
void list_display(struct node*);
int list_search(struct node*, int);
void list_delete(struct node**, int);