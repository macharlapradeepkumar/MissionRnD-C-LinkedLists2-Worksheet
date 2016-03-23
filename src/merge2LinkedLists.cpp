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
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	lptr p = head1, q = head2, j, r=head1;
	if (p == NULL && q == NULL) return NULL;
	if (p == NULL&&q != NULL) return head2;
	if (p != NULL&&q == NULL) return head1;
	while (p != NULL&&q != NULL){
		if (p->num <= q->num){
			r = p;
			p = p->next;
		}
		else{
			j = (lptr)malloc(sizeof(struct node));
			j->num = q->num;
			j->next = p;
			r->next = j;
			q = q->next;
		}
	}
	while (q != NULL){
	  j = (lptr)malloc(sizeof(struct node));
		j->num = q->num;
		j->next = NULL;
		r->next = j;
		r = r->next;
		q = q->next;
	}
	return head1;
}
