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
       
    bool isCircular(Node *head) {
        
        // An empty linked list is circular
        if (head == NULL)
           return true;
       
        Node* temp = head->next;
        while(temp != NULL && temp != head) {
            temp = temp->next;
            }
        return (temp == head);
        }


};

int main() {
    
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    bool result;
    
    for(int i=0; i<5; i++){
        temp->pushBeg(&head, i);   
    }

    
    // print linked list
    temp->printLinkedlist(head);
    
    result = temp->isCircular(head);
    if (result)
        cout<<"Linkedlist is circular"<<endl;
    else
        cout<<"Linkedlist is not circular"<<endl;
    
    Node *temp_node = head;
    while(temp_node->next != NULL) {
        temp_node = temp_node->next;
        }
    temp_node->next = head;
    
    result = temp->isCircular(head);
    if (result)
        cout<<"Linkedlist is circular"<<endl;
    else
        cout<<"Linkedlist is not circular"<<endl;
        
        
    return 0;
}

/*

Sample output:

value is 4
value is 3
value is 2
value is 1
value is 0
Linkedlist is not circular
Linkedlist is circular

*/
