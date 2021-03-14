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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL and curr->next!=NULL){
            if(curr->next->val==curr->val){
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
      l1->next= new ListNode(1);
      l1->next->next=new ListNode(5);
      l1->next->next->next=new ListNode(7);
      
      Solution obj;
      obj.deleteDuplicates(l1);
      ListNode* result = l1;
      while(result){
          cout<<result->val<<"->";
          result=result->next;
      }


    return 0;
}
