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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     vector<vector<int>>results;
//     void helper(TreeNode* root, int level){
        
//         if(results.size()==level)
//             results.push_back({});
       
//         results[level].push_back(root->val);
//         if(root->left)
//             helper(root->left, level+1);
//         if(root->right)
//             helper(root->right, level+1);
//     }
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if(root!=NULL)
//             helper(root,0);
//         return results;
        
//     }
// };

//iterative - BFS
class Solution {
    
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>results;
        if(root==NULL)
            return results;
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            results.push_back({});
            //to pop out the elements of current level only
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                results[level].push_back(curr->val);
                q.pop();
            
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            
           }
            level++;
            
        }
        
        return results;
        
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
  
   vector<vector<int>>result=obj.levelOrder(root);

    return 0;
}
