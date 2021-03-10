/******************************************************************************
@author - Smriti GUpta
@date created - March 10, 21

*******************************************************************************/

#include <bits/stdc++.h>

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
    TreeNode* flattenTree(TreeNode* root){
        if(root==NULL)
            return root;
        
        if(root->left == NULL && root->right == NULL)
            return root;
        
        TreeNode* leftTail= flattenTree(root->left);
        TreeNode* rightTail=flattenTree(root->right);
        
        //if there is left child so add it to right tail
        // and make left child NULL
        if(leftTail!=NULL){
            leftTail->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        return rightTail==NULL? leftTail:rightTail;
    }
public:
    void flatten(TreeNode* root) {
        flattenTree(root);
        
    }
};



int main()
{
    struct TreeNode* root1= new TreeNode(1);
    
    root1->left             = new TreeNode(2); 
    root1->right         = new TreeNode(3); 
    root1->left->left     = new TreeNode(4); 
    root1->left->right = new TreeNode(5);  
    
    Solution obj;
    obj.flatten(root1);
    
    return 0;
}
