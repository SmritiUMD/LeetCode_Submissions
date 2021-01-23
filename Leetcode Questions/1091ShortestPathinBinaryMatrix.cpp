/******************************************************************************
@author - Smriti Gupta
@date created - January 23,21
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>grid) {
        //creating a directory of possible moves
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
        
        if(grid[0][0]!=0 || grid[grid.size()-1][grid.size()-1]!=0) return -1;
        
        // cout<<dir[1].first<<dir[1].second;
        
        //BFS
        queue<pair<int,int>>q;
        grid[0][0]=1;
        q.push({0,0});
        int distance=0;
        
        while(!q.empty()){
            pair<int,int> curr=q.front();
            q.pop();
            int row=curr.first;
            int col=curr.second;
            distance=grid[row][col];
          
            if(row==grid.size()-1 && col==grid.size()-1) return distance ;
            
            for(int i=0;i<8;i++){
                int new_x=curr.first+dir[i].first;
                int new_y=curr.second+dir[i].second;
                
                if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid.size() && grid[new_x][new_y]==0 ){
                    //for every neighbour addiing current grid value +1 to calculate the distance
                    grid[new_x][new_y]=1+distance;    
                    q.push({new_x,new_y});
                
                }
                    
                
            }
        }
        
       return -1;
        
    }
};



int main()
{
   Solution s;
   vector<vector<int>>matrix={{0,1},{0,0}};
   
   cout<<s.shortestPathBinaryMatrix(matrix);

    return 0;
}
