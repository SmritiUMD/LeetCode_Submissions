/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int result=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    result+=4;
                //checking the left side of the current cell
                if(i>0 && grid[i-1][j]==1){
                    result-=2;
                }
                //checking the upper cell of the current cell
                if(j>0 && grid[i][j-1]==1){
                    result-=2;
                }
            }
            }
        }
        return result;
        
    }
};
int main()
{
    Solution obj;
    vector<vector<int>>grid={{1,1,0,0,0},
                               { 1,1,0,0,0},
                               { 0,0,0,1,1},
                                {0,0,0,1,1}};
    
    cout<<obj.islandPerimeter(grid);

    return 0;
}
