/******************************************************************************
@author- Smriti Gupta
@date created -January 14,21

*******************************************************************************/

#include <iostream>

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

void postorder(TreeNode* root){
    if(!root) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<",";
    
}

void inorder(TreeNode* root){
    if(!root) return;
    
    inorder(root->left);
    cout<<root->val<<",";
    inorder(root->right);
}

int main()
{
    struct TreeNode* root= new TreeNode(1);
    
    root->left             = new TreeNode(2); 
    root->right         = new TreeNode(3); 
    root->left->left     = new TreeNode(4); 
    root->left->right = new TreeNode(5);  
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<endl;
    
    cout<<"preorder"<<endl;
    preorder(root);
    cout<<endl;
    
    cout<<"postorder"<<endl;
    postorder(root);
    
    

    return 0;
}
