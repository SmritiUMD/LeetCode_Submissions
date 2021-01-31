/******************************************************************************
@author- Smriti Gupta
@date created - January 30, 2021
*******************************************************************************/

//Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
    
};

class Solution {
    double diff=598675676636;
    int ans=0;
    vector<int>nums;
    private:
    void inorder(TreeNode* curr){
        if(!curr) return;
        inorder(curr->left);
        nums.push_back(curr->val);
        inorder(curr->right);
    }
    
    
public:
    int closestValue(TreeNode* curr, double target) {
        inorder(curr);
        for(int i=0;i<nums.size();i++){
            if(diff>abs(target-nums[i])){
               diff=abs(target-nums[i]);
               ans=nums[i];
            }
        }
        
        
       return ans; 
    }
};

int main()
{
    TreeNode* root= new TreeNode(4);
    root->left= new TreeNode(5);
    root->right= new TreeNode(2);
    root->left->left= new TreeNode(1);
    root->left->right= new TreeNode(3);
    
    double target=3.71;
    
    Solution obj;

    cout<<obj.closestValue(root, target);
    return 0;

}


