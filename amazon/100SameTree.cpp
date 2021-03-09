/******************************************************************************
@author - Smriti Gupta
@date created - March 9, 21

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
    bool check(TreeNode* p, TreeNode* q){
           if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val==q->val)
            return true;
    return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>p_;
        queue<TreeNode*>q_;
        p_.push(p);
        q_.push(q);
        while(!q_.empty()||!p_.empty()){
            TreeNode* one=p_.front();
            p_.pop();
            TreeNode* two=q_.front();
            q_.pop();
            if(!check(one,two))
                return false;
            if(p){
                if(!check(one->left,two->left))
                        return false;
                if(one->left){
                    p_.push(one->left);
                    q_.push(two->left);
                }
                if(!check(one->right, two->right))
                        return false;
                if(one->right){
                    p_.push(one->right);
                    q_.push(two->right);
                }
            }
            
        }
        
      return true;  
        
    }
};

int main()
{
    struct TreeNode* root1= new TreeNode(1);
    
    root1->left             = new TreeNode(2); 
    root1->right         = new TreeNode(3); 
    root1->left->left     = new TreeNode(4); 
    root1->left->right = new TreeNode(5);  
   
   struct TreeNode* root2= new TreeNode(1);
    
    root2->left             = new TreeNode(2); 
    root2->right         = new TreeNode(3); 
    root2->left->left     = new TreeNode(4); 
    root2->left->right = new TreeNode(5);  
    Solution obj;
  
    cout<<obj.isSameTree(root1, root2);

    return 0;
}
