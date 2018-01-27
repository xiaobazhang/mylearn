/**
 * Created by suli on 18/1/20.
 */

#include <iostream>

template<typename T>
struct Node {
	Node(T data) : next(NULL) {
		value = data;
	}
	T value;
	Node *next; //单向链表
};

//链表反向
template<typename T>
bool InvertList(Node<T> *src, Node<T> *des) {
	if (src == NULL) {
		return false;
	}
	Node<T> *next;
	Node<T> *prev = NULL;
	while (src != NULL) {
		next = src->next;
		src->next = des;
		des = src;
		src = next;
	}
	return true;
}

int main(void) {
	Node<int> *src = NULL;
	Node<int> *des = NULL;
	for (int i = 0; i < 10; i++) {
		Node<int> *node = new Node<int>(i + 1);
		std::cout << "new " << std::endl;
		if (src == NULL) {
			src = node;
			continue;
		}
		src->next = node;
		std::cout << "insert value=" << node->value << "," << std::endl;
	}

	//InvertList<int>(src,des);
	Node<int> *tmp = src;
	while (tmp->next) {
		std::cout << "InvertList value=" << tmp->value << ",";
		tmp = tmp->next;
	}

	//你自己看能不能写一个把链表内存释放掉

	return 1;
}