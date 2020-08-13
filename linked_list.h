#pragma once

template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void PushFront(const T& value) {
        Node* new_head = new Node{ value, head };
        head = new_head;
    }

    void InsertAfter(Node* node, const T& value) {
        if (node == nullptr) {
            PushFront(value);
            return;
        }
        Node* new_node = new Node{ value, node->next };
        node->next = new_node;
    }

    void RemoveAfter(Node* node) {
        if (node == nullptr) {
            PopFront();
            return;
        }
        if (node->next == nullptr) return;

        Node* del_node = node->next;
        node->next = (node->next)->next;
        delete del_node;
    }

    void PopFront() {
        if (head == nullptr) {
            return;
        }
        Node* last_head = head;
        head = head->next;
        delete last_head;
    }

    Node* GetHead() { return head; }

    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};