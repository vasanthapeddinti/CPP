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
    
    bool searchElement (Node **head_ref, int element) {
        if (*head_ref == NULL) {
            cout<<"empty linked list provided" << endl;
            return false;
        }
        
        Node *temp_node = *head_ref;
        
        while(temp_node != NULL) {
            if (temp_node->data == element) {
                cout<<"element found!!!"<<endl;
                return true;
            }
            else {
                temp_node = temp_node->next;
            }
        }
        cout<<"element not found!!"<<endl;
        return false;
        
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
    
    temp->searchElement(&head, 4);
    temp->searchElement(&head, 784);
    

    return 0;
}

/*

Sample output:

value is 4
value is 3
value is 2
value is 1
value is 0



element found!!!
element not found!!

*/