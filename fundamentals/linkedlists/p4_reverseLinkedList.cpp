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
    
    void reverseLinkedlist(Node **head_ref) {
        Node *current = *head_ref;
        Node *prev, *next = NULL;
        
        while(current != NULL) {
            // move the next after current to preserve the link from current
            next = current->next;
            
            // change the link direction of current node from forward to reverse
            current->next = prev;
            
            // move one step forward: move prev to current and current to next
            prev = current;
            current = next;
        }
        (*head_ref) = prev;
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
    
    temp->reverseLinkedlist(&head);
    temp->printLinkedlist(head);
    cout << "\n\n\n";


    return 0;
}

/*

Sample output:

value is 4
value is 3
value is 2
value is 1
value is 0



value is 0
value is 1
value is 2
value is 3
value is 4

*/