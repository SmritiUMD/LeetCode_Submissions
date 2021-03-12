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
    /*ime complexity : O(n + m)

Because exactly one of l1 and l2 is incremented on each loop iteration, the while loop runs for a 
number of iterations equal to the sum of the lengths of the two lists. All other work is constant, so the overall complexity is linear.

Space complexity : O(1)
*/


public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        //recursive
        // if(l1==NULL) return l2;
        // else if(l2==NULL) return l1;
        // else if(l1->val < l2->val){
        //     l1->next=mergeTwoLists(l1->next,l2);
        //     return l1;
        // }
        // else{
        //     l2->next=mergeTwoLists(l1,l2->next);
        //     return l2;
        // }
        // space = O(n+m)
        
        //iterative
        //false pointer to allow us to return list
        
    ListNode* list= new ListNode(-1);
//         pointer pointing to head of list, it will iterate over list
        ListNode* prehead=list;
    while(l1 && l2){
        if(l1->val <= l2->val){
            prehead->next= l1;
            l1=l1->next;
        }
        else{
            prehead->next=l2;
            l2=l2->next;
        }
        prehead=prehead->next;
        
    }
        prehead->next=l1==NULL? l2:l1;
        
        return list->next;
    }
};
int main()
{
  ListNode* l1 =  new ListNode(1);
  l1->next= new ListNode(2);
  l1->next->next=new ListNode(5);
  l1->next->next->next=new ListNode(7);

  
  Solution obj;
  int n=2;
  obj.removeNthFromEnd(l1,2);
  
    return 0;
}
