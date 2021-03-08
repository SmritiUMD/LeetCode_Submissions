/******************************************************************************
@author - Smriti Gupta
@date created - March 8, 21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


//  /Definition for a binary tree node.
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
    
//     Passing NULL to int will cast NULL to 0 in integer.
// So, It will give wrong result for [0, null, -1].
// If someone will pass INT_MIN as default value, then It'll fail for case - [-2147483648] and vice-versa.
// That's why pointers are used here.
// One can use TreeNode addresses as pointers.
    private:
//     bool helper(TreeNode* curr, int* low, int* high){
//         if(curr==NULL){
//             return true;
//         }
//         if((low && curr->val<=*low) || (high && curr->val >=*high)){
//             return false;
//         }
        
//         return helper(curr->left, low, &(curr->val)) && helper(curr->right, &(curr->val), high);
        
        
//     }
    
//     public:
     
//     bool isValidBST(TreeNode* root) {
        
//         if(!root)
//             return true;
//         else{
//             return helper(root,NULL, NULL);
//         }
//         return true;
//     }
// };
    
    
//     //inorder iterative

    
    public:
    bool isValidBST(TreeNode* root){
        int* prev=NULL;
        stack<TreeNode*>s;
        
        TreeNode* curr=root;
        while(!s.empty() || curr){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            if(prev!=NULL  && curr->val<=*prev ){
                return false;
            }
            else{
                prev=&(curr->val);
                curr=curr->right;
            }
            
            
        }
        return true;
        
        
    }
};



int main()
{
    struct TreeNode* root= new TreeNode(1);
    
    root->left             = new TreeNode(2); 
    root->right         = new TreeNode(3); 
    root->left->left     = new TreeNode(4); 
    root->left->right = new TreeNode(5);  
   
   Solution obj;
  
   cout<<obj.isValidBST(root);

    return 0;
}
