/******************************************************************************
@author -Smriti Gupta
@date created-January 30,2021
*******************************************************************************/
//In In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

//A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction,
//then one square in an orthogonal direction. Find minimum number of moves to reach given coordinates

#include <bits/stdc++.h>

class Solution {
    //limiting the exploration by diving my search into 4 quadrants
    private:
    int Quadrant(int x, int y, pair<int, int> pairs){
        if(x-pairs.first>=0 && y-pairs.second>=0) // 1st Quadrant
            return 0;
        else if(x-pairs.first<0 && y-pairs.second>=0) // 2nd Quadrant
            return 2;
        else if(x-pairs.first<0 && y-pairs.second<0) // 3rd Quadrant
            return 4;
        else return 6; // 4th Quadrant
        
    }
public:
    int minKnightMoves(int x, int y) {
        if((x==1 || x==-1) &&( y==1 || y==-1)) return 2;
        //quandrant wise arrangement
        vector<pair<int,int>>dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
        queue<vector<int>>q;
        q.push({0,0,0});
        int moves=1;
        set<pair<int,int>>visited;
        visited.insert({0,0});
        //BFS
        while(!q.empty()){
            //running 
            // for(int j=0;j<q.size();j++){
            vector<int>curr=q.front();
            
            q.pop();
            if(curr[0]==x && curr[1]==y) return curr[2];
            int quad=Quadrant(x,y,{curr[0], curr[1]});
            
            for(int i=quad;i<quad+2;i++){
                int new_x=dir[i].first+curr[0];
                int new_y=dir[i].second+curr[1];
                cout<<new_x<<" "<<new_y<<endl;
            
                if((visited.find(pair<int,int>(new_x,new_y)))==visited.end()){
                    //incrementing distance here to remove the additional need of for loop for iterating over same order or same step
                    q.push({new_x,new_y,curr[2]+1});
                    visited.insert({new_x,new_y});
                    
                    
                }
            }
        
        }
        return -1;
        
    }
};

int main(){

Solution obj;
cout<<obj.minKnightMoves(5,5);
};
