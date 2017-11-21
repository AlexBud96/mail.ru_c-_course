#ifndef TNODE_H
#define TNODE_H

#include <iostream>


template<class T>
struct TNode {
   T value;
   TNode<T> *pleft, *pright;

   //constructor
   TNode() {
      pleft = pright = NULL;
   }
};

template<class T>
void delTree(TNode<T>* p) {
   if(p != NULL) {
      delTree(p->pleft);
      delTree(p->pright);
      delete p;
   }
}

template<class T>
void makeTree(TNode<T>** pp, T key) {
   if(*pp == NULL) {
      TNode<T>* p = new TNode<T>();
      p->value = key;
      *pp = p;
   }
   else {
      if((*pp)->value > key)
         makeTree(&((*pp)->pleft), key);
      else
         makeTree(&((*pp)->pright), key);
   }
}

template<class T>
void residual(TNode<T>** first, TNode<T>* second) {
   if(second != NULL){
   		residual(first, second->pleft);
   		residual(first, second->pright);
   		delNode(first, second->value);
   }
}

template<class T>
void addTree(TNode<T>** first, TNode<T>* second) {
   if(second != NULL){
   		if(findTree(*first, second->value) == NULL){
   			makeTree(first, second->value);
   		}
   		addTree(first, second->pleft);
   		addTree(first, second->pright);
   }
}

template<class T>
void walkTree(TNode<T>* p, std::ostream& os = std::cout) {
   if(p != NULL) {
      walkTree(p->pleft);
      os << p->value << ' ';
      walkTree(p->pright);
   }
}

template<class T>
void copyTree(TNode<T>* source, TNode<T>** copy) {
   if(source != NULL) {
   	  makeTree(copy, source->value);
      copyTree(source->pleft, copy);
      copyTree(source->pright, copy);
   }
}

template<class T>
void maple(TNode<T>* p) {
	if(p != NULL) {
      maple(p->pleft);
      if(p->pleft == NULL and p->pright == NULL)
      		std::cout << p->value << ' ';
      maple(p->pright);
   }
}

template<class T>
TNode<T>* findTree(TNode<T>* p, T key){
	if(p == NULL){
		return p;
	}
	if(p->value == key){
		return p;
	}
	if(p->value > key)
		return findTree(p->pleft, key);
	else
		return findTree(p->pright, key);
}

template<class T>
TNode<T>* findParentTree(TNode<T>* p, TNode<T>* child, TNode<T>* parent = NULL){
	if(p == NULL)
		return NULL;
	if(child == p)
		return parent;
	parent = p;
	if(child->value < p->value)
		return findParentTree(p->pleft, child, parent);
	else
		return findParentTree(p->pright, child, parent);
}

template<class T>
TNode<T>* minTree(TNode<T>* p){
	while(p->pleft != NULL)
		p = p->pleft;
	return p;
}

template<class T>
void replace_successor_node(TNode<T>* parent, TNode<T>* successor, TNode<T>* child = NULL){
	if(parent != NULL){
		if(successor == parent->pleft){
			parent->pleft = child;
			delete successor;
		}
		if(successor == parent->pright){
			parent->pright = child;
			delete successor;
		}
	}
	else{
		delete successor;
	}
}

template<class T>
void delNode(TNode<T>** p, T key){
	if(*p == NULL){
		return;
	}
	TNode<T>** s = p;
	if(key < (*p)->value)
		delNodeRecursion(s, &((*p)->pleft), key);
	if(key > (*p)->value)
		delNodeRecursion(s, &((*p)->pright), key);
	if(key == (*p)->value){
		if((*p)->pleft != NULL and (*p)->pright != NULL){
			TNode<T>* successor = minTree((*p)->pright);
			(*p)->value = successor->value;
			delNodeRecursion(s, &successor, successor->value);
		}
		else{
			if((*p)->pleft != NULL){
				TNode<T>* parent = findParentTree(*s, *p);
				replace_successor_node(parent, *p, (*p)->pleft);
				*p = ((*p)->pleft);
			}
			if((*p)->pright != NULL){
				TNode<T>* parent = findParentTree(*s, *p);
				replace_successor_node(parent, *p, (*p)->pright);
				*p = ((*p)->pright);
			}
			if((*p)->pleft == NULL and (*p)->pright == NULL){
				TNode<T>* parent = findParentTree(*s, *p);
				replace_successor_node(parent, *p);
				*p = NULL;
			}
		}
	}
}

template<class T>
void delNodeRecursion(TNode<T>** s, TNode<T>** p, T key){
	if((*p) == NULL){
		return;
	}
	if(key < (*p)->value)

		delNodeRecursion(s, &((*p)->pleft), key);
	if(key > (*p)->value)
		delNodeRecursion(s, &((*p)->pright), key);
	if(key == (*p)->value){
		if((*p)->pleft != NULL and (*p)->pright != NULL){
			TNode<T>* successor = minTree((*p)->pright);
			(*p)->value = successor->value;
			delNodeRecursion(s, &successor, successor->value);
		}
		else{
			if((*p)->pleft != NULL){
				TNode<T>* parent = findParentTree(*s, *p);
				replace_successor_node(parent, *p, (*p)->pleft);
			}
			if((*p)->pright != NULL){
				TNode<T>* parent = findParentTree(*s, *p);
				replace_successor_node(parent, *p, (*p)->pright);
			}
			if((*p)->pleft == NULL and (*p)->pright == NULL){
				TNode<T>* parent = findParentTree(*s, *p); 
				replace_successor_node(parent, *p);
			}
			}
	}
}


#endif