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
	
}


int main()
{

}