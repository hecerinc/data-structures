#include <iostream>

void sortedLinkMerge(Node * a, Node * b) {
	if(a == NULL || b == NULL) {
		return;
	}
	
	Node *p, *q, *r, *m;
	int alen = 0;
	p = a;
	while(p != NULL) {
		p = p->next;
		alen++;
	}
	if(a->data < b->data) {
		r = a;
		p = r->next;
		q = b;
	}
	else {
		r = b;
		q = r->next;
		p = a;
	}
	m = r;
	while(p != NULL && q != NULL) {
		if(p->data < q->data) {
			m->next = p;
			p = p->next;
		}
		else {
			m->next = q;
			q = q->next;
		}
		m = m->next;
	}
	while(p != NULL) {
		m->next = p;
		p = p->next;
		m = m->next;
	}
	while(q != NULL) {
		m->next = q;
		q = q->next;
		m = m->next;
	}
	p = r;
	alen--;
	while(alen--) {
		p = p->next;
	}
	a = r;
	b = p->next;
	p->next = NULL; // end the first list
	m = q = p = r = NULL;

}

int main() {

}