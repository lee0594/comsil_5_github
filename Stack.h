#include"LinkedList.h"

template<class T>
class Stack : public LinkedList<T>
{
public:
	virtual bool Delete(T &element);
};
template<class T>
bool Stack<T>::Delete(T &element)
{
	if (this->first == 0)
	{
		return false;
	}
	Node<T> *current = this->first;
	this->current_size--;
	this->first = this->first->link;
	element = current->data;
	current->link = NULL;
	delete current;

	return true;
}
