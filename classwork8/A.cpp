#include <iostream>

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

struct List {
    Node* head_ptr;

    List(){
        head_ptr=nullptr;
    }

    void append(int value) {
        Node *current = head_ptr;
        Node *prev = nullptr;
        while (current != nullptr) {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr) {
            Node *tmp = new Node;
            head_ptr = tmp;
            head_ptr->field = value;
            return;
        }
        prev->next = new Node;
        prev->next->field = value;
    }

    void add(int value, int index) {
        if (index == 0) {
            Node *tmp = new Node;
            tmp->next = head_ptr;
            tmp->field = value;
            head_ptr = tmp;
            return;
        }
        int i = 0;
        Node *current = head_ptr;
        Node *prev = head_ptr;

        while (current != nullptr) {
            if (i == index) {
                break;
            }
            prev = current;
            current = current->next;
            i++;
        }

        if (i < index) return;
        prev->next = new Node;
        prev->next->field = value;
        prev->next->next = current;
    }

    void pop() {
        Node *current = head_ptr;
        Node *prev = nullptr;
        Node *fck = nullptr;
        while (current != nullptr) {
            fck = prev;
            prev = current;
            current = current->next;
        }
        if (fck == nullptr) {
            Node *tmp = head_ptr;
            head_ptr = nullptr;
            delete tmp;
            return;
        }
        fck->next = nullptr;
        delete prev;
        return;
    }

    void print_list() {
        Node *current = head_ptr;
        while (current != nullptr) {
            std::cout << current->field << '\n';
            current = current->next;
        }
    }

    void delete_list() {
        Node *current = head_ptr;
        head_ptr = nullptr;
        while (current != nullptr) {
            Node *tmp = current->next;
            delete current;
            current = tmp;
        }
    }

    Node *find_by_value(int value) {
        Node *current = head_ptr;
        Node *prev = nullptr;
        while (current != nullptr) {
            if (current->field == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    Node *find_by_index(int index) {
        Node *current = head_ptr;
        int i = 0;
        while (current != nullptr) {
            if (i == index) return current;
            current = current->next;
            i++;
        }
        return nullptr;
    }

    void delete_by_value(int value) {
        Node *current = head_ptr;
        Node *prev = nullptr;
        while (current != nullptr) {
            if (current->field == value) {
                if (prev == nullptr) {
                    head_ptr = current->next;
                    delete current;
                    return;
                }
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        return;
    }

    void delete_by_index(int index) {
        Node *current = head_ptr;
        Node *prev = nullptr;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                if (prev == nullptr) {
                    head_ptr = current->next;
                    delete current;
                    return;
                }
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            i++;
        }
        return;

    }
};

int main(){
    List* a = new List;
    a->append(1);
    a->append(3);
    a->append(5);
    a->append(7);
    a->append(9);
    a->append(11);
    a->find_by_value(5)->print();
    a->find_by_index(3)->print();
    a->pop();
    a->print_list();
    a->delete_list();
}
