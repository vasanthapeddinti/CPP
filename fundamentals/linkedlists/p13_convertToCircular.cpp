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
    
    void convertSingleToCircular(Node *head) {
        Node *temp_node = head;
        
        while(temp_node->next != NULL) {
            temp_node = temp_node->next;
        }
        temp_node->next = head;
        
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
    bool result;
    int cirNodes;
    
    for(int i=0; i<10; i++){
        temp->pushBeg(&head, i);   
    }

    
    // print linked list
    cout<<"printing singly linked list..."<<endl;
    temp->printLinkedlist(head);
    
        
    temp->convertSingleToCircular(head);
    
    cout<<"printing circular linked list..."<<endl;
    temp->displayCircularLinkedList(head);

    return 0;
}

/*

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
printing circular linked list...
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
 
*/