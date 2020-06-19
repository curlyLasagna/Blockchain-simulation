#pragma once

template <typename T> 
class TreeNode {
public:
	/* Attributes*/ 
	T data;
	TreeNode* left;
	TreeNode* right;
	/* Functions */
	TreeNode<T>(T data);
};

template<typename T>
inline TreeNode<T>::TreeNode(T data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

