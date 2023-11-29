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

    int lengthLinkedlist(Node *temp) {
        if (temp == NULL) {
            cout<<"length of linkedlist is 0";
            return 0;    
        }
        
        int count=0;
        while(temp != NULL) {
            count = count+1;
            temp=temp->next;
        }
        cout<<"length of linkedlist is "<<count<<endl;
        return count;
    }
    
    int getNthNodeFromEnd(Node *head, int n, int len) {
        if (head == NULL) {
            cout<<"Linkedlist is empty"<<endl;
            return -1;
        }
        
        Node *current = head;
        int n_front = len - n + 1;

        if (n_front<=0) {
            cout << "Trying to access invalid index"<<endl;
            return -1;
        }
        
        for (int i=1; i<=n_front; i++) {
            if (current != NULL){
                if (i == n_front) {
                    cout<< "nth node is "<<current->data<<endl;
                    return current->data;
                }
                else {
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
    
    //class Node *temp_head = NULL;
    temp->printLinkedlist(head);
    cout << "\n\n\n";
    
    int x = temp->lengthLinkedlist(head);
    temp->getNthNodeFromEnd(head, 2, x);
    

    return 0;
}

