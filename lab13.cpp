#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

int C = 0;
int M = 0;

struct Node {
    Node* next = nullptr;
    union {
        int data;
        unsigned char digit[sizeof(int)];
    };
};

struct Queue {
    Node* head;
    Node* tail;
};

void print(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Node* fill_inc(int n) {
    Node* p = nullptr, * head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        p = new Node;
        p->data = i;
        p->next = head;
        head = p;
    }
    return head;
}

Node* fill_dec(int n) {
    Node* p = nullptr, * head = nullptr;
    for (int i = 0; i < n; i++) {
        p = new Node;
        p->data = i;
        p->next = head;
        head = p;
    }
    return head;
}

Node* fill_rand(int n) {
    Node* p = nullptr, * head = nullptr;
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        p = new Node;
        p->data = rand() % (n * 2);
        p->next = head;
        head = p;
    }
    return head;
}

int check_sum(Node* head) {
    int sum = 0;
    Node* p = head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int run_number(Node* head) {
    int i = 1;
    Node* p = head;
    while (p->next) {

        if (p->data > p->next->data) {
            i += 1;
        }
        p = p->next;
    }
    return i;
}

void clear(Node*& head) {
    if (head == nullptr)
        return;
    Node* p = head, * temp;
    while (p) {
        temp = p;
        p = p->next;
        delete temp;
    }
    head = nullptr;
}

int get_size(Node* head) {
    int size = 0;
    Node* p = head;
    while (p) {
        size++;
        p = p->next;
    }
    return size;
}

void digital_sort(Node*& S) {
    Queue Q[256];
    for (int j = sizeof(int); j >= 0; j--) {
        for (int i = 0; i < 256; i++) {
            Q[i].tail = (Node*)&Q[i].head;
        }
        Node* p = S;
        while (p) {
            unsigned char d = p->digit[j];
            Q[(int)d].tail->next = p;
            Q[(int)d].tail = p;
            p = p->next;
        }
        p = (Node*)&S;
        for (int i = 0; i < 256; i++) {
            if (Q[i].tail != (Node*)&Q[i].head) {
                p->next = Q[i].head;
                p = Q[i].tail;
            }
        }
        p->next = nullptr;
    }
}

int main() {

    Node* list = fill_rand(30);
    cout << "list:\t";
    print(list);
    digital_sort(list);
    cout << "digital sort:\t";
    print(list);
    clear(list);

    return 0;
}
