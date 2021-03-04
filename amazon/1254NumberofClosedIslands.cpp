/******************************************************************************
@author -Smriti Gupta
@date created- March 3,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   bool dfs(vector<vector<int>>& grid, int i, int j){
     //checking for water and already visited nodes return true
        if(grid[i][j]==1 || grid[i][j]==-1)
            return true;
        //if the 0 lies on boundary return false
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)
            return false;
       //mark the node as visited
        grid[i][j]=-1;
     //run DFS for 4 directions if dfs exists than it is closed island
        bool left=dfs(grid,i,j-1);
        bool right=dfs(grid,i,j+1);
        bool up=dfs(grid,i-1,j);
        bool down=dfs(grid,i+1,j);
        return left && right && up && down;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int counter=0;
        
       for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                
                if(grid[i][j]==0 && dfs(grid, i,j))
                        counter++;
                }
        }
        return counter;
    }
};

int main()
{
   Solution obj;
   
   vector<vector<int>>grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
                             
   cout<<obj.closedIsland(grid);
   
    return 0;
}
