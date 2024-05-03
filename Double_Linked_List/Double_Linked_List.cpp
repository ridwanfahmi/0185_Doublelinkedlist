#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

Node* START = NULL;

void addNode() {
	Node* newNode = new Node();  //step 1: create a new mode
	cout << "\nEnter the roll number of the student: ";
	cin >> newNode->noMhs;       //assign value to the data field of the new node
	cout << "\nEnter the name of the student: ";
	cin >> newNode->name;        //assign value to the data field of the new node


	//insert the new node in the list
	if (START == NULL || newNode->noMhs <= START->noMhs) { //step 2 insert to the new node

		if (START != NULL && newNode->noMhs == START->noMhs) {
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
			return;
		}
		// if the list is empty, make the new node the START
		newNode->next = START;        //step 3: make the new node point to the first node
		if (START != NULL) {
			START->prev = newNode;    //step 4: make the first node point to the new node
		}
		newNode->prev = NULL;   //step 5: make the new node point to null
		START = newNode;        //step 6: make the new node the first node
	}
	else {
		//insert the new node in the middle or at the end
		Node* current = START;   //step 1.a: start from the first node
		Node* previous = NULL;   //step 1.b: previous node is null initially


		while (current != NULL && current->noMhs < newNode->noMhs) {   //step 1.c: traverse the list to find the correct possition
			previous = current;       //step 1.d: move the previous to the current node
			current = current->next;  //step 1.e: move the current to the next node
		}

		newNode->next = current;  //step 4: make the next field of the new node point
		newNode->prev = previous; //step 5: make the previous field of the new node point

		if (current != NULL) {
			current->prev = newNode;  //step 6: make the previous field of the current
		}

		if (previous != NULL) {
			previous->next = newNode;   //step 7: make the next field of the previous node
		}
		else {
			//if previous is still NULL, it means newNode is now the first node
			START = newNode;
		}
	}
}

bool search(int rollNo, Node** previous, Node** current)
{
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo)
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void deleteNode()
{
	Node* previous, *current;
	int rollNo;

	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	cin >> rollNo;

	if (START == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	current = START;
	previous = NULL;


	while (current != NULL && current->noMhs != rollNo)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
		return;
	}

	if (current == START)
	{
		START = START->next;
		if (START != NULL)
		{
			START->prev = NULL;
		}
	}
	else
	{
		previous->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = previous;
		}
	}

	delete current;
	cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b{0m" << endl;

}

bool listEmpty()
{
	return (START == NULL);
}

void traverse()
{
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else
	{
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL)
		{
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void revtraverse()
{
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else
	{
		cout << "\nRecords is descending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL)
		{
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void seacrhData()
{
	if (listEmpty() == true)
	{
		cout << "\nList is empty" << endl;
	}
	Node* prev, *curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else
	{
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}





int main()
{

}