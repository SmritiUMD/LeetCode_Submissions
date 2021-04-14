#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int val){
    this->val=val;
    }
};

  bool myComp( const vector<int>& v1,
           const vector<int>& v2 ){
    if(v1[0]==v2[0]){
        if(v1[1]==v2[1])
            return v1[2]<v2[2];
        else
            return v1[1]<v2[1];
    }
        else
            return v1[0]<v2[0];

  }

class Solution {
    
    vector<vector<int>>result;
    void BFS(TreeNode* root){
          queue<pair<TreeNode*,vector<int>>>q;
        int row=0;
        int column=0;
        q.push({root,{row,column}});
        while(!q.empty()){
           auto curr= q.front();
            q.pop();
            if(curr.first!=NULL){   
                result.push_back({curr.second[1], curr.second[0],curr.first->val});
                q.push({curr.first->left,{curr.second[0]+1, curr.second[1]-1}});
                q.push({curr.first->right,{curr.second[0]+1, curr.second[1]+1}});
            }      
    }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)
            return {{}};
        BFS(root);
        sort(result.begin(), result.end(), myComp);
        vector<int>currentcol;
        vector<vector<int>>output;
        int current_col_index=result[0][0];
        for(int i=0;i<result.size();i++){
            int col=result[i][0];
            int val=result[i][2];
            if(col==current_col_index){
               currentcol.push_back(val); 
            }
            else{
                output.push_back(currentcol);
                current_col_index=col;
                vector<int>x;
                currentcol=x;
                currentcol.push_back(val);
                
            }
            
        }
        output.push_back(currentcol);
        return output;
      
    }
};

int main(){

Solution obj;
TreeNode* node= new TreeNode(4);

obj.verticalTraversal(node);


}
