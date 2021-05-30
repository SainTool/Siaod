#include <iostream>
using namespace std;
void clear();
struct Data {
    int num;
    Data* next = NULL;
};
Data* head;
void print_node(Data* tmp);

void generate_rand(int n) {
    if (n <= 0)
        return;
    if (head)
        clear();
    head = new Data;
    Data* tmp2 = head;
    int i = 0;
    while (i < n) {
        Data* tmp = new Data;
        tmp->num = rand() % 100;
        Data* tmp2 = head->next;
        head->next = tmp;
        tmp->next = tmp2;
        i++;
    }
}

void generate_dec(int n) {
    if (n <= 0)
        return;
    if (head)
        clear();
    head = new Data;
    Data* tmp2 = head;
    int i = 0;
    while (i < n) {
        Data* tmp = new Data;
        tmp->num = n - i;
        Data* tmp2 = head->next;
        head->next = tmp;
        tmp->next = tmp2;
        i++;
    }
}

void generate_inc(int n) {
    if (n <= 0)
        return;
    if (head)
        clear();
    head = new Data;
    int i = 0;
    while (i < n) {
        Data* tmp = new Data;
        tmp->num = i + 1;
        Data* tmp2 = head->next;
        head->next = tmp;
        tmp->next = tmp2;
        i++;
    }
}

void print_node(Data* tmp) { cout << tmp->num << " "; }

void print() {
    if (head == NULL)
        return;
    if (head->next != NULL) {
        Data* tmp = head->next;
        while (tmp != NULL) {
            print_node(tmp);
            tmp = tmp->next;
        }
        cout << endl;
    }
}

int control_sum() {
    if (head == NULL)
        return 0;
    int sum = 0;
    if (head->next != NULL) {
        Data* tmp = head->next;
        while (tmp != NULL) {
            sum += tmp->num;
            tmp = tmp->next;
        }
    }
    return sum;
}

int run_number() {
    if (head == NULL)
        return 0;
    int k = 1;
    if (head->next != NULL) {
        Data* tmp = head->next;
        while (tmp->next != NULL) {
            if (tmp->num >= tmp->next->num)
                k++;
            tmp = tmp->next;
        }
    }
    return k;
}

void clear() {
    Data* tmp = head;
    Data* next;
    while (tmp != NULL) {
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head = NULL;
}

int main() {
    int n = 10;

    srand(time(NULL));

    generate_rand(n);
    print();
    cout << "Control Sum = " << control_sum() << endl;
    cout << "Run number = " << run_number() << endl << endl;

    generate_dec(n);
    print();
    cout << "Control Sum = " << control_sum() << endl;
    cout << "Run number = " << run_number() << endl << endl;

    generate_inc(n);
    print();
    cout << "Control Sum = " << control_sum() << endl;
    cout << "Run number = " << run_number() << endl << endl;
    clear();

}


