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
    
    
    void printLinkedlist(Node *temp) {
        while(temp != NULL) {
            cout<<"value is " << temp->data << endl;
            temp=temp->next;
        }
    }
    
    void deleteLinkedlist(Node **head_ref) {
        Node *current = (*head_ref);
        Node *next = NULL;
        
        if (current == NULL) {
            cout<< "Linked list is empty, nothing to delete!!" <<endl;
        }
        while(current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        (*head_ref) = NULL;
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
    
    temp->deleteLinkedlist(&head);
    temp->printLinkedlist(head);
    cout << "\n\n\n";
    

    return 0;
}