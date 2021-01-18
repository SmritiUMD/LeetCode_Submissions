/******************************************************************************
@author - Smriti Gupta
@date created - January 18,21

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std; 
 
struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    
    TreeNode(int data){
        this->val=data;
        left=NULL;
        right=NULL;
    }
};



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>curr;
        queue<TreeNode*>next;
        next.push(root);
        vector<int>right_nodes;
        if(!root) return right_nodes;
        TreeNode* ele=NULL;
        while(!next.empty()){
            curr=next;
            while(!next.empty())
                next.pop();
            while(!curr.empty()){
                ele=curr.front();
                curr.pop();
                if(ele->left) next.push(ele->left);
                if(ele->right) next.push(ele->right);
                
            }
            if(curr.empty())
             right_nodes.push_back(ele->val);
        }
        return right_nodes;
        
    }
};

int main()
{
    struct TreeNode* root= new TreeNode(1);
    
    root->left             = new TreeNode(2); 
    root->right         = new TreeNode(3); 
    root->left->left     = new TreeNode(4); 
    root->left->right = new TreeNode(5);  
   
   Solution o;
   vector<int>result = o.rightSideView(root) ;
   for(auto i:result){
       cout<<i<<",";
   }
   
   

    return 0;
}
