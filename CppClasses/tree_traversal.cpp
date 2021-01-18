/******************************************************************************
@author- Smriti Gupta
@date created- January 18,2021
*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

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
void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<",";
    preorder(root->left);
    preorder(root->right);
}

void preorder_it(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    s.push(curr);
    while(!s.empty()){
        curr=s.top();
        s.pop();
        cout<<curr->val<<".";
        if(curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
        
    }
}

void postorder(TreeNode* root){
    if(!root) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<",";
    
}

void postorder_it(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> s1;
    
    stack<TreeNode*>s2;
    
    TreeNode* curr = root;
    s1.push(curr);
    while(!s1.empty()){
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left) s1.push(curr->left);
        if(curr->right) s2.push(curr->right);
    }
    while(!s2.empty()){
        curr=s2.top();
        s2.pop();
        cout<<curr->val<<",";
    }
    
    
}

void inorder(TreeNode* root){
    if(!root) return;
    
    inorder(root->left);
    cout<<root->val<<",";
    inorder(root->right);
}

void inorder_it(TreeNode* root){
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(!s.empty() || curr){
        while(curr){
            s.push(curr);
            // cout<<curr->val;
            curr=curr->left;
        }
        curr=s.top();
        cout<<curr->val<<",";
        s.pop();
        curr=curr->right;
    }
}

int main()
{
    struct TreeNode* root= new TreeNode(1);
    
    root->left             = new TreeNode(2); 
    root->right         = new TreeNode(3); 
    root->left->left     = new TreeNode(4); 
    root->left->right = new TreeNode(5);  
    cout<<"Inorder recursive"<<endl;
    inorder(root);
    cout<<endl;
    
    cout<<"Inorder Iterative"<<endl;
    inorder_it(root);
    cout<<endl<<endl;
    
    cout<<"preorder recursive"<<endl;
    preorder(root);
    cout<<endl;
    
    cout<<"Preorder Iterative"<<endl;
    preorder_it(root);
    cout<<endl<<endl;
    
    cout<<"postorder recursive"<<endl;
    postorder(root);
    cout<<endl;
     
    cout<<"Postorder Iterative"<<endl;
    postorder_it(root);
    cout<<endl;
    
    

    return 0;
}
