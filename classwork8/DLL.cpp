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

struct DList {
    Node *head;
    Node *tail;

    DList() {
        head = nullptr;
        tail = nullptr;
    }

    DList(int value) {
        head = new Node;
        head->field = value;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }

    void append(int value) {
        Node *tmp = new Node(value);
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }

    void add(int value, int index) {
        if (index == 0) {
            Node *tmp = new Node;
            tmp->next = head;
            tmp->field = value;
            head->prev = nullptr;
            head = tmp;
            return;
        }

        int i = 0;
        Node *current = head;

        while (current != nullptr) {
            if (i == index) {
                break;
            }
            current = current->next;
            i++;
        }

        if (i < index) return;
        if (current == nullptr) {
            append(value);
            return;
        }

        Node *tmp = new Node(value);
        tmp->prev = current->prev;
        tmp->next = current;
        if (current->prev != nullptr) current->prev->next = tmp;
        current->prev = tmp;
    }

    void pop() {
        Node *tmp = tail->prev;
        delete tail;
        tail = tmp;
        return;
    }

    void print_list() {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current->field << '\n';
            current = current->next;
        }
    }

    void delete_list() {
        Node *current = head;
        head = nullptr;
        while (current != nullptr) {
            Node *tmp = current->next;
            delete current;
            current = tmp;
        }
    }

    Node *find_by_value(int value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->field == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    Node *find_by_index(int index) {
        Node *current = head;
        int i = 0;
        while (current != nullptr) {
            if (i == index) return current;
            current = current->next;
            i++;
        }
        return nullptr;
    }

    void delete_by_value(int value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->field == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        return;
    }

    void delete_by_index(int index) {
        Node *current = head;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
            i++;
        }
        return;

    }

    int size() {
        int i = 0;
        Node *cur = head;
        while (cur != nullptr) {
            i++;
            cur = cur->next;
        }
        return i;
    }
};

int main() {
    DList *a = new DList;
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

