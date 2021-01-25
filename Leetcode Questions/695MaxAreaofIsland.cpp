#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>grid;
    vector<vector<bool>>visited;
    
    int helper(int i, int j){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]!=0 && !visited[i][j]){
            visited[i][j]=true;
        }
        else{
            return 0;
        }
        return ( 1+ helper(i+1,j)+helper(i-1,j)+helper(i,j+1)+helper(i,j-1));
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid=grid;
        int ans=0;
         vector<vector<bool>>seen(grid.size(), vector<bool>(grid[0].size()));
        visited=seen;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=max(ans,helper(i,j));
            }
        }
      return ans;  
        
    }
};
int main(){

vector<vector<int>>grid={{0,0,0,0,0,0,0,0}};
Solution o;
cout<<o.maxAreaOfIsland(grid);
return 0;

};
