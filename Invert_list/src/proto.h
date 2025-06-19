typedef struct list {
    int data;
    struct list *next;
} list;

void add_element(list **l, int data);
void print_list(list *l);
void invert_list(list **l);
void invert_extremes(list **l);
void print_pointer(list *l);