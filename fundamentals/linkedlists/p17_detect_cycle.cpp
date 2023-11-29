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
       
    bool detectCycle(Node *temp) {
        Node *slow_ptr = temp;
        Node *fast_ptr = temp;
        
            if (temp == NULL) {
                cout<< "head node is NULL"<<endl;
                return false;
                }
                
            while(fast_ptr != NULL && slow_ptr != NULL) {
                    slow_ptr = slow_ptr->next;
                    fast_ptr = fast_ptr->next->next;
                    
                    cout<<"\n\nvalue is "<<slow_ptr->data <<endl;
                    cout<<"value is "<<fast_ptr->data <<endl;
                    if (slow_ptr == fast_ptr) {
                        cout<<"Linked list is a circular linked list"<< endl;
                        return true;
                        }
                }
                cout<<"Linked list is not a circular linked list"<< endl;
                return false;
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

    result = temp->detectCycle(head);

    
    return 0;
}
