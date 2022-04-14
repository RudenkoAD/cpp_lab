#include <iostream>
#include "Stack.h"

struct Node{
    int field;
    Node* next;
    Node(){
        field=0;
        next=nullptr;
    }
    Node(int f, Node* n){
        field=f;
        next = n;
    }

    void print(){
        std::cout<<field;
    }
};

struct Stack {
    Node *top;

    Stack(){
        top=nullptr;
    }

    void push(int value) {
        Node* tmp = new Node;
        tmp->next = top;
        tmp->field=value;
        top=tmp;
    }

    Node* pop(){
        if (top == nullptr) return nullptr;
        Node* tmp = top->next;
        delete top;
        top=tmp;
        return top;
    }

    bool is_empty(){
        return (top==nullptr);
    }

    Node* Top(){
        return top;
    }
};

int main(){
    Stack* a = new Stack;
    //вау
}