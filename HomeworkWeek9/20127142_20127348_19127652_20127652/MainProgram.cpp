#include <iostream>
#include "List.h"

using namespace std;

bool compareAGreaterB(int a, int b)
{
	return a < b;
}

bool compareALessB(int a, int b)
{
	return a > b;
}


int main()
{
	//1. danh sach tang dan
	Node* head = nullptr;
	cout << "1. danh sach tang dan\n";
	inputList(head, compareAGreaterB);
	freeList(head);
	head = nullptr;
	cout << "\n\n\n";

	//2. danh sach giam dan
	cout << "2. danh sach giam dan\n";
	inputList(head, compareALessB);
	freeList(head);

	return 1;
}