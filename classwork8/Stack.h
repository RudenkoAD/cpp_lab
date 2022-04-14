//
// Created by anton on 07.04.2022.
//

#ifndef CPP_LAB_STACK_H
#define CPP_LAB_STACK_H

#include <iostream>

struct Node {
    int field;
    Node *next;

    Node() {
        field = 0;
        next = nullptr;
    }

    Node(int f, Node *n) {
        field = f;
        next = n;
    }

    void print() {
        std::cout << field;
    }
};

struct Stack {
    Node *top;

    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node *tmp = new Node;
        tmp->next = top;
        tmp->field = value;
        top = tmp;
    }

    int pop() {
        if (top == nullptr) return 0;
        Node *tmp = top->next;
        int ans=top->field;
        delete top;
        top = tmp;
        return ans;
    }

    bool is_empty() {
        return (top == nullptr);
    }

    int Top() {
        return top->field;
    }
};

#endif //CPP_LAB_STACK_H
