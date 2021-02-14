/******************************************************************************
@author - Smriti Gupta
@date created - Feb 14, 2021

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        cout<<fresh;
        int min=-1;
        q.push({-1,-1});
        
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            if(curr.first==-1 && curr.second==-1){
                min++;
                if(!q.empty()) q.push({-1,-1});
                continue;
            }
            
            for(int i=0;i<dir.size();i++){
                int x=curr.first+dir[i].first;
                int y=curr.second+dir[i].second;
                
                
                if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                    if(grid[x][y]==1){
                        grid[x][y]=2;
                        fresh--;
                        q.push({x,y});
                    }
                }
                
            }
            
        }
        return fresh==0? min:-1;
        
    }
};



int main()
{
   Solution obj;
   vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
   cout<<"minutes elapsed - "<<obj.orangesRotting(grid)<<endl;

    return 0;
}
