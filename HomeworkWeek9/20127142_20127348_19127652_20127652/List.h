#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* getNode(int data);
void makeOrderedList(Node*& head, int k, bool(*compare)(int, int));
ostream& operator<<(ostream&, Node* const head);
void inputList(Node* head, bool(*compare)(int, int));
void freeList(Node* head);

#endif