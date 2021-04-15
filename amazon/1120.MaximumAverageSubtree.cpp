/******************************************************************************
@author - Smriti Gupta
@date created - April 14, 2021

*******************************************************************************/

#include <iostream>

using namespace std;



 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 };
 
class Solution {
    struct State{
        int count;
        int sum;
        double maxAverage;
    };
    State maxAverage(TreeNode* root){
        if(!root)
            return {0,0,0};
        State left=maxAverage(root->left);
        State right=maxAverage(root->right);
        
        int count=left.count+right.count+1;
        int sum=left.sum+right.sum+root->val;
        double maxAverage= max((1.0 *(sum)/count), max(left.maxAverage, right.maxAverage));
        return {count, sum, maxAverage};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        return maxAverage(root).maxAverage;
    }
};
int main()
{
   Solution obj;
   TreeNode* root= new TreeNode(3);
   obj.maximumAverageSubtree(root);
   

    return 0;
}
