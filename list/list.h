#ifndef LIST_H
#define LIST_H


struct l_node;
typedef struct l_node *ptr_l_node;
typedef ptr_l_node list;
typedef ptr_l_node position;
typedef int data_type;

list create_list();
position find(data_type X, list L);
position find_previous(data_type X, list L);
void destroy_list(list L);
void delete(data_type X, list L);
void insert(data_type X, position P);
void print(position P);


struct l_node
{
	data_type data;
	position next;
};

#endif
