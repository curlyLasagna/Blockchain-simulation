#pragma once
#include <iostream>
#include <queue>
#include "TreeNode.h"

template <typename T>
class BinaryTree {
public:
	TreeNode<T>* root;
	BinaryTree();					// Constructor
	void add(T inputData);			// Add data to 
	void inOrder(TreeNode<T> *n); 	// Inorder search
	void bfs();						// Breadth-first search

private:
	void add(T inputData, TreeNode<T> *childNode);
	void printTraverse(TreeNode<T> *n);
};

