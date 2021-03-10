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

class Solution{
    int pre_idx=0;
    map<int,int>inorder_indx;
    vector<int>preorder;
    vector<int>inorder;
    
    TreeNode* helper(int left, int right){
        if(left==right)
            return NULL;
        
        int root_val=preorder[pre_idx];
        int index=inorder_indx[root_val];
        //creating a tree
        struct TreeNode* node=new TreeNode(root_val);
        //increment the index
        pre_idx++;
        //create left and right subtrees
        node->left=helper(left,index);
        node->right=helper(index+1, right);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder=preorder;
        this->inorder=inorder;
        int index=0;
        for(int i=0;i<inorder.size();i++){
          inorder_indx.insert({inorder[i],index++});  
        }
 
        return helper(0,inorder.size());
    }
};


int main()
{
    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    
    
    Solution obj;
    obj.buildTree(preorder, inorder);
    
    return 0;
}
