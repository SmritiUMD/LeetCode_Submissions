/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
/*
Using sets to keep a track of unique shapes of islands.
To store shapes, I am storing relative distances of neighbours from current node.
*/

class Solution {
    vector<vector<int>>grid;
    vector<vector<bool>>seen;
    //to keep a track of the node currently visiting
    int curr_row;
    int curr_col;
    set<pair<int,int>>curr_Island;
private:
    void dfs(int i, int j){
        if(i<0|| i>=grid.size() || j<0 || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==0 || seen[i][j])
            return ;
        seen[i][j]=true;
        cout<<i-curr_row<<","<<j-curr_col<<endl;
        //store relative distance of neighbours from the visiting node
        curr_Island.insert({i-curr_row, j-curr_col});
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        this->grid=grid;
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(),false));
        seen=vis;
        set<set<pair<int,int>>>islands;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //for every node initialize curr_row and curr_col
                    this->curr_row=i;
                    this->curr_col=j;
                    this->curr_Island={};
                    dfs(i,j);
                    if(!curr_Island.empty())
                        islands.insert(curr_Island);
                    
                
            }
        }
        
       return islands.size(); 
        
    }
};
int main()
{
    Solution obj;
    vector<vector<int>>grid={{1,1,0,0,0},
                              { 1,1,0,0,0},
                              { 0,0,0,1,1},
                              {0,0,0,1,1}};
    
    cout<<obj.numDistinctIslands(grid);

    return 0;
}
