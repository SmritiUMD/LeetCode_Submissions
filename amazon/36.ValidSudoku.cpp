/******************************************************************************
@author - Smriti Gupta
@date created- March 7,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //map row number with the indivisual numbers and their frequencies 
        map<int,map<int,int>>rows;
        map<int,map<int,int>>columns;
        map<int,map<int,int>>boxes;
        for(int i=0;i<9;i++){
            rows.insert({i,{}});
            columns.insert({i,{}});
            boxes.insert({i,{}});
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num!='.'){
                    int n=int(num);
                    int box_index=(i/3)*3+j/3;
                    if(rows[i].find(n)!=rows[i].end()){
                        rows[i][n]++;
                    }
                    else{
                        rows[i].insert({n,1});
                    }
                    if(columns[j].find(n)!=columns[j].end()){
                        columns[j][n]++;
                    }
                    else{
                        columns[j].insert({n,1});
                    }
                    if(boxes[box_index].find(n)!=boxes[box_index].end()){
                        boxes[box_index][n]++;
                    }
                    else{
                        boxes[box_index].insert({n,1});
                    }
                
                if(rows[i][n]>1 || columns[j][n]>1 || boxes[box_index][n]>1){
                    return false;
                }
                }
            }
        }
        return true;
        
    }
};
int main()
{
    vector<vector<char>>board; 

    Solution  obj;
    cout<<obj.isValidSudoku(board);
    
    return 0;
}
