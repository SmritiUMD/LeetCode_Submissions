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
    private:
    ListNode* merge(ListNode* l1, ListNode* l2){
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

public:
    ListNode* mergeKLists(vector<ListNode*>lists) {
        if(lists.size()==0) return NULL;
    ListNode* x=lists[0];
        for(int i=1;i<lists.size();i++){
            x=merge(x,lists[i]);
        }
        return x;
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
//   obj.mergeKLists();
  
    return 0;
}
