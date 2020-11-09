/******************************************************************************
@author- Smriti Gupta
@date created- November 9,20
*******************************************************************************/

#include<bits/stdc++.h>

using namespace std;

class Solution {

    private:
        bool backtrack(int i, int j, int index);
    public:
    vector<vector<char>>board;
    string word;
    Solution(vector<vector<char>>& board, string& word);
    bool exist();

    
};

    Solution::Solution(vector<vector<char>>& y, string& x): board(y),word(x)
    {
        
    }
    bool Solution::backtrack(int i, int j, int index){
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
            visited=backtrack(i+dir[k][0], j+dir[k][1], index+1);
            if(visited){
                break;
            }
        }
        board[i][j]=word.at(index);
        return visited;
        
    }

    bool Solution::exist() {
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(i,j,0))
                    return true;
                
            }
            
        }
         return false;
        
    }


int main()
{
    vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution s(board, word);
    cout<<s.exist();

    return 0;
}
