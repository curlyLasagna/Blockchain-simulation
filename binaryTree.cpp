#include "binaryTree.h"

template<typename T>
inline BinaryTree<T>::BinaryTree() {
	root = nullptr;
}

template<typename T>
inline void BinaryTree<T>::add(T inputData) {
	if (root == nullptr) {
		TreeNode<T>* node = new TreeNode<T>(inputData);
		node->data = inputData; 
		root = node; 
	}
	else
		add(inputData, root);
}

template<typename T>
inline void BinaryTree<T>::add(T inputData, TreeNode<T> *childNode) {
	if (inputData.getNonce() < childNode->data.getNonce()) {
		if (childNode->left == nullptr) {
			TreeNode<T>* node = new TreeNode<T>(inputData);
			node->data = inputData;
			childNode->left = node;
		}
		else 
			add(inputData, childNode->left);
	}

	else
		if (childNode->right == nullptr) {
			TreeNode<T>* node = new TreeNode<T>(inputData);
			node->data = inputData;
			childNode->right = node;
		}
		else
			add(inputData, childNode->right);
}

template<typename T>
inline void BinaryTree<T>::printTraverse(TreeNode<T> *n) {
	std::cout 
		<< "ID: " << n->data.getID() << std::endl
		<< "Nonce: " << n->data.getNonce() << std::endl
		<< "Hash: " << n->data.getHash() << std::endl;
}

template<typename T>
inline void BinaryTree<T>::inOrder(TreeNode<T> *n) {
	if(n != nullptr) {
		inOrder(n->left);	
		printTraverse(n);
		inOrder(n->right);
	}
}

template<typename T>
inline void BinaryTree<T>::bfs() {
	std::queue<TreeNode<T>*> q;	
	TreeNode<T> *r = root;
	if(r != nullptr) {
		q.push(r);
		while(!q.empty()) {
			r = q.front();	
			printTraverse(r);
			q.pop();

			if(r->left != nullptr)
				q.push(r->left);
			if(r->right != nullptr)
				q.push(r->right);
		}
	}
}
