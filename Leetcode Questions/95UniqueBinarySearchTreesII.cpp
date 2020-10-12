/******************************************************************************
@author- Smriti Gupta
@date created - October 12,2020

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    private:
    vector<TreeNode*> generate_trees(int start, int end) {
         vector<TreeNode*>all_trees;
        if(start>end){
            all_trees.push_back(NULL);
            return all_trees;
        }
    
        
        for(int i=start; i<=end;i++){
            vector<TreeNode*>left=generate_trees(start,i-1);
            vector<TreeNode*>right=generate_trees(i+1,end);
            
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* current_tree=new TreeNode(i);
                    current_tree->left=l;
                    current_tree->right=r;
                    all_trees.push_back(current_tree);
                }
            }
            
        }
      
        return all_trees;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>tree;
       if(n==0){
           return tree;
       }
       
        return generate_trees(1,n);
    }
    
   
};

int main()
{
    
   
    Solution obj;
    int n;
    cin>>n;
    obj.generateTrees(n);
    
   

    return 0;
}
