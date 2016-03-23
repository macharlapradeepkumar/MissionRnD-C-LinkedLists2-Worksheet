/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node *lptr;
struct node * reverseLinkedList(struct node *head) {
	lptr p = head, t = NULL,q=NULL,s=NULL;
	if (p == NULL) return NULL;
	int l = 0,i=1;
	while (p != NULL){
		l++;
		p = p->next;
	}
	p = head;
	t = head;
	while (i <= l / 2){
		
     while (p != s){
			q = p;
		p=p->next;
		}
		s = q;
		int temp = t->num;
		t->num = q->num;
		q->num = temp;
		t = t->next;
		p = t;
		i++;
	}
	return head;
}
