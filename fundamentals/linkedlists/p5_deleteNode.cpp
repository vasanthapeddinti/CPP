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
    
    void deleteNode(Node **head_ref, int pos) {
        Node *current = (*head_ref);
        Node *prev = (*head_ref);
        
        for(int i=1; i<=pos; i++) {
            // position matched at first
            if ((pos == 1) && (current != NULL)) {
                (*head_ref) = current->next;
                free(current);
            }
            else {
                // position other than first: mid or end
                if ((i == pos) && (current != NULL)) {
                    prev->next = current->next;
                    free(current);
                }
                else {
                    // you either reached at the end of linked list or have to traverse more
                    if (current == NULL) {
                        cout<<"position is larger than length of linked list\n\n"<<endl;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
            }
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
    
    temp->deleteNode(&head, 5);
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



value is 4
value is 3
value is 2
value is 1

*/