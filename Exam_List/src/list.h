#include "item.h"

typedef struct node *list;

list newList(void);

int emptyList(list l);

list tailList(list l);

list consList(item val, list l);

item getFirst(list l);

list removeList(list l, int pos);

void outputList(list l);