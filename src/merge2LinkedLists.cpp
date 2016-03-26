/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
typedef struct node *lptr;
lptr insertend(lptr first, int x);
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *head=NULL;
	lptr p = head1, q = head2;
	if (p == NULL && q == NULL) return NULL;
	if (p == NULL&&q != NULL) return head2;
	if (p != NULL&&q == NULL) return head1;

	while (p != NULL&&q != NULL){
		if (p->num < q->num)
		{
			head = insertend(head, p->num);
			p = p->next;
		}
		else
		{
			head= insertend(head, q->num);
			q = q->next;
		}
	}
	while (p != NULL)
	{


		head= insertend(head, p->num);
		p = p->next;
	}
	while (q != NULL){
		head = insertend(head, q->num);
		q = q->next;
	}
	return head;

}
lptr insertend(lptr first, int x){
	lptr s, t;
	s = (lptr)malloc(sizeof(struct node));
	s->num = x;
	s->next = NULL;
	if (first == NULL)
	{
		first = s;
		return first;

	}
	t = first;
	while (t->next != NULL){
		t = t->next;
	}
	t->next = s;
	return first;
}
	
		