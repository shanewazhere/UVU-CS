
//Linked List Iterator - project 7 - 03/15/2017
//Max Nelson
//Section 002
//BST.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: BST.cpp

#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

//precondition: no
//postcondition: binary tree object with root set to nullptr
BST::BST() {
    root = nullptr;
}

//precondition: BST Object exists
//postcondition: deletes every node in BST
BST::~BST() {
	if (root == nullptr) {
		return;
	} 
	DestroyHelper(root);
}

//precondition: Destructor has been called
//postcondition: deletes every node in BST
void BST::DestroyHelper(Node* n) {
	if (n == nullptr) {
		return;
	}
	else {
		DestroyHelper(n->left);
		DestroyHelper(n->right);
		delete n;
		n = nullptr;
	}
}

//precondition: BST Object exists
//postcondition: returns size
int BST::Size()
{
    // initialize counter value
    int count = 0;
    
	if (root == nullptr) {
		return count;
	}
    
    // call helper function
    return SizeHelp(root, count);
}


//precondition: size called
//postcondition: returns pre-incremented num
int BST::SizeHelp(Node* n, int& counter)
{
    if (n->left != nullptr)
    {
        SizeHelp(n->left, counter);
    }
    
    if (n->right != nullptr)
    {
        SizeHelp(n->right, counter);
    }
    return ++counter;
}

//postcondition: node exists
//precondition: checks if node is leaf
bool BST::isLeaf(Node* n)
{

		if (n->left == nullptr && n->right == nullptr) {
			return true;
		}


    return false;
}

//precondition: BST Object exists
//postcondition: prints binary search tree  with indentations
void BST::Print()
{
	if (root == nullptr) {
		return;
	}
        
    PrintHelp(root, "");
}

//precondition: Print called
//postcondition: prints binary search tree with indentations. recursivley.
void BST::PrintHelp(Node* n, string depth)
{
    cout << depth; 
    if (n == nullptr) 
        cout << "[none]" << endl;
    else if (isLeaf(n)) 
        cout << n->data << " [leaf]" << endl;
    else
    {
        cout << n->data << endl;
        PrintHelp(n->left, (depth + "    "));
        PrintHelp(n->right, (depth + "    "));
    }
    
}

//Precondition: Called when attempting to delete a node with two childeren
//Postcondition: Returns the node with minimum value
Node* BST::FindSmallest(Node* np){
    while(np->left != nullptr) {
        np = np->left;
    }
    return np;
}

//Precondition: binary search tree is balanced
//Postcondition: removes a binary search tree node with specified value
void BST::Erase(int item) {
	if (root->left == nullptr && root->right == nullptr) {
		delete root;
		root = nullptr;
		return;
	}
     EraseHelp(item, root);
}

//Precondition: Called when attempting to delete a node with two childeren
//Postcondition: Returns the node with minimum value
Node* BST::EraseHelp(int item, Node *np) {
	if (np == nullptr) {
		return np;
	}
    else if(item < np->data) 
		np->left = EraseHelp(item, np->left);
    else if(item > np->data)
		np->right = EraseHelp(item, np->right);
    else {
        if(np->left == nullptr && np->right == nullptr){
            //no child
            delete np;
            np = nullptr;
        } else if(np->left == nullptr){
            //child * 1 on the right
            struct Node *temp = np;
            np = np->right;
            delete temp;
			temp = nullptr;
        } else if(np->right == nullptr){
            //child * 1 on the left
            struct Node *temp = np;
            np = np->left;
            delete temp;
			temp = nullptr;
        } else {
            //child * 2
            struct Node *temp = FindSmallest(np->right);
            np->data = temp->data;
            np->right = EraseHelp(temp->data, np->right);
        }
    }
    return np;
}
//Precondition: Sorted binary search tree
//Postcondition: new node is created in empty binary search tree or inserthelp is called
void BST::Insert(int item) {
    // empty tree check
    if (root == nullptr)
        root = new Node(item);
    
    InsertHelp(item, root);
}

//Precondition: Insert has been called
//Postcondition: Node is inserted in the correct place within binary search tree
void BST::InsertHelp(int item, Node* n) {
    if (item < n->data)
    {
        if (n->left != nullptr) {
            //keep searching down left
            InsertHelp(item, n->left);
        }
        else  {
            //leaf
            n->left = new Node(item);
        }
        
    }
    else if (item > n->data)
    {
        if (n->right != nullptr) {
            //keep searching for position to enter down right
            InsertHelp(item, n->right);
        }
        else {
            //leaf
            n->right = new Node(item);
        }
    }
    else {
        //do not allow duplicates manneeee.
        return;
    }

}

// pre-order function implementation
//Precondition:
//Postcondition: printpreorderhelp
void BST::preOrderTraversal()
{
    if (root == nullptr) {
        return;
    }
    printPreOrderHelp(root);
}

//Precondition: postordertraversal
//Postcondition: printpostorderhelp
void BST::postOrderTraversal()
{
    if (root == nullptr) {
         return;
    }
    
    printPostOrderHelp(root);
}

//Precondition: Iinordertraversal
//Postcondition: printinorderhelp
void BST::inOrderTraversal()
{
    if (root == nullptr) {
        return;
    }
    printInOrderHelp(root);
}


//Precondition: preordertraversal
//Postcondition: preorderhelp
void BST::printPreOrderHelp(Node* n)
{
    if (n == nullptr) {
        return;
    }
    else {
        cout << n->data << endl;
        printPreOrderHelp(n->left);
        printPreOrderHelp(n->right);
    }
}

//Precondition: postordertraversal
//Postcondition: printPostOrderHelp
void BST::printPostOrderHelp(Node* n)
{
    if (n == nullptr) {
         return;
    }
    else {
        printPostOrderHelp(n->left);
        printPostOrderHelp(n->right);
        cout << n->data << endl;
    }
}

//Precondition: inordertraversal
//Postcondition: printInOrderHelp
void BST::printInOrderHelp(Node* n)
{
    if (n == nullptr) {
        return;
    }
    else {
        printInOrderHelp(n->left);
        cout << n->data << endl;
        printInOrderHelp(n->right);
    }
}


