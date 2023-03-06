#include "LinkedList.h"
#include "Node.h"
#include <cstddef>
using namespace std;
#include <iostream>


void LinkedList::SortedInsert(Node** H, int x)
{
	Node* t = NULL;
	Node* q = NULL;
	Node* p = *H;
	Node* temp = NULL;

	t = new Node;
	t->data = x;
	t->next = NULL;

	if (*H == NULL)
		*H = t;
	else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == NULL) {
			q->next = t;
		}
		else {
			temp = q->next;
			q->next = t;
			t->next = temp;
		}
	}

}

Node* LinkedList::Search(Node* p, int key) {
	while (p != NULL) {
		if (key == p->data)
			return p;
		else if (key > p->data)
			p = p->next;
		else
			return NULL;
	}
	return NULL;

}

Node* LinkedList::Delete(Node* p, int key) {
	Node* first = p;
	Node* temp = LinkedList::Search(p, key);
	Node* q = NULL;
	if (temp != NULL) {
		if (p->data == key) {
			q = p->next;
			delete p;
			cout << "The deleted key is ";
			cout << key;
			return q;
		}
		else {
			while (p->data < key) {
				q = p;
				p = p->next;
			}
			q->next = p->next;
			delete p;
			cout << "The deleted key is ";
			cout << key;
			return first;
		}



	}
	else
		cout << "There is no such key found to be deleted.";
		cout << endl;
		return first;
}
