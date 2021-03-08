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

//using Dfs to store child=parent information
// and BFS to find nodes at k distance from target
class Solution {
    map<TreeNode*, TreeNode*>parents;
    void dfs(TreeNode* root, TreeNode* parent){
        if(root!=NULL){
            parents.insert({root, parent});
            dfs(root->right, root);
            dfs(root->left, root);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, NULL);
        
        queue<TreeNode*>q;
        //to store level information
        q.push(NULL);
        q.push(target);
        
        set<TreeNode*>seen;
        
        seen.insert(target);
        seen.insert(NULL);
        
        int dist=0;
        // vector<int>ans;
        while(!q.empty()){
            TreeNode* curr_node=q.front();
            q.pop();
            //if current node is NULL means we have incremented by k distance
            // check if distance is equal to given distance
            if(curr_node==NULL){
                if(dist==K){
                    vector<int>ans;
                    while(!q.empty()){
                        ans.push_back(q.front()->val);
                        q.pop();
                    }
                    return ans;
                    
                }
                //add null at every increment in distance to keep a track of all the nodes at that distance
                q.push(NULL);
                dist++;
            }
            else{
                // else check left and right child node and parent if
               // it is already seen ->if not then add it into seen and queue
                if(seen.find(curr_node->left)==seen.end()){
                    seen.insert(curr_node->left);
                    q.push(curr_node->left);
                }
                if(seen.find(curr_node->right)==seen.end()){
                    seen.insert(curr_node->right);
                    q.push(curr_node->right);
                }
                if(seen.find(parents[curr_node])==seen.end()){
                    seen.insert(parents[curr_node]);
                    q.push(parents[curr_node]);
                }
            }
        }
        
        return {};
        
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
   TreeNode* target=  new TreeNode(2);
   int k=2;
   vector<int>ans=obj.distanceK(root, target, k);

    return 0;
}
