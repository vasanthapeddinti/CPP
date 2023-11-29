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
    
    void printReverseLinkedlist(Node *temp) {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        //Node *temp_rev = new Node;
        //temp_rev = temp;
        while(temp != NULL) {
            cout<<"value is "<<temp->data<<endl;
            temp = temp->prev;
        }
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

    //print reverse doubly linked list
    cout<<"printing reverse of doubly linked list..."<<endl;
    temp->printReverseLinkedlist(head);

    
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
printing reverse of doubly linked list...
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
