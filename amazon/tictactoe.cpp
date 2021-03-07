/******************************************************************************
@author - Smriti Gupta
@date created- March 7,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int>>game;
    int n;
    TicTacToe(int n) {
        this->game.resize(n,vector<int>(n,INT_MAX));
        this->n=n;
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        game[row][col]=player;
        int i=0;
        while(i<n){
            // cout<<i<<col<<endl;
            if(game[i][col]==player)
                i++;
            else{
                break;
            }
        }
        // cout<<i;
        if(i==n){
            // cout<<player;
            return player;
        }
        i=0;
        while(i<n){
            if(game[row][i]==player)
               i++;
            else
                break;
        }
        if(i==n)
            return player;
        
       return 0; 
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
int main()
{
    int n= 3;
    TicTacToe obj(n);
    vector<vector<int>>moves= {{0, 0, 1}, {0, 2, 2}, {2, 2, 1}, {1, 1, 2}, {2, 0, 1}, {1, 0, 2}}; 

    
    cout<<"moves 1 " << "moves 2"<< " player name "<<"player won"<<endl;
    for(int i=0;i<moves.size();i++){
        cout<<moves[i][0]<<"   "<<moves[i][1]<<"   "<<moves[i][2]<<"   "<<obj.move(moves[i][0],moves[i][1],moves[i][2])<<endl;
    }
    
    return 0;
}
