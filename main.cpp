#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//
template<typename T>
class List
{
public:
	List();
	~List();
	void Push_up(T data);
	void Pop_down();
	void Cleaning();
	int GetSize() { return Size; }

	T& operator[](const int index);
private:


	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data, Node* pNext=nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
}
template<typename T>
void List<T>::Push_up(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}
template<typename T>
void List<T>::Pop_down()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T>
void List<T>::Cleaning()
{
	while (Size) {
		Pop_down();
	}
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0; // schetchic
	Node<T>* current = this->head;
	while (current !=nullptr)
	{
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}
//

int main() {
	List<int> lst;
	
	for (int i = 0; i < 10; i++)
	{
		lst.Push_up(i+1);//добавление элемента
	}
	cout << lst.GetSize() << endl;//вывод размера
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i];
	}
	lst.Pop_down();//удаление 1-го элемента
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i];
	}
	cout << endl;
	lst.Cleaning();
	cout << lst.GetSize();
	system("pause");
	return 0;
}
