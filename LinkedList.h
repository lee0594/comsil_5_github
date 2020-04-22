#include<string>
#include<iostream>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T> *link;
	Node(T element) {
		data = element;
		link = 0;
	}
};
template<class T>
class LinkedList
{protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList<T>(){
		first = 0;
		current_size = 0;
	}
	int GetSize()
	{
		return current_size;
	}
	void Insert(T element);
	virtual bool Delete(T &element);
	void Print();
};
template<class T>
void LinkedList<T>::Insert(T element)
{
	Node<T> *newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}
template<class T>
bool LinkedList<T>::Delete(T &element) {
	if (first == 0)
	{
		return false;
	}
	Node<T> *current =first, *previous = 0;
	while (1)
	{ 
		if (current->link == 0)
		{
			if (previous)
				previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;
	return true;
}
template<class T>
void LinkedList<T>::Print()
{
	Node<T> *tmp = first;
	if (!tmp)
		return;
	current_size = 1;
	while (1)
	{
		if (tmp->link == 0)
		{
			cout << "[" << current_size << "|" << tmp->data << "]" << endl;
			break;
		}
		else
		{
			cout << "[" << current_size << "|" << tmp->data << "]" << "->";
			tmp = tmp->link;
			current_size++;
		}
	}
}
