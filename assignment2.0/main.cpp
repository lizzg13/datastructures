//
//  main.cpp
//  assignment2.0
//
//  Created by Liz Garcia on 9/30/24.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

struct DoublyLinkedList {
    Node* head;

    DoublyLinkedList() : head(nullptr) {}
};

int DoublyInsert(int data, int index, DoublyLinkedList** Ptr) {
    if (index < 0) return -1;

    Node* newNode = new Node(data);
    if (*Ptr == nullptr) {
        
        if (index == 0) {
            *Ptr = new DoublyLinkedList();
            (*Ptr)->head = newNode;
            return 0;
        }
        return -1;
    }

    DoublyLinkedList* list = *Ptr;
    Node* current = list->head;

    if (index == 0) {
        newNode->next = current;
        if (current) {
            current->prev = newNode;
        }
        list->head = newNode;
        return 0;
    }

    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        
        return -1;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return 0;
}

int DoublyDelete(int index, DoublyLinkedList** Ptr) {
    if (*Ptr == nullptr || index < 0) return -1;

    DoublyLinkedList* list = *Ptr;
    Node* current = list->head;

    if (index == 0) {
        if (current) {
            list->head = current->next;
            if (list->head) {
                list->head->prev = nullptr;
            }
            delete current;
            return 0;
        }
        return -1;
    }

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        return -1;
    }

    // Update pointers
    if (current->prev) {
        current->prev->next = current->next;
    }
    if (current->next) {
        current->next->prev = current->prev;
    }

    delete current;
    return 0;
}

int main() {
    DoublyLinkedList* list = nullptr;

    DoublyInsert(10, 0, &list);  //  10 at index 0
    DoublyInsert(20, 1, &list);  //  20 at index 1
    DoublyInsert(15, 1, &list);  //  15 at index 1

    DoublyDelete(1, &list);

    Node* current = list->head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
