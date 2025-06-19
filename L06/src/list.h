#include "item.h"

typedef struct node *list;

list newList(void);

int emptyList(list l);

list tailList(list l);

list consList(item i, list l);

item getFirst(list l);

int sizeList(list l);

int posItem(item i, list l);

item getItem(int pos, list l);

list reverseList(list l);

void outputList(list l);

list inputList(int n);