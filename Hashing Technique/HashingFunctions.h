#pragma once
#include "LinkedList.h"
class HashingFunctions
{
public:
	static int hashChaning(int key);
	static void InsertChaning(Node* H[], int key);
	static void SearchChaning(Node* H[], int key);
	static void DeleteChaning(Node* H[], int key);
	static int hashLP(int key);
	static int probeLP(int H[], int key, int size);
	static void InsertLP(int H[], int key, int size);
	static int SearchLP(int H[], int key, int size);
	static int hashQP(int key);
	static int probeQP(int H[], int key, int size);
	static void InsertQP(int H[], int key, int size);
	static int SearchQP(int H[], int key, int size);
	static int hashDH(int key);
	static int prime(int key);
	static int doublehash(int H[], int key, int size);
	static void InsertDH(int H[], int key, int size);
	static int SearchDH(int H[], int key, int size);

};

