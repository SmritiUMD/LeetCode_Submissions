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
//     ListNode* swapPairs(ListNode* head) {
//         if(head==NULL  || head->next == NULL){
//             return head;
//         }
//         ListNode* first= head;
//         ListNode* second = head->next;
        
//         first->next=swapPairs(second->next);
//         second->next=first;
        
//         return second;
        
//     }
// };
    // iterative - o(1) space
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode* prev= dummy;
        while(head && head->next){
            //nodes to be swapped
            ListNode* first=head;
            ListNode* second = head->next;
            //swapping
            prev->next=second;
            first->next=second->next;
            second->next=first;
            //reiitialize nodes fro swapping
            // -1->second->first
                
            prev=first;
            head=first->next;
            
            
        }
        return dummy->next;
        
    }
};
int main()
{
    ListNode* l1 =  new ListNode(1);
      l1->next= new ListNode(2);
      l1->next->next=new ListNode(5);
      l1->next->next->next=new ListNode(7);
      
      Solution obj;
      ListNode* result = obj.swapPairs(l1);
      while(result){
          cout<<result->val<<"->";
          result=result->next;
      }


    return 0;
}
