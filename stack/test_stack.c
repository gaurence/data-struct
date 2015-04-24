#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "stack.h"

#define NUM 5

int
main()
{
	int i; /* for loop */
	int tmp;
	stack S;

	S = create_stack();
	printf("Please keyin %d data: ", NUM);
	for (i = 0; i < NUM; i++) {
		scanf("%d", &tmp);
		push(tmp, S);
	}

	printf("You have keyin: ");
	for (i = 0; i < NUM; i++) {
		tmp = pop(S);
		printf("%d\t", tmp);
	}
	printf("\n");
	destroy_stack(S);

	return 0;
}
