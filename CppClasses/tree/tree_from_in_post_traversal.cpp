/******************************************************************************
@author-Smriti Gupta
@date created- January 20,21

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;



 struct TreeNode {
     
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int data){
         this->val=data;
         left=NULL;
         right=NULL;
         
     }
     };
 
 
class Solution {
    int post_idx=0;
    int index=0;
    vector<int> postorder;
    vector<int>inorder;
    map<int,int>inorder_idx;
    
    TreeNode* helper(int left, int right){
        if(left>right){
            return NULL;
        }
      int root_val=postorder[post_idx];
      int index=inorder_idx[root_val];
      struct TreeNode* root=new TreeNode(root_val);
      //recursion to make subtrees
        post_idx--;
        
        root->right=helper(index+1, right);
        root->left=helper(left, index-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder=postorder;
        this->inorder=inorder;
    
        post_idx=postorder.size()-1;
        index=0;
        for(int i=0;i<inorder.size();i++){
            inorder_idx.insert({inorder[i],index});
            index++;
        }
        
       return helper(0,inorder.size()-1); 
    }
};


void printTree(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    int index=0;
    while(!q.empty()){
        TreeNode* curr=q.front();
        cout<<curr->val<<' ';
        q.pop();
        if(q.empty()){
            cout<<endl;
        }
        if(curr->left) {
            q.push(curr->left);
            index++;
        }
        if(curr->right) {
            q.push(curr->right);
            index++;
        }
        
    }
}


int main()
{
    Solution o;
    vector<int>inorder = {9,3,15,20,7};
    vector<int>postorder = {9,15,7,20,3};
    
    printTree(o.buildTree(inorder, postorder));

    return 0;
}
