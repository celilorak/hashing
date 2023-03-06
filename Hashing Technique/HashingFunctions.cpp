#include "HashingFunctions.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;
#include <iostream>
#include <cstddef>


int HashingFunctions::hashChaning(int key)
{
	return key % 10;
}

void HashingFunctions::InsertChaning(Node* H[], int key)
{
	int index = hashChaning(key);
	LinkedList::SortedInsert(&H[index], key);
}

void HashingFunctions::SearchChaning(Node* H[], int key) {
	Node *temp = new Node;
	int index = hashChaning(key);
	temp=LinkedList::Search(H[index], key);

	if (temp != NULL) {
		cout << "key is found and the value is ";
		cout << temp->data;
		cout << endl;
	}
	else {
		cout << "key is not found.";
		cout << endl;
	}

}

void HashingFunctions::DeleteChaning(Node* H[], int key) {
	Node* temp = NULL;
	int index = hashChaning(key);
	H[index] = LinkedList::Delete(H[index], key);

}

int HashingFunctions::hashLP(int key) {
	return key % 10;
	/*Linear Probing*/
}

int HashingFunctions::probeLP(int H[], int key, int size) {
	int index = hashLP(key);
	int i = 0;
	while (H[(index + i) % size] != 0)
		i++;
	return (index+i)%size;
}

void HashingFunctions::InsertLP(int H[], int key, int size) {
	int index = hashLP(key);
	if (H[index] != 0)
		index = probeLP(H, key, size);
	H[index] = key;

}

int HashingFunctions::SearchLP(int H[], int key, int size) {
	int i = 0;
	int index = hashLP(key);
	while (H[(index + i) % size] != key ) {
		i++;
		if (H[(index + i) % size] == 0)
			return -1;
	}

		return (index + i) % size;

}

int HashingFunctions::hashQP(int key) {
	return key % 10;
	/*Quadratic Probing*/
}

int HashingFunctions::probeQP(int H[], int key, int size) {
	int index = hashQP(key);
	int i = 0;
	while (H[(index + i*i) % size] != 0)
		i++;
	return (index + i*i) % size;
}

void HashingFunctions::InsertQP(int H[], int key, int size) {
	int index = hashQP(key);
	if (H[index] != 0)
		index = probeQP(H, key, size);
	H[index] = key;

}

int HashingFunctions::SearchQP(int H[], int key, int size) {
	int i = 0;
	int index = hashQP(key);
	while (H[(index + i*i) % size] != key ) {
		i++;
		if (H[(index + i*i) % size] == 0)
			return -1;
	}


		return (index + i*i) % size;

}

int HashingFunctions::hashDH(int key) {
	return key % 10;
	/*Double Hashing*/
}

int HashingFunctions::prime(int key) {
	int prime = 7;
	return  prime - (key % prime);
}

int HashingFunctions::doublehash(int H[], int key, int size) {
	int index = hashDH(key);
	int i = 0;
	while (H[(index + i * prime(key)) % size] != 0)
		i++;
	return (index + i * prime(key)) % size;
}

void HashingFunctions::InsertDH(int H[], int key, int size) {
	int index = hashDH(key);
	if (H[index] != 0)
		index = doublehash(H, key, size);
	H[index] = key;

}

int HashingFunctions::SearchDH(int H[], int key, int size) {
	int i = 0;
	int index = hashDH(key);
	while (H[(index + i * prime(key)) % size] != key ) {
		i++;
		if (H[(index + i * prime(key)) % size] == 0)
			return -1;
	}

		return (index + i * prime(key)) % size;

}
