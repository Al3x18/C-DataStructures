typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
} node;

node* createBST();
node* search(node* T, int key);
void insert(node** T, int new_key);
void del_node(node** T, int delete_key);
node* findMin(node* root);