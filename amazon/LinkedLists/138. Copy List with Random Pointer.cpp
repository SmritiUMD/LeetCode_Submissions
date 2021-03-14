/******************************************************************************
@author - Smriti Gupta
@date created - March 13,21
*******************************************************************************/

#include <iostream>

using namespace std;


//  * Definition for singly-linked list.
struct Node {
    int val;
    Node *next;
    Node *random;
    Node(int val) {
        this->val=val;
        
    }
};
 
class Solution {
    //iterative - O(1) - space
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* ptr=head;
        while(ptr){
            //clonde node
            Node* newNode= new Node(ptr->val);
        /*
            Inserting the cloned node just next to the original node.
      If A->B->C is the original to - > A->A'->B->B'->C->C'
      */
            
            newNode->next=ptr->next;
            ptr->next=newNode;
            ptr=newNode->next;
        }
        ptr=head;
     /*   
    Now link the random pointers of the new nodes created.
    Iterate the newly created list and use the original nodes'
    random pointers,to assign references to random pointers for cloned nodes.

        if current's random pointer in not null, then assign its random poiter to ptr->next's random pointer
        1->random, 2->random
            ptr     ptr->next
            
            */
        while(ptr){
            ptr->next->random=(ptr->random!=NULL) ? ptr->random->next : NULL;
            
            ptr = ptr->next->next;
        }
        
        Node* old_list=head; //A-B-C
        Node* new_list= head->next; //A'-B'-C'
        Node* head_new=head->next;
        
        // Make two seperate lists
        while(old_list){
            old_list->next=old_list->next->next;
            //check if old list is finished first and next assign the pointer
            new_list->next=(new_list->next!= NULL) ? new_list->next->next : NULL;
            //advance the pointers
            old_list=old_list->next;
            new_list=new_list->next;
            
        }
        return head_new;
        
    }
};
int main()
{
    Node* l1 =  new Node(1);
      l1->next= new Node(2);
      l1->next->next=new Node(5);
      l1->next->next->next=new Node(7);
      
      Solution obj;
      Node* result = obj.copyRandomList(l1);
      while(result){
          cout<<result->val<<"->";
          result=result->next;
      }


    return 0;
}
