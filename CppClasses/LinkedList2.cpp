/******************************************************************************
@author- Smriti Gupta
@date created- Dec 8,20

*******************************************************************************/

#include <iostream>

using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    
};
//takes pointer to pointer to the head of the List
//it pushes a node in the front of the list
void push(ListNode** head, int new_data){
    //allocating new node
    ListNode* new_node= new ListNode();
    
    //putting the data
    new_node->val=new_data;
    
    //link old list off the new node
    new_node->next=(*head);
    
    // now the head pointer will point to new_node
    *head=new_node;
}

void printList(ListNode* head){
    while(head){
        cout<<"<-"<<head->val;
        head=head->next;
    }
    
}

int main()
{
    ListNode* head=NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head,5);
    push(&head, 7);
    push(&head, 10);
    
    printList(head);

    return 0;
}
