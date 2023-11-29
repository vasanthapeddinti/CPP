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
       
    bool isCircular(Node *head) {
        
        // An empty linked list is circular
        if (head == NULL)
           return true;
       
        Node* temp = head->next;
        while(temp != NULL && temp != head) {
            temp = temp->next;
            }
        return (temp == head);
        }


    int countNodesCircular(Node *head) { 
        Node *temp_node = head;
        int count = 0;
        
        if (head == NULL) {
            return count;
            }
        
        do {
                temp_node = temp_node->next;
                count++;
        } while(temp_node != head) ;
        
        return count; // 1 is for head which is skipped in the begining
        }

};

int main() {
    
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    bool result;
    int cirNodes;
    
    for(int i=0; i<10; i++){
        temp->pushBeg(&head, i);   
    }

    
    // print linked list
    temp->printLinkedlist(head);
    
    result = temp->isCircular(head);
    if (result)
        cout<<"Linkedlist is circular"<<endl;
    else
        cout<<"Linkedlist is not circular"<<endl;
    
    Node *temp_node = head;
    while(temp_node->next != NULL) {
        temp_node = temp_node->next;
        }
    temp_node->next = head;
    
    result = temp->isCircular(head);
    if (result)
        cout<<"Linkedlist is circular"<<endl;
    else
        cout<<"Linkedlist is not circular"<<endl;
        
    cirNodes = temp->countNodesCircular(head);
    cout<<"No of nodes in circular linked list is "<< cirNodes <<endl;
        
    return 0;
}

/*

Sample Output:

value is 9
value is 8
value is 7
value is 6
value is 5
value is 4
value is 3
value is 2
value is 1
value is 0
Linkedlist is not circular
Linkedlist is circular
No of nodes in circular linked list is 10

*/
