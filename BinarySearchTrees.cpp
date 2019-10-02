//Binary Search Tree
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
};

class BST {
private:
	Node* root;
	Node* insert(int, Node*); //helper
	int getSize(Node*); //helper
	void displayInOrder(Node*); //helper
	//  void deleteNode(int, Node*); // helper
public:
	BST();
	void insert(int);
	void displayInOrder();
	int getSize();
	int maxValue();
	Node* find(int);
	// void deleteNode(int); 
	void load(int, int, int);
}; //BST class

//helper functions
Node* BST::insert(int v, Node* r) { // "r" is short for "root"
	if (r == nullptr) {
		r = new Node;
		r->left = r->right = nullptr;
		r->data = v;
		return r;
	}
	else if (v < r->data) {
		r->left = insert(v, r->left);
		return r;
	}
	else {
		r->right = insert(v, r->right); // r->right is assigned the new node that will be created to the right
		return r;
	}
} //insert helper

void BST::displayInOrder(Node* r) {
	if (r != nullptr)
	{
		displayInOrder(r->left);
		cout << r->data << endl;
		displayInOrder(r->right);
	}
} //displayInOrder helper

int BST::getSize(Node* r) {
	if (r == nullptr)
		return 0;
	else
		return 1 + getSize(r->left) + getSize(r->right);
} //getSize helper

//constructors
BST::BST() {
	root = nullptr;
} //BST

//setters
void BST::insert(int v) {
	root = insert(v, root);
} //insert

void BST::load(int howMany, int minVal, int maxVal) {
	insert(minVal);
	insert(maxVal);
	howMany--;
	howMany--; 
	if (howMany != 0) {
		while (howMany != 0) {
			insert(((rand() % (maxVal - minVal + 1)) + minVal));
			howMany--;
		}
	}
}

//getters
int BST::getSize() {
	return getSize(root);
} //getSize

//loaders


//utility
void BST::displayInOrder() {
	displayInOrder(root);
} //displayIn

int BST::maxValue() {
	Node* r = root;
	Node* parent = r;
	while (r != nullptr) {
		parent = r;
		r = r->right;
	}
	int target = parent->data;
	return target; 
}

Node* BST::find(int v) { 
	Node* r = root;
	while (r != nullptr) {
		if (r->data == v)
			return r; 
		else if (v > r->data)
			r = r->right;
		else if (v < r->data)
			r = r->left;
	}
	cout << v << " is not in this BST!" << endl; 
	return nullptr; 
}

int main() {
	BST bst1 = BST();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(20);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(10);
	bst1.insert(30);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(5);
	bst1.insert(40);
	bst1.insert(25);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(0);
	bst1.insert(2);
	bst1.insert(-5);
	bst1.insert(-2);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	cout << "test of getMax()" << endl;
	cout << "first, display in order: " << endl << endl;
	bst1.displayInOrder();
	cout << endl << endl;
	cout << "the max value of this BST is: " << bst1.maxValue() << endl; 

	int findTarget = 40;
	cout << "test find(" << findTarget << ") " << endl;
	Node* testPtr = bst1.find(findTarget);
	cout << "found: " << testPtr->data; 

	cout << "test void load(int, int, int) " << endl << endl;
	BST bst2 = BST();
	bst2.load(5, 2, 9);
	bst2.displayInOrder();


} //main


