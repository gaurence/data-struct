#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "error.h"


list
create_list()
{
	list L;
	L = (ptr_l_node)malloc(sizeof(struct l_node));
	L->next = NULL;

	return L;
}

void
destroy_list(list L)
{
	list tmp;

	while (L->next != NULL) {
		tmp = L->next;
		L->next = L->next->next;
		free(tmp);
	}
	free(L);
}

/* Return the position of X if found, or return NULL */
position
find(data_type X, list L)
{
	position P;

	P = L->next;
	while (P != NULL && P->data != X) {
		P = P->next;
	}

	if (P == NULL)
		return NULL;
	else
		return P;
}

/* Return the position of X if found, or return NULL */
position
find_previous(data_type X, list L)
{
	position P;

	P = L;
	while (P->next != NULL && P->next->data != X) {
		P = P->next;
	}

	if (P->next == NULL)
		return NULL;
	else
		return P;
}

void
delete(data_type X, list L)
{
	position P;
	position tmp;

	P = find_previous(X, L);
	if (P == NULL || P->next == NULL)
		error("Not found!");
	else {
		tmp = P->next;
		P->next = P->next->next;
		free(tmp);
	}
}

/* insert after P */
void
insert(data_type X, position P)
{
	position Q;

	Q = (ptr_l_node)malloc(sizeof(struct l_node));
	if (Q == NULL)
		fatal_error("Out of space!");
	else {
		Q->data = X;
		Q->next = P->next;
		P->next = Q;
		}
}

void
print(position P)
{
	while (P != NULL) {
		fprintf(stdout, "%d\t", P->data);
		P = P->next;
	}
	printf("\n");
}
