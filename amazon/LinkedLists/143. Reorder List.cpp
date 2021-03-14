/******************************************************************************
@author - Smriti Gupta
@date created - March 13,21
*******************************************************************************/

#include <iostream>

using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val=val;
        
    }
};
 
class Solution {
    //find middle->reverse the second half ->merge 2 lists
public:
    void reorderList(ListNode* head) {
        if(head==NULL)
            return ;
        ListNode *slow =head, *fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *prev = NULL, *curr=slow, *temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        ListNode *first = head;
        ListNode *second= prev;
        // 1->2->3->4 and 6->5->4 -> 1->6->2->5->3
        while(second->next!=NULL){
            // store the first's next pointer
            temp=first->next;
            // assign second(6) to it
            first->next=second;
            // restore the pointer - 1->6->2 first pointer is pointing to 2
            first=temp;
            
            //store the second pointer
            temp=second->next;
            // assign it to 2 1->6->2->5
            second->next=first;
            second=temp;
        }
    }
};
int main()
{
    ListNode* l1 =  new ListNode(1);
      l1->next= new ListNode(2);
      l1->next->next=new ListNode(5);
      l1->next->next->next=new ListNode(7);
      
      Solution obj;
      obj.reorderList(l1);
      ListNode* result = l1;
      while(result){
          cout<<result->val<<"->";
          result=result->next;
      }


    return 0;
}
