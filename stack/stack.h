#ifndef STACK_H
#define STACK_H


struct s_node;
typedef struct s_node *ptr_s_node;
typedef ptr_s_node stack;
typedef int data_type;

stack create_stack();
void destroy_stack(stack S);
void push(data_type X, stack S);
data_type pop(stack S);


struct s_node
{
	data_type	data;
	ptr_s_node	next;
};

#endif
