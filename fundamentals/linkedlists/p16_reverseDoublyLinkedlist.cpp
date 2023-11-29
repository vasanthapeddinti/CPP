#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};

class NodeOperation{
    public:
    void pushBeg(Node **head_ref, int new_data) {
        Node *new_node = new Node;
        
        new_node->data = new_data;
        new_node->prev = NULL;
        new_node->next = *head_ref;
        
        if (*head_ref != NULL) {
            (*head_ref)->prev = new_node;
            }
        (*head_ref) = new_node;
    }
        
    void printLinkedlist(Node *temp) {
        while(temp != NULL) {
            cout<<"value is " << temp->data << endl;
            temp=temp->next;
        }
    }
    
    void reverseDoublyLinkedlist(Node **head_ref) {
        Node *temp = new Node;
        Node *current = *head_ref;
        /* swap next and prev for all nodes of
        doubly linked list */
        while(current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        
    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if (temp != NULL)
        *head_ref = temp->prev;
    }
};

int main() {
    
    Node *head = NULL;
    NodeOperation *temp = new NodeOperation();
    
    for(int i=0; i<10; i++){
        temp->pushBeg(&head, i);   
    }

    
    // print doubly linked list
    cout<<"printing doubly linked list..."<<endl;
    temp->printLinkedlist(head);

    temp->reverseDoublyLinkedlist(&head);
   
    cout<<"printing doubly linked list..."<<endl;
    temp->printLinkedlist(head); 
    
    return 0;
}

/*

Sample output:

printing doubly linked list...
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
printing doubly linked list...
value is 0
value is 1
value is 2
value is 3
value is 4
value is 5
value is 6
value is 7
value is 8
value is 9

*/