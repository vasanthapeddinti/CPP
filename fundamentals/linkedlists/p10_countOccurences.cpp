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
    
    void countOccurences(Node *head, int k) {
        int count = 0;
        if (head != NULL) {
            while(head != NULL) {
                if (head->data == k) {
                        count++;
                    }
                head = head->next;
                }
            }
            cout<<"count of number: "<< k << " is "<< count<<endl;
        }
        
};

int main() {
    
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    
    for(int i=0; i<5; i++){
        temp->pushBeg(&head, i);   
    }
    temp->pushBeg(&head, 1);
    temp->pushBeg(&head, 3);
    temp->pushBeg(&head, 4);
    temp->pushBeg(&head, 4);
    temp->pushBeg(&head, 4);
    
    // print linked list
    temp->printLinkedlist(head);
    
    temp->countOccurences(head, 3);
    
    return 0;
}

/*

Sample output:

value is 4
value is 4
value is 4
value is 3
value is 1
value is 4
value is 3
value is 2
value is 1
value is 0
count of number: 3 is 2

*/

