#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;

		Node(T _data, Node<T>* _next=nullptr){
			data=_data;
			next=_next;
		}
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node.data;
        		return out;
		}




};
#endif
