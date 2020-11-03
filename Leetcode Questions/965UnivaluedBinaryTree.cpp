/******************************************************************************
@author- Smriti Gupta
@date created- November 3,20
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode(int data) 
        { 
            val = data; 
      
            // Left and right child for node 
            // will be initialized to null 
            left = NULL; 
            right = NULL; 
        } 
}; 
    
class Solution {
    vector<int>vals;
    private:
    
    //dfs to go till end and store the last val in vector
    void dfs(TreeNode* root)
    {
        if(root)
        {
            vals.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
            
    }
public:
    bool isUnivalTree(TreeNode* root)
    {
        vector<int>val;
        //run dfs
        dfs(root);
        for(int i=0;i<vals.size();i++)
        {
            if(vals[i]!=vals[0]) return false;
        }
       
       return true;
        
    }
};

int main()
{
struct TreeNode* root= new TreeNode(1);
root=new TreeNode(1);
root->left=new TreeNode(1);
root->right=new TreeNode(1);
root->left->left=new TreeNode(1);
root->left->right=new TreeNode(1);
root->right->left=new TreeNode(1);

Solution s;
if(s.isUnivalTree(root))
{
    cout<<"true";
}
else
{
    cout<<"false";
}

    return 0;
}
