#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;
};

class NodeOperation {
    public:
    void pushBeg(Node **head_ref, int new_data) {
        Node *new_node = new Node;
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
    
    void insertAfter(Node *prev_node, int new_data) {
        if (prev_node == NULL) {
            cout<< "Prev node can't be NULL";
            return;
        }
        Node *new_node = new Node;
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    
    void insertEnd(Node **head_ref, int new_data) {
        // Create a new node
        Node* new_node = new Node();
        new_node->data = new_data;
     
        // Set the next pointer of the new node as NULL since it
        // will be the last node
        new_node->next = NULL;
        
        // Store the head reference in a temporary variable
        Node* last = *head_ref;
    
     
        // If the Linked List is empty, make the new node as the
        // head and return
        if (*head_ref == NULL) {
            *head_ref = new_node;
            return;
        }
     
        // Else traverse till the last node
        while (last->next != NULL) {
            last = last->next;
        }
     
        // Change the next pointer of the last node to point to
        // the new node
        last->next = new_node; 
    }
    
    void printLinkedlist(Node *temp) {
        while(temp != NULL) {
            cout<<"value is " << temp->data << endl;
            temp=temp->next;
        }
    }
};


int main() {

    class Node *head = NULL;
    class NodeOperation *temp = new NodeOperation();
    
    for (int i=0; i<5; i++) {
        temp->pushBeg(&head, i);
    }
    
    class Node *temp_head = NULL;
    temp->printLinkedlist(head);
    cout << "\n\n\n";
    
    temp->insertAfter(head, -1);
    temp->printLinkedlist(head);
    
    cout << "\n\n\n";
    
    temp->insertEnd(&head, 78);
    temp->printLinkedlist(head);
    

    return 0;
}

/*
Output:

value is 4
value is 3
value is 2
value is 1
value is 0



value is 4
value is -1
value is 3
value is 2
value is 1
value is 0



value is 4
value is -1
value is 3
value is 2
value is 1
value is 0
value is 78

*/