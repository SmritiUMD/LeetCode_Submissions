/******************************************************************************
@author- Smriti Gupta
@date created - March 12, 21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int val){
         this->val=val;
     }
 };

class Solution {
    /*Time - O(max(l1,l2));
    Space - (O(max(l1,l2)))+1;
    */
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l3 = new ListNode(0);
        ListNode* curr=l3;
        int sum=0;
        int carry=0;
        
        while(l1 || l2){
            int add = (l1? l1->val :0) + (l2? l2->val :0) + carry;
            sum=add%10;
            carry=add/10;
            curr->next= new ListNode(sum);
            curr=curr->next;
            l1? l1=l1->next  : nullptr;
            l2? l2=l2->next : nullptr;
        }
        
        if(carry){
            curr->next= new ListNode(carry);
        }
        
        return l3->next;          
        
        
    }
};
int main()
{
  ListNode* l1 =  new ListNode(1);
  l1->next= new ListNode(2);
  l1->next->next=new ListNode(5);
  l1->next->next->next=new ListNode(7);
  
  ListNode* l2 =  new ListNode(4);
  l2->next= new ListNode(3);
  l2->next->next=new ListNode(5);
  l2->next->next->next=new ListNode(2);
  
  
  Solution obj;
  obj.addTwoNumbers(l1,l2);
  
    return 0;
}
