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
    
    void printMiddleNode(Node *temp) {
        Node *slow_ptr = temp;
        Node *fast_ptr = temp;
        
        while((fast_ptr != NULL && fast_ptr->next != NULL)) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        cout<< "Mid number in the Linked List is " << slow_ptr->data << endl;
    }
};

int main() {
    
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    
    for(int i=0; i<6; i++){
        temp->pushBeg(&head, i);   
    }
    // print linked list
    temp->printLinkedlist(head);
    
    // print mid number of linked list
    temp->printMiddleNode(head);
    
    return 0;
}

/*

Sample output:

value is 5
value is 4
value is 3
value is 2
value is 1
value is 0
Mid number in the Linked List is 2

*/