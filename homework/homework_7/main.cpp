#include <iostream>
#include "tnode.h"
#include "tree.h"


int main()
{
	Tree<int> int_tree(9, 8, 7, 6, 5, 4, 3, 2, 1);
	Tree<double> d_tree(1.0, 36.0, 5.84, 2.18, 5.13);
	Tree<double> d2_tree(1.0, 36.0, 5.84, 2.18, 5.13, 14.5, 13.32);
	Tree<double> d3_tree(d_tree);
	std::cout << "В порядке возрастания: " << d3_tree << std::endl;
	d3_tree = d2_tree - d_tree;
	std::cout << "Вычитание: " << d3_tree << std::endl;
	d3_tree = d3_tree + d_tree;
	std::cout << "Сложение: " << d3_tree << std::endl;
	TNode<double>* found = d3_tree.findNode(36.0);
	std::cout << "Поиск по ключу: " << found->value << std::endl;
	d3_tree.deleteNode(36.0);
	d3_tree.addNode(37.0);
	std::cout << "Удаление и добавление ключа: " << d3_tree << std::endl;
	std::cout << "Листья: " << std::endl;
	d3_tree.foliage();	
	return 0;
}
