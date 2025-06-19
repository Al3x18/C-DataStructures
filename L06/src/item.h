/* per semplicità in questo es.  
   il nostro tipo item è l’insieme 
   degli interi positivi 
   NULLITEM è un elemento che 
   viene restituito quando la 
   precondizione di getFirst
   viene violata */


#define NULLITEM 0

typedef int item;

int eq(item x, item y);

void input_item(item *x);

void output_item(item x);