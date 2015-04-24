#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define NUM 5	//The num of the list.

int
main()
{
	int i; /* For loop */
	int tmp;
	list L;
	position P;
	position Q;

	L = create_list();

	while (1) {
		printf("Please keyin a num to select operation:\n");
		printf(" 1.Insert\n 2.Find\n 3.Delete\n 4.Print\n 5.Quit\n");
		scanf("%d", &tmp);
		if (!(tmp >= 1 && tmp <= 5))
			continue;
		switch(tmp) {

			case 1:
				printf("Please input %d num to the list:\n", NUM);
				Q = L;
				for (i = 0; i < NUM; ++i) {
					scanf("%d", &tmp);
					insert(tmp, Q);
					Q = Q->next;
				}
				print(L->next);
				break;

			case 2: {
				printf("Please input the value that you want to find: ");
				scanf("%d", &tmp);
				if (P = find(tmp, L))
					printf("Found!\nIt's %d.\n", P->data);
				else
					printf("Don't find!\n");
				} break;

			case 3: {
				printf("Please input the value that you want to delete: ");
				scanf("%d", &tmp);
				delete(tmp, L);
				printf("Successfully delete!\n");
				} break;

			case 4: print(L->next); break;

			case 5:
				exit(0);

			default:
				printf("Please key num 1-5!"); break;
		}
	}
	destroy_list(L);

	return 0;
}


