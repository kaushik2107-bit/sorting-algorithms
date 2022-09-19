#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            data = 0;
            next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Linkedlist {
    Node* head;
    public:
        Linkedlist() {head = NULL;}

        void insertNode (int data) {
            Node* newNode = new Node(data);
            if (head == NULL) {
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
        void printList() {
            Node *temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        void deleteNode(int nodeoffset) {
            Node *temp1 = head, *temp2 = NULL;
            int count = 0;
            if (head == NULL) {
                cout << "LIST EMPTY" << endl;
            }

            while(temp1 != NULL) {
                temp1 = temp1->next;
                count++;
            }

            if (count < nodeoffset) {
                cout << "Index out of range" << endl;
                return;
            }

            temp1 = head;
            if (nodeoffset == 1) {
                head = head->next;
                delete temp1;
                return;
            }

            while(nodeoffset-- > 1) {
                temp2 = temp1;
                temp1 = temp1->next;
            }

            temp2->next = temp1->next;
            delete temp1;
        }

        Node* listhead() {
            return head;
        }


        void bubble_sort_in_ll() {
            if (head == NULL || head->next == NULL) return;

            Node *temp1 = head;
            
            while(temp1->next != NULL) {
                Node *temp2 = temp1->next;
                while(temp2 != NULL) {
                    if (temp1->data > temp2->data) {
                        swap(temp1->data, temp2->data);
                    }
                    temp2 = temp2->next;
                }
                temp1 = temp1->next;
            }
        }
    
};


void bubble_sort_in_ll(Node *head) {
    if (head == NULL || head->next == NULL) return;
    Node *temp1 = head;
    while(temp1->next != NULL) {
        Node *temp2 = temp1->next;
        while(temp2 != NULL) {
            if (temp1->data > temp2->data) {
                swap(temp1->data, temp2->data);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}


signed main() {
    Linkedlist list;
    list.insertNode(1);
    list.insertNode(100);
    list.insertNode(24);
    list.insertNode(43);
    list.insertNode(12);
    list.insertNode(5);
    list.insertNode(9);
    list.insertNode(1000);

    list.printList();
    cout  << endl;


    list.bubble_sort_in_ll();
    // bubble_sort_in_ll(list.listhead());
    

    list.printList();
    cout  << endl;
    
}