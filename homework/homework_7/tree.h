#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "tnode.h"


template<class T>
class Tree{
public:
	TNode<T>* get_root(){
		return root;
	};
	Tree();
	Tree(const Tree& source);
	template<class... Args>
	Tree(Args... arg);
	Tree(TNode<T>* const& source);
	~Tree();
	template<typename... Args>
	void addNode(T value, Args... arg);
	void addNode(T value);
	void deleteNode(T key);
	TNode<T>* findNode(T key);
	void foliage();
	const Tree<T>& operator = (const Tree<T>& other);
	const Tree<T> operator - (const Tree<T>& other);
	const Tree<T> operator + (const Tree<T>& other);
	template <typename U>
	friend std::ostream& operator << (std::ostream& os, Tree<U>& p);
private:
	TNode<T>* root;
};

template<class T>
Tree<T>::Tree():root(NULL){
}

template<class T>
template<class... Args>
Tree<T>::Tree(Args... arg):root(NULL){
	addNode(arg...);
}

template<class T>
Tree<T>::Tree(TNode<T>* const& source):root(NULL){
	copyTree(source, &root);
}

template<class T>
Tree<T>::Tree(const Tree<T>& source):root(NULL){
	copyTree(source.root, &root);
}

template <class T>
void Tree<T>::addNode(T key){
	makeTree(&root, key);
};

template <class T>
TNode<T>* Tree<T>::findNode(T key){
	return findTree(root, key);
};

template <class T>
void Tree<T>::deleteNode(T key){
	delNode(&root, key);
};

template <class T>
void Tree<T>::foliage(){
	maple(root);
};

template<class T>
template<class... Args>
void Tree<T>::addNode(T key, Args... arg)
{
	makeTree(&root, key);
	addNode(arg...);
};

template<class T>
Tree<T>::~Tree(){
	delTree(root);
}

template<class T>
const Tree<T>& Tree<T>::operator = (const Tree<T>& other){
	delTree(root);
	root = NULL;
	copyTree(other.root, &root);
	return *this;
};

template<class T>
const Tree<T> Tree<T>::operator - (const Tree<T>& other){
	TNode<T>* temp = NULL;
	copyTree(root, &temp);
	residual(&temp, other.root);
	Tree<T> rez(temp);
	delTree(temp);
	return rez;
}

template<class T>
const Tree<T> Tree<T>::operator + (const Tree<T>& other){
	TNode<T>* temp = NULL;
	copyTree(root, &temp);
	addTree(&temp, other.root);
	Tree<T> rez(temp);
	delTree(temp);
	return rez;
}

template<class T>
std::ostream& operator << (std::ostream& os, Tree<T>& p){
	walkTree(p.root, os);
	return os;
};

# endif