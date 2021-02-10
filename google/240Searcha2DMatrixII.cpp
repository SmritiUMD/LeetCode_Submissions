/******************************************************************************
@author - Smriti Gupta
@date created -Feb 10,21

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int col=0;
        //we are starting from bottomm left corner
        //since matrix is sorted row wise and col -wise we can reduce computation 
        while(row>=0 && col<matrix[0].size()){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                row--;
            else
                col++;
        }
        return false;
        
    }
};
// O(m+n) - time complexity
// O(1) - space



int main()

{
    vector<vector<int>>matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target =20;
    Solution obj;
    cout<<obj.searchMatrix(matrix , target)<<endl;
    
    

    return 0;
}
