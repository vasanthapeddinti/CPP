// Answer is wrong, still needs debugging

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class NodeOperation{
    public:
    void pushBeg(Node **head_ref, int new_data) {
        Node *new_node = new Node;
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        return;
    }
        
    void printLinkedlist(Node *temp) {
        while(temp != NULL) {
            cout<<"value is " << temp->data << endl;
            temp=temp->next;
        }
    }

    Node* exchangeNodes(Node *head) {

        if (head->next->next == head) {
            head = head->next;
            return head;
        }
        
        Node *temp = head;
        // traverse till the last but one node from head
        while(temp->next->next != head) {
            temp = temp->next;
            }
        temp->next->next = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp->next->next; // or head = head->next;
        return head;
        }

    void displayCircularLinkedList(Node *head) {
        Node *temp_node = head;
        while(temp_node->next != head) {
            cout<<"value is " << temp_node->data << endl;
            temp_node=temp_node->next;
        }
        //print last node in circular linkedlist
        cout<<"value is " << temp_node->data << endl;
        temp_node=temp_node->next;  
        
    }
    
};

int main() {
    
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    
    for(int i=0; i<10; i++){
        temp->pushBeg(&head, i);   
    }

    
    // print linked list
    cout<<"printing singly linked list..."<<endl;
    temp->printLinkedlist(head);

    // generate circular linked list
    Node *temp_node = head;
    while(temp_node->next != NULL) {
        temp_node = temp_node->next;
        }
    temp_node->next = head;
    cout<<"head->data is "<<head->data<<endl;
    
    // exchange first and last nodes in circular linked list
    temp->exchangeNodes(head);

    cout<<"printing circular linked list..."<<endl;
    temp->displayCircularLinkedList(head);
    
    return 0;
}
/*
Answer is wrong, still needs debugging

Sample output:

printing singly linked list...
value is 9
value is 8
value is 7
value is 6
value is 5
value is 4
value is 3
value is 2
value is 1
value is 0
head->data is 9
printing circular linked list...
value is 9
value is 0
value is 8
value is 7
value is 6
value is 5
value is 4
value is 3
value is 2
value is 1

*/