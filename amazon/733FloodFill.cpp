/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <bits/stdc++.h>
/*
Using Dfs to solve the problem.
If the neighbour cells have same color as starting cell, then change it to given color.

*/

using namespace std;

class Solution {
    vector<vector<int>>grid;
    int newColor;
    int start;
    void dfs(int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return ;
        if(grid[i][j]!=start )
            return ;
        if(grid[i][j]==start)
            grid[i][j]=newColor;
        
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        grid=image;
        this->newColor=newColor;
        this->start=grid[sr][sc];
        //if the color of starting point is same than return the grid
        if(grid[sr][sc]==newColor)
            return grid;
        dfs(sr,sc);
        
        return grid;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>>grid={{1,1,0,0,0},
                               { 1,1,0,0,0},
                               { 0,0,0,1,1},
                               {0,0,0,1,1}};
    int sr=1;
    int sc=1;
    int newColor=4;
    
    vector<vector<int>>result=obj.floodFill(grid, sr, sc, newColor);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }

    return 0;
}
