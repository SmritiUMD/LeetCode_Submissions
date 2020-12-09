/******************************************************************************

@Author-Smriti Gupta
@Date Created-Dec 8,20
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ListNode{
    public:
  int val;
  ListNode* next;
 
};


class Solution{
  
  public:
  bool detectCycle(ListNode* head){
      set<ListNode*>visited;
     while(head){
         if(visited.find(head)!=visited.end()){
             cout<<head->val;
             return true;
         }
         else{
             visited.insert(head);
         }
         
     }
     return false;
  }
};
    


int main()
{
  ListNode* head= new ListNode();
  head->val=50;
  head->next=new ListNode();
  head->next->val=20;
  head->next->next= new ListNode();
  head->next->next->val=40;
  head->next->next->next= new ListNode();
  head->next->next->next->val=20;
  
  
  Solution obj;
  cout<<obj.detectCycle(head);
   
    return 0;
}
