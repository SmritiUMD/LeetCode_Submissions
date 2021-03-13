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
/* Iterative 
TIme- O(n)
Space - O(1)

*/
// public:
//     ListNode* reverseList(ListNode* head) {
//        ListNode* curr = head;
//         ListNode* prev= NULL;
//         ListNode* next=NULL;
//         while(curr){
//             //save the next pointer
//             next=curr->next;
//             //reverse the pointer
//             curr->next=prev;
//             //advance the prev and curr
//             prev=curr;
//             curr=next;
//         }
//         //new head
//         return prev;
//     }
// };
public:
//     recursive
//  space - O(n)   
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
       ListNode* l3= reverseList(head->next);
        while(head->next){
           head->next->next=head;
           head->next=NULL;
           
       } 
        return  l3; 
        
    }
};
int main()
{
    ListNode* l1 =  new ListNode(1);
      l1->next= new ListNode(2);
      l1->next->next=new ListNode(5);
      l1->next->next->next=new ListNode(7);
      
      Solution obj;
      obj.reverseList(l1);


    return 0;
}
