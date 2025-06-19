#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    int priority;
} queue_item;

typedef struct {
    queue_item items[MAX_QUEUE_SIZE];
    int queue_size;
} PQueue;

void enqueue(PQueue *q, int data, int priority);
int extract(PQueue *q, int data);
void print_queue(PQueue *q);
void dai_priorita(PQueue *q);
void order_by_priority(PQueue *q);