
//Linked List Iterator - project 7 - 03/15/2017
//Max Nelson
//Section 002
//BST.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: BST.h

#include <stdio.h>
#include "Node.h"
#include <string>
using namespace std;

class BST {
    private:
    Node* root;
    
    public:
    //precondition: no
    //postcondition: binary tree object with root set to nullptr
    BST();
    
    //precondition: BST Object exists
    //postcondition: deletes every node in BST
    ~BST();
    
    //precondition: Destructor has been called
    //postcondition: deletes every node in BST
    void DestroyHelper(Node* n);
    
    //precondition: BST Object exists
    //postcondition: returns size
    int Size();
    
    //precondition: size called
    //postcondition: returns pre-incremented num
    int SizeHelp(Node* n, int& counter);
    
    //postcondition: node exists
    //precondition: checks if node is leaf
     bool isLeaf(Node* n);
    
    //precondition: BST Object exists
    //postcondition: prints binary search tree  with indentations
    void Print();
    
    //precondition: Print called
    //postcondition: prints binary search tree with indentations. recursivley.
    void PrintHelp(Node* n, string depth);
    
    //Precondition: Called when attempting to delete a node with two childeren
    //Postcondition: Returns the node with minimum value
    Node* FindSmallest(Node* np);

    //Precondition: binary search tree is balanced
    //Postcondition: removes a binary search tree node with specified value
    void Erase(int item);
    
    //Precondition: Called when attempting to delete a node with two childeren
    //Postcondition: Returns the node with minimum value
    Node* EraseHelp(int item, Node* np);
    
    //Precondition: Sorted binary search tree
    //Postcondition: new node is created in empty binary search tree or inserthelp is called
    void Insert(int item);
    
    //Precondition: Insert has been called
    //Postcondition: Node is inserted in the correct place within binary search tree
    void InsertHelp(int item, Node* np);
    
    
    void inOrderTraversal();
    void printInOrderHelp(Node* n);
    
    void preOrderTraversal();
    void printPreOrderHelp(Node* n);
 
    void postOrderTraversal();
    void printPostOrderHelp(Node* n);

    
    
};
