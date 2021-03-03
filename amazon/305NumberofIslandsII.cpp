/******************************************************************************
@author -Smriti Gupta
@date created- March 3,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<bool>>visited;;
    
      void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size()) return;
        if(j<0 || j>=grid[0].size() ) return;
        if(grid[i][j]=='0'|| visited[i][j] ) return;
       
   
     visited[i][j]=true;
     dfs(grid, i+1,j);
     dfs(grid, i-1, j);
     dfs(grid,i,j+1);
     dfs(grid,i,j-1);
        
     }
    int numIslands(vector<vector<char>>& grid) {
        int number_of_islands=0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        visited=vis;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ++number_of_islands;
                   dfs(grid,i,j);
                    
                }
            }
        }
        
      return number_of_islands;  
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int>ans;
        vector<vector<char>>grid(m,vector<char>(n,'0'));
        for(auto pos:positions){
            grid[pos[0]][pos[1]]='1';
            ans.push_back(numIslands(grid));
            
        }
        return ans;
        
    }
};

int main()
{
   Solution obj;
   int m = 3;
   int n = 3;
   vector<vector<int>>positions = {{0,0}, {0,1}, {1,2}, {2,1}};
   vector<int>result=obj.numIslands2(m,n,positions);
   for(int i=0;i<result.size();i++){
       cout<<result[i]<<",";
   }

    return 0;
}
