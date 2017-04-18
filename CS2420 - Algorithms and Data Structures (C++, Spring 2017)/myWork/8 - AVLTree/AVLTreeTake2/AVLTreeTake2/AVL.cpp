
//AVL Tree - project 8 - 04/3/2017
//Max Nelson
//Section 002
//AVL.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: AVL.cpp

#include "AVL.h"


//precondition: none
//postcondition: creates AVL tree object
AVL::AVL()
{
	root = nullptr;
}

//precondition: AVL tree object exists
//postcondition: destructor
AVL::~AVL()
{
	eraseAll();
}

//precondition: AVL tree object exists
//postcondition: inserts a new node into the AVL Tree. insert
void AVL::insert(int val)
{
	insert(root, val);
	rebalance();
}

//precondition: AVL tree object exists
//postcondition: prints empty or it prints a tabbed AVL tree. print
void AVL::print()
{
	print(root, 0);
}

//precondition: AVL tree object exists
//postcondition: rotateRight
void AVL::rotateRight(Node* node)
{
	Node parental = *node;
	Node* firstChild = node->left;
	Node* secondChild = (firstChild == nullptr ? nullptr : firstChild->right);

	node->val = firstChild->val;
	node->left = firstChild->left;
	node->right = firstChild;

	firstChild->val = parental.val;
	firstChild->right = parental.right;
	firstChild->left = secondChild;
}

//precondition: AVL tree object exists
//postcondition: rotateLeft
void AVL::rotateLeft(Node* node)
{
	Node parent = *node;
	Node* firstChild = node->right;
	Node* secondChild = (firstChild == nullptr ? nullptr : firstChild->left);

	node->val = firstChild->val;
	node->right = firstChild->right;
	node->left = firstChild;

	firstChild->val = parent.val;
	firstChild->left = parent.left;
	firstChild->right = secondChild;
}


//precondition: AVL tree object exists
//postcondition: rebalance
void AVL::rebalance()
{
	Node* parent = unbalanced(root);
	if (parent != nullptr)
	{
		std::cout << parent->val << std::endl;
		if (heightAt(parent->left) < heightAt(parent->right))
		{
			if (heightAt(parent->right->right) > heightAt(parent->right->left))
				rotateLeft(parent);
			else
			{
				rotateRight(parent->right);
				rotateLeft(parent);
			}
		}
		else {
			if (heightAt(parent->left->left) > heightAt(parent->left->right))
				rotateRight(parent);
			else
			{
				rotateLeft(parent->left);
				rotateRight(parent);
			}
		}
	}
}

int AVL::heightAt(Node* node)
{
	if (node == nullptr) {
		return 0;
	}
	else {
		return node->height;
	}

}

//precondition: AVL tree object exists with nodes
//postcondition: erase
void AVL::eraseAll()
{
	eraseAll(root);
	root = nullptr;
}

//precondition: AVL tree object exists
//postcondition: erases all of specific number
void AVL::eraseAll(Node * node)
{
	if (node == nullptr) {
		return;
	}

	eraseAll(node->left);
	eraseAll(node->right);

	delete node;
}

//precondition: AVL tree object exists with nodes
//postcondition: inOrder
void AVL::inOrder()
{
	inOrder(root);
}

//precondition: AVL tree object exists
//postcondition: rotateRight
Node* AVL::unbalanced(Node* node)
{
	if(node == nullptr)
		return nullptr;
	else
	{
		Node* leftRet = unbalanced(node->left);
		Node* rightRet = unbalanced(node->right);

		if (abs(heightAt(node->left) - heightAt(node->right)) > 1) {
			return node;
		}
		else if (leftRet != nullptr) {
			return leftRet;
		}
		else if (rightRet != nullptr) {
			return rightRet;
		}
		else {
			return nullptr;
		}	
	}
}

//precondition: AVL tree object exists
//postcondition: insert a node into the list. insert
void AVL::insert(Node*& node, int val)
{
	if (node == nullptr) {
		node = new Node(val);
	}
	else if (val < node->val) {
		insert(node->left, val);
	}
	else if (val > node->val) {
		insert(node->right, val);
	}
	node->updateHeight();
}

//precondition: AVL tree object exists
//postcondition: print from a specific node with a specified depth/length
void AVL::print(Node* node, int depth)
{
	for (int i = 0; i < depth; i++)
		std::cout << "    ";
	if (node != nullptr) {
		bool isLeaf = (node->left == nullptr) && (node->right == nullptr);
		std::cout << node->val << " (" << node->height << ")" << (isLeaf ? " [leaf]" : "") << std::endl;
		if (!isLeaf)
		{
			print(node->left, depth + 1);
			print(node->right, depth + 1);
		}
	}
	else
	{
		std::cout << "[empty]" << std::endl;
	}
}

//precondition: AVL tree object exists with nodes
//postcondition: inOrder, specific node.
void AVL::inOrder(Node* n)
{
	if (n == nullptr) {
		return;
	}

	inOrder(n->left);
	std::cout << n->val << ' ';
	inOrder(n->right);
}