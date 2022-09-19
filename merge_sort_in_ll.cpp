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

        Node* findmid(Node * ptr) {
            Node *slow = ptr;
            Node *fast = ptr->next;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node* merge(Node* left, Node* right) {
            Node *tmp = new Node();
            Node *prev = tmp;
            while(left != NULL && right != NULL) {
                Node *ptr = new Node();
                if (left->data > right->data) {
                    ptr->data = right->data;
                    right = right->next;
                } else {
                    ptr->data = left->data;
                    left = left->next;
                }

                prev->next = ptr;
                prev = ptr;
            }

            while(left != NULL) {
                Node *ptr = new Node();
                ptr->data = left->data;
                prev->next = ptr;
                prev = ptr;
                left = left->next;
            }

            while(right != NULL) {
                Node *ptr = new Node();
                ptr->data = right->data;
                prev->next = ptr;
                prev = ptr;
                right = right->next;
            }

            return tmp->next;
        }

        Node* mergesort(Node *ndhead) {
            if (ndhead == NULL || ndhead->next == NULL) return ndhead;

            Node *mid = findmid(ndhead);
            Node *left = ndhead;
            Node *right = mid->next;
            mid->next = NULL;

            Node *l1 = mergesort(left);
            Node *l2 = mergesort(right);

            Node *result = merge(l1, l2);
            head = result;
            return result;
        }

};


signed main() {
    Linkedlist list;
    Linkedlist ll;
    
    list.insertNode(12);
    list.insertNode(90);
    list.insertNode(450);
    list.insertNode(1000);
    list.insertNode(20000);
    list.insertNode(8);
    list.insertNode(10);
    list.insertNode(23);
    list.insertNode(123);
    list.insertNode(221);

    list.mergesort(list.listhead());


    list.printList();
    cout  << endl;
    
}