/******************************************************************************
@author- Smriti Gupta
@date created - March 12, 21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Time Complexity: O(N⋅3^L) where N is the number of cells in the board and L is the length of the word to be matched.
    3 beacuse we have 3 choices , we cant go back.
    For worst case- N times backtrcking function will be called.
    Space- O(L)- to store word
    
    
    
    
    */

    private:
    bool backtrack(vector<vector<char>>& board,int i, int j, string& word, int index){
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        if(index>=word.size()){
            return true;
        }
        if(i<0 || i==rows || j<0 || j==cols ||board[i][j]!=word.at(index) ){
            return false;
            
        }
        bool visited=false;
        board[i][j]='X';
        for(int k=0;k<4;k++){
            visited=backtrack(board,i+dir[k][0], j+dir[k][1], word, index+1);
            if(visited){
                // we are breaking out here, because the marked letters will remain like that for remaining calls
                break;
            }
        }
        // restoring the board before next recursive call
        board[i][j]=word.at(index);
        return visited;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(board,i,j,word,0))
                    return true;
                
            }
            
        }
         return false;
        
    }
};

int main()
{
   vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
   string word = "ABCCED";
   Solution obj;
   obj.exist(board, word);

    return 0;
}
