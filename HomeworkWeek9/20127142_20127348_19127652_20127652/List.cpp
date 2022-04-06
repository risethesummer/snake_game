#include "List.h"

Node* getNode(int data)
{
	Node* newNode = new Node;
	if (!newNode)
		return nullptr;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}


void makeOrderedList(Node*& head, int k, bool(*compare)(int, int)) {
	Node* p = getNode(k);
	if (!head)
	{
		head = p;
		return;
	}
	if (compare(head->data, k))
	{
		p->next = head;
		head = p;
		return;
	}

	Node* before = head;
	for (Node* current = head; current; current = current->next)
	{
		if (compare(current->data, k))
		{
			before->next = p;
			p->next = current;
			return;
		}
		if (current->next == nullptr) //tail node
		{
			current->next = p;
			return;
		}
		before = current;
	}

}

ostream& operator<<(ostream& stream, Node* const head)
{
	for (Node* current = head; current; current = current->next)
		stream << current->data << "->";
	stream << "NULL";
	return stream;
}

void inputList(Node* head, bool (*compare)(int, int))
{
	int input;
	while (true)
	{
		cout << "Nhap vao so nguyen: ";
		cin >> input;
		if (input == 0)
			break;
		makeOrderedList(head, input, compare);
		cout << head << '\n';
	}
}

void freeList(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}
