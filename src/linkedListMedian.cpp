/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node*lptr;
int linkedListMedian(struct node *head) {
	int k = 0,j=0,m=0;
	lptr p = head;
	if (p == NULL) return -1;
	while (p != NULL){
		k++;
		p=p->next;
	}
	 p = head;
	if (k%2==0){
		while (p!=NULL)
		{  
			j++;
			if (j == k / 2 || j == k / 2 + 1)
				m = m + p->num;
			p = p->next;
                 
		}
		return m / 2;
	}
	else{
		while (p != NULL)
		{
			j++;
			if ( j == k / 2 + 1)
				m = m + p->num;

			p = p->next;

		}
		return m;
	}



}
