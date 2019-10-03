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
	Node* insert(int, Node*); // helper
	int getSize(Node*); // helper
	void displayInOrder(Node*); // helper
	void displayPreOrder(Node*); // helper
	//  void deleteNode(int, Node*); // helper
	void display(Node*, int); // display helper
public:
	BST();
	void insert(int);
	void displayInOrder();
	int getSize();
	int maxValue();
	Node* find(int);
	void deleteNode(int); 
	void load(int, int, int);
	int returnRoot();
	void displayPreOrder(); 
	void display(); 
}; //BST class

//helper functions
Node* BST::insert(int v, Node* r) { 
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
	if (r != nullptr) {
		displayInOrder(r->left);
		cout << r->data << endl;
		displayInOrder(r->right);
	}
} //displayInOrder helper

int BST::getSize(Node* r) {
	if (r == nullptr) return 0;
	else return 1 + getSize(r->left) + getSize(r->right);
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
	if (root == nullptr) {
		int newRoot = (minVal + maxVal) / 2;
		insert(newRoot);
	}
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

void BST::deleteNode(int v) {
	Node* target = root;
	Node* parent = nullptr;

	// find node
	while (target != nullptr) {
		if (v > target->data) {
			parent = target;
			target = target->right;
		}
		else if (v < target->data) {
			parent = target;
			target = target->left;
		}
		else {
			if (target->left == nullptr && target->right == nullptr) { //delete leaf Node
				if (parent->left == target) parent->left = nullptr;
				else parent->right = nullptr;
				return;
			}
			else if (target->left == nullptr || target->right == nullptr) { //delete node w/ one child
				if (target->left == nullptr) parent->left = target->right;
				else if (target->right == nullptr) parent->right = target->left;
			}
			else { // delete node that has two children
				Node* runner = target->right;
				while (runner->left != nullptr) runner = runner->left;
				target->data = runner->data;
			}
			return;
		}
	}
}


void BST::displayPreOrder(Node* r) {
	if (root == nullptr)
	{
		cout << "ERROR: Tree does not exist" << endl;
		return;
	}
	if (r != nullptr)
	{
		cout << r->data << "  " << endl;
		displayPreOrder(r->left);
		displayPreOrder(r->right);
	}
}

void BST::displayPreOrder() {
	displayPreOrder(root);
}

void BST::display(Node* ptr, int level)
{
	if (ptr != nullptr)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->:  ";
		else
		{
			for (int i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
} // display helper

void BST::display() {
	display(root, 1);
}


int BST::returnRoot() {
	return root->data; 
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

	bst1.display();
	cout << endl << "size is: " << bst1.getSize();

	cout << endl << "test void load(4, 2, 8) " << endl << endl;
	bst1.load(4, 2, 8);

	bst1.display(); 

	cout << endl << "new size is: " << bst1.getSize();

	cout << "test load(int,int,int) with an empty BST " << endl;
	BST bst2 = BST();
	bst2.load(4, 1, 10);
	bst2.display();

	cout << endl << endl << "test deleteNode " << endl;
	cout << "display before" << endl;
	bst1.display();
	bst1.deleteNode(20); 
	cout << endl << endl << "display after " << endl;
	bst1.display();

} //main


