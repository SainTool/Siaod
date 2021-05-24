#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//
class List
{
public:
	List();
	~List();
	void Push_up(int data);
	void Pop_down();
	void Cleaning();
	int GetSize() { return Size; }

	int& operator[](const int index);
private:

	class Node {
	public:
		Node* pNext;
		int data;
		Node(int data, Node* pNext=nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;
};

List::List()
{
	Size = 0;
	head = nullptr;
}
List::~List()
{
  Cleaning();
}
void List::Push_up(int data)
{
	if (head == nullptr) {
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	Size++;
}
void List::Pop_down()
{
	Node *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
void List::Cleaning()
{
	while (Size) {
		Pop_down();
	}
}
int& List::operator[](const int index)
{
	int counter = 0; // счётчик
	Node* current = this->head;
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
  srand(time(NULL));
	List lst;
	int sum=0;
  int x;
	for (int i = 0; i < 10; i++){
		lst.Push_up(i+1);//добавление элемента
	}
  for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i]<<" ";
    sum+=lst[i];
	}
  cout<<endl<<sum<<" - kontrol sum"<<endl;
  sum=0;
  lst.Cleaning();
  for (int i = 10; i>0;i--){
      lst.Push_up(i);
  }
  for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i]<<" ";
    sum+=lst[i];
	}
  cout<<endl<<sum<<" - kontrol sum"<<endl;
  sum=0;
  lst.Cleaning();
  for (int i = 0; i<lst.GetSize();i++){
    x = rand() %10+1 ;
    cout<<x;
    lst.Push_up(x);
    sum+=lst[i];
  }
  cout<<endl;
  for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i]<<" ";
	}
  cout<<endl<<sum<<" - kontrol sum"<<endl;
  sum=0;
  lst.Cleaning();
	cout << lst.GetSize() << endl;//вывод размера
	cout << endl;
	lst.Cleaning();
	cout << lst.GetSize();
	return 0;
}
