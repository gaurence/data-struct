/*
 * Implement the stack by list.
 */
#include <stdlib.h>
#include "stack.h"
#include "error.h"


stack
create_stack()
{
	stack S;

	S = (ptr_s_node)malloc(sizeof(struct s_node));
	if (S == NULL)
		fatal_error("Out of space!");
	S->next = NULL;

	return S;
}

void
destroy_stack(stack S)
{
	ptr_s_node tmp;
	while (S->next != NULL) {
		tmp = S->next;
		S->next = S->next->next;
		free(tmp);
	}
	free(S);

}

void
push(data_type X, stack S)
{
	ptr_s_node tmp;

	tmp = (ptr_s_node)malloc(sizeof(struct s_node));
	if (tmp == NULL)
		fatal_error("Out of space!");
	else {
		tmp->data = X;
		tmp->next = S->next;
		S->next = tmp;
	}
}

data_type
pop(stack S)
{
	data_type X;
	ptr_s_node tmp;

	if (S->next == NULL)
		error("Empty stack!");
	else {
		tmp = S->next;
		X = tmp->data;
		S->next = S->next->next;
		free(tmp);

		return X;
	}
}
