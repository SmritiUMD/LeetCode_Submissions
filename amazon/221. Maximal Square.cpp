/******************************************************************************
@author - Smriti Gupta
@date created - March 16,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=rows>0 ? matrix[0].size() : 0;
        vector<vector<int>>dp(rows+1, vector<int>(cols+1,0));
        
        int max_side=0;
        
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    max_side=max(max_side,dp[i][j]);
                }
            }
        }
       return max_side*max_side; 
        
    }
};

int main()
{
    Solution obj;
   
    vector<vector<char>>matrix={{"0","1"},{"1","0"}};
    obj.maximalSquare(matrix);
    

    return 0;
}
