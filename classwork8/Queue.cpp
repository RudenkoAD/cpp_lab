#include <iostream>

struct Node {
    int field;
    Node *next;
    Node *prev;

    Node() {
        field = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int f) {
        field = f;
        next = nullptr;
        prev = nullptr;
    }

    void print() {
        std::cout << field;
    }
};


struct Queue {
    Node *head;
    Node *tail;

    void push(int value) {
        Node *tmp = new Node(value);
        if (is_empty()) {
            head = tmp;
            tail = tmp;
            return;
        }
        tail->next = tmp;
        tmp->next = tail;
        tail = tmp;
        return;
    }

    void last() {
        std::cout << tail->field;
    }

    void pop() {
        Node *tmp = head->next;
        delete head;
        head = tmp;
        return;
    }

    bool is_empty() {
        return head != nullptr;
    }

    int size() {
        int i = 0;
        Node *cur = head;
        while (cur != nullptr) {
            i++;
            cur = cur->prev;
        }
        return i;
    }
};

int main() {

}
