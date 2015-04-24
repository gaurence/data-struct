#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define NUM 5


int
main()
{
	int i; /* for loop */
	int tmp;
	link_queue Q;

	Q = (link_queue)malloc(sizeof(struct queue));
	create_queue(Q);
	printf("Please keyin %d num: ", NUM);
	for (i = 0; i < NUM; i++) {
		scanf("%d", &tmp);
		enqueue(tmp, Q);
	}
	printf("You have keyin: ");
	for (i = 0; i < NUM; i++) {
		tmp = dequeue(Q);
		printf("%d\t", tmp);
	}
	printf("\n");
	destroy_queue(Q);
	free(Q);

	return 0;
}
