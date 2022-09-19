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

        void insertionsort(int data) {
            Node *temp = new Node(data);
            if (head==NULL) {
                head = temp;
                return;
            }

            Node* tmp1 = head;
            Node *tmp2 = NULL;
            while(tmp1 != NULL) {
                if (tmp1->data >= data) break;
                tmp2 = tmp1;
                tmp1 = tmp1->next;
            }

            if (tmp1 == head) {
                temp->next = tmp1;
                head = temp;
                return;
            }

            if (tmp1 == NULL) {
                tmp2->next = temp;
                return;
            }

            temp->next = tmp1;
            tmp2->next = temp;
        }
};





signed main() {
    Linkedlist list;
    
    list.insertionsort(5);
    list.insertionsort(7);
    list.insertionsort(1);
    list.insertionsort(1);
    list.insertionsort(10);
    list.insertionsort(6);
    list.insertionsort(5);
    list.insertionsort(8);
    list.insertionsort(1);
    list.insertionsort(9);
    list.insertionsort(10);
    list.insertionsort(11);

    list.printList();
    cout  << endl;
    
}