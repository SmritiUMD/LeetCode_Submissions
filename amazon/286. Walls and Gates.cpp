/******************************************************************************
@author - Smriti Gupta
@date created - March 16,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    int empty=INT_MAX;
    int gate=0;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size()==0)
            return ;
        int rows=rooms.size();
        int cols=rooms[0].size();
        queue<vector<int>>q;
        vector<pair<int,int>>dir={{-1,0}, {0,-1},{1,0},{0,1}};
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j]==gate){
                    q.push({i,j});
                }
            }
        }
        //BFS
        while(!q.empty()){
            int new_r=q.front()[0];
            int new_c=q.front()[1];
            q.pop();
            for(auto x:dir){
                int r=new_r+x.first;
                int c=new_c+x.second;
                if(r<0 || c<0 || r>=rows || c>=cols || rooms[r][c]!=empty){
                    continue;
                }
                rooms[r][c]=rooms[new_r][new_c]+1;
                q.push({r,c});
            }
        }
        
        
        
    }
};
int main()
{
    Solution obj;
   
    vector<vector<int>>rooms={{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    obj.wallsAndGates(rooms);
    

    return 0;
}
