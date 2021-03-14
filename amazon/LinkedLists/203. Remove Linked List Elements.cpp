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
public:
    ListNode* removeElements(ListNode* head, int val) {
//         ListNode* temp= new ListNode(-1);
//         temp->next=head;
        
//         ListNode* prev= temp;
//         ListNode* curr=head;
//         ListNode* todelete=NULL;
       
//         while(curr){
//             if(curr->val==val){
//                 prev->next=curr->next;
//                 todelete=curr;
//             }
//             else{
//                 prev=curr;
//             }
//             curr=curr->next;
//             if(todelete){
//                 delete todelete;
//                 todelete=NULL;
//             }
//         }
//         return temp->next;
        
        if(!head) return head;
        //to handle if first value is the given value
        while(head && head->val==val){
            head=head->next;
        }
        ListNode* curr=head;
        while(curr && curr->next){
            if(curr->next->val==val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
        
    }
};
int main()
{
    ListNode* l1 =  new ListNode(1);
      l1->next= new ListNode(2);
      l1->next->next=new ListNode(5);
      l1->next->next->next=new ListNode(7);
      
      Solution obj;
      int val=2;
      ListNode* result = obj.removeElements(l1,val);
      while(result){
          cout<<result->val<<"->";
          result=result->next;
      }


    return 0;
}
