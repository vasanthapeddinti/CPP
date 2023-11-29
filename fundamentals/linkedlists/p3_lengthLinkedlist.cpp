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
    
    void lengthLinkedlist(Node *temp) {
        if (temp == NULL) {
            cout<<"length of linkedlist is 0";
            return;    
        }
        
        int count=0;
        while(temp != NULL) {
            count = count+1;
            temp=temp->next;
        }
        cout<<"length of linkedlist is "<<count<<endl;
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
    
    temp->lengthLinkedlist(head);
    

    return 0;
}

/*

Sample output:

value is 4
value is 3
value is 2
value is 1
value is 0



length of linkedlist is 5

*/