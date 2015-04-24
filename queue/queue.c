#include <stdlib.h>
#include "queue.h"
#include "error.h"


void
create_queue(link_queue Q)
{
	ptr_q_node tmp;

	tmp = (ptr_q_node)malloc(sizeof(struct q_node));
	if (tmp == NULL)
		fatal_error("Out of space!");
	else { 				//A head q_node.
		Q->front = tmp;
		Q->rear = tmp;
		Q->front->next = NULL;
	}
}

void
destroy_queue(link_queue Q)
{
	ptr_q_node tmp;

	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}

}

void
enqueue(data_type X, link_queue Q)
{
	ptr_q_node tmp;

	tmp = (ptr_q_node)malloc(sizeof(struct q_node));
	if (tmp == NULL)
		fatal_error("Out of space!");
	else {
		tmp->data = X;
		tmp->next = NULL;
		Q->rear->next = tmp;
		Q->rear = tmp;

	}
}

data_type
dequeue(link_queue Q)
{
	ptr_q_node tmp;
	data_type data;

	if (Q->front == Q->rear)
		error("Empty queue!");
	tmp = Q->front->next;
	Q->front->next = tmp->next;
	if (Q->rear == tmp)
		Q->rear = Q->front;

	data = tmp->data;
	free(tmp);

	return data;
}
