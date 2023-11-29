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
    
    int getNode(Node *head, int n) {
        Node *current = head;
        int count = 0;
        while(current != NULL) {
            if (count == n) {
                cout<<"Found the "<<n<<"th node. Value is "<<current->data<<endl;
                return current->data;
            }
            count++;
            current = current->next;
        }
        cout<<"Node not found"<<endl;
        return -1;
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
    
    temp->getNode(head, 4);
    
    

    return 0;
}

/*

Saple output:

value is 4
value is 3
value is 2
value is 1
value is 0



Found the 4th node. Value is 0

*/