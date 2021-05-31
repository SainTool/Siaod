#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

int C = 0;
int M = 0;

struct Node {
  Node *next = nullptr;
  int data;
};

struct Queue {
  Node *head;
  Node *tail;
};

void print_list(Node *head) {
  Node *p = head;
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

Node *fill_inc(int n) {
  Node *p = nullptr, *head = nullptr;
  for (int i = n - 1; i >= 0; i--) {
    p = new Node;
    p->data = i;
    p->next = head;
    head = p;
  }
  return head;
}

Node *fill_dec(int n) {
  Node *p = nullptr, *head = nullptr;
  for (int i = 0; i < n; i++) {
    p = new Node;
    p->data = i;
    p->next = head;
    head = p;
  }
  return head;
}

Node *fill_rand(int n) {
  Node *p = nullptr, *head = nullptr;
  srand(time(nullptr));
  for (int i = 0; i < n; i++) {
    p = new Node;
    p->data = rand() % (2 * n);
    p->next = head;
    head = p;
  }
  return head;
}

int check_sum(Node *head) {
  int sum = 0;
  Node *p = head;
  while (p) {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int run_number(Node *head) {
  int i = 1;
  Node *p = head;
  while (p->next) {

    if (p->data > p->next->data) {
      i += 1;
    }
    p = p->next;
  }
  return i;
}

void clear(Node *&head) {
  if (head == nullptr)
    return;
  Node *p = head, *temp;
  while (p) {
    temp = p;
    p = p->next;
    delete temp;
  }
  head = nullptr;
}

void merge(Node *&a, int q, Node *&b, int r, Queue &c) {
  while (q != 0 && r != 0) {
    C++;
    if (a->data <= b->data) {
      c.tail->next = a;  //перемещение элемента из списка а в очередь с
      c.tail = a;
      a = a->next;
      M++;
      q--;
    } else {
      c.tail->next = b; //перемещение элемента из списка b в очередь с
      c.tail = b;
      b = b->next;
      M++;
      r--;
    }
  }
  while (q > 0) {
    c.tail->next = a; //перемещение элемента из списка а в очередь с
    c.tail = a;
    a = a->next;
    M++;
    q--;
  }
  while (r > 0) {
    c.tail->next = b; //перемещение элемента из списка b в очередь с
    c.tail = b;
    b = b->next;
    M++;
    r--;
  }
}

int get_size(Node *head) {
  int size = 0;
  Node *p = head;
  while (p) {
    size++;
    p = p->next;
  }
  return size;
}

int main() {
    
  Node *list1, *list2;
  Queue c;
  c.tail = (Node *)&c.head;
  int n = 10;

  cout << "Первая серия : ";
  list1 = fill_inc(n);
  print_list(list1);
  cout << "Contr. sum = " << check_sum(list1) << endl;
  cout << "Run number = " << run_number(list1) << endl << endl;

  cout << "Вторая серия : ";
  list2 = fill_inc(n);
  print_list(list2);
  cout << "Contr. sum = " << check_sum(list2) << endl;
  cout << "Run number = " << run_number(list2) << endl << endl;

  merge(list1, n, list2, n, c);

  cout << "Слияние : ";
  print_list(c.head);
  cout << "Contr. sum = " << check_sum(c.head) << endl;
  cout << "Run number = " << run_number(c.head) << endl << endl;
  cout << "Mt = " << n + n << endl;
  cout << "Ct = " << n + n - 1 << endl;
  cout << "M = " << M << endl;
  cout << "C = " << C << endl;
  clear(list1);
  clear(list2);
  clear(c.head);
  cout << endl << endl << endl;


  return 0;
}


