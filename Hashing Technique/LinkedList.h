#pragma once
#include "Node.h"
class LinkedList
{
	public:
	static void SortedInsert(Node** H, int x);
	static Node* Search(Node* p, int key);
	static Node* Delete(Node* p, int key);

};

