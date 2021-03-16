/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        
        //making in place changes by manipulating the values of the cells
        // sign of the value will show it was live or dead now and their magnitude will tell the their status before.
        // for 0->1 - make it 2
        // for 1->0 make it -1
        vector<pair<int,int>>neigh={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,1},{1,0}};
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int live_neigh=0;
                for(int k=0;k<neigh.size();k++){
                    int new_x=i+neigh[k].first;
                    int new_y=j+neigh[k].second;
                    // cout<<'('<<new_x<<new_y<<')';
                    
                    if(new_x<r && new_y<c && new_x>=0 && new_y>=0 ) 
                    {
                         // cout<<'('<<"y"<<new_x<<new_y<<')';
                        int new_ele=board[new_x][new_y];
                        //take abs value as -1 means it was live before
                        if(abs(new_ele)==1)
                        {
                            live_neigh++;
                
                        }
                    }
                }
                // for 0->1 - make it 2
                // for 1->0 make it -1
                    // cout<<live_neigh<<endl;
                    
                    if(board[i][j]==1 && live_neigh<2)
                    {
                        //means it was live before
                        board[i][j]=-1;
                    } 
                    if(board[i][j]==1 && live_neigh>3)
                    {
                        board[i][j]=-1;
                    }
                    if(board[i][j]==0 && live_neigh==3)
                    {
                        //2 means it was dead before
                        board[i][j]=2;
                    }
                }
               
                
            }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]>0){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
        
        
       
    }
};


int main()
{
    Solution obj;
    vector<vector<int>>board= {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    obj.gameOfLife(board);
  
    return 0;
}
