#ifndef QUEUE_H
#define QUEUE_H

struct q_node;
struct queue;
typedef struct q_node *ptr_q_node;
typedef struct queue  *link_queue;
typedef int data_type;

void create_queue(link_queue Q);
void destroy_queue(link_queue Q);
void enqueue(data_type X, link_queue Q);
data_type dequeue(link_queue Q);


struct q_node {
	data_type data;
	ptr_q_node next;
};

struct queue {
	ptr_q_node front;
	ptr_q_node rear;
};

#endif
