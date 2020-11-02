/******************************************************************************
@author-Smriti Gupta
@Date created- November2,20
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<int>>copy_board;
        copy_board=board;
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
                        if(new_ele==1)
                        {
                            live_neigh++;
                
                        }
                    }
                }
                    // cout<<live_neigh<<endl;
                    if(board[i][j]==1 && live_neigh<2)
                    {
                        copy_board[i][j]=0;
                    } 
                    if(board[i][j]==1 && live_neigh>3)
                    {
                        copy_board[i][j]=0;
                    }
                    if(board[i][j]==0 && live_neigh==3)
                    {
                        copy_board[i][j]=1;
                    }
                }
               
                
            }
            board=copy_board;
            cout<<"new"<<endl;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                     cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
        
        
       
    }
};

int main()
{
    vector<vector<int>>board={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution s;
    cout<<"previous"<<endl;
    for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                     cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    s.gameOfLife(board);
    

    return 0;
}
