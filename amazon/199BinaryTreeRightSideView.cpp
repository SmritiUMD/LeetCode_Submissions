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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL) return result;
        queue<TreeNode*>next_level;
        queue<TreeNode*>curr_level;
        next_level.push(root);
        
        //declaring the variable here so that it will keep the last value after 
        // the current queue is empty
        TreeNode* node=NULL;
        
        while(!next_level.empty()){
            curr_level=next_level;
            while(!next_level.empty()){
                next_level.pop();
            }
            while(!curr_level.empty()){
                node=curr_level.front();
                curr_level.pop();
                if(node->left) next_level.push(node->left);
                if(node->right) next_level.push(node->right);
            }
            //if current level is empty that means node is the last node
            if(curr_level.empty()){
                result.push_back(node->val);
            }
            
        }
        return result;
        
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
    vector<int>result=obj.rightSideView(root1);

    return 0;
}
