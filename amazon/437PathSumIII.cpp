/******************************************************************************
@author- Smriti Gupta
@date created- March 10, 21
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
    int count=0;
    int k;
    map<int,int>h;
    void preorder(TreeNode* node, int curr_sum){
        if(node==NULL)
            return ;
        //calculate the curr_sum till the current node from root node
        curr_sum+=node->val;
        
        //if curr_sum== k count the path
        if(curr_sum==k)
            count++;
        
        //also add the number of time the sum has already occured
        count+=h[curr_sum-k];
        
        //if the sum already occured- increment the count
        if(h.find(curr_sum)!=h.end()){
            h[curr_sum]++;
        }
        //else insert the curr_sum
        else{
            h.insert({curr_sum,1});
        }
        /*
        call the left and right nodes recursively
        it will call left till we reach last node and before coming back
        to go to right remove last node
        */
        preorder(node->left, curr_sum);
        preorder(node->right, curr_sum);
        
        //before checking other child remove the sum of first child
        //to do parallel subtree processing
        h[curr_sum]--;
        
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        k=sum;
        preorder(root,0);
        return count;
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
    int sum=5;
    cout<<obj.pathSum(root1, sum);


    return 0;
}
