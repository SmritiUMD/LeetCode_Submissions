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

// 2 pass
/*Time - O(l)
Space= O(1)
*/
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* curr=new ListNode(0);
//         ListNode* newList= new ListNode(0);
//         newList->next= head;
//         curr=head;
//         int len=0;
//         while(curr){
//             len++;
//             curr=curr->next;
//         }
//         curr=newList;
//         while(len-n>0){
//             curr=curr->next;
//             len--;
//         }
//         curr->next=curr->next->next;
        
//         return newList->next;
//     }
// };

/* One Pass Algorithm
use 2 pointers to maintain n distance between both pointers.
advance second pointer first till n+1.
then advance both and remove the last node from first
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
       
        ListNode* first=dummy;
        //to keep a track of distance
        ListNode* second=dummy;
        int len=1;
        while(len<=n+1){
            second=second->next;
            len++;
        }
        while(second){
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return dummy->next;
       
    }
};
int main()
{
  ListNode* l1 =  new ListNode(1);
  l1->next= new ListNode(2);
  l1->next->next=new ListNode(5);
  l1->next->next->next=new ListNode(7);
  
//   ListNode* l2 =  new ListNode(4);
//   l2->next= new ListNode(3);
//   l2->next->next=new ListNode(5);
//   l2->next->next->next=new ListNode(2);
  
  
  Solution obj;
  int n=2;
  obj.removeNthFromEnd(l1,2);
  
    return 0;
}
