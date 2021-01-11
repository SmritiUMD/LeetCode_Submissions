/******************************************************************************
@author - Smriti Gupta
@date created - January 11,21

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int r1=0;
        int c1=0;
        int r2=matrix.size()-1;
        int c2=matrix[0].size()-1;
        while(r1<=r2 && c1 <=c2){
            for(int c = c1; c<=c2;c++){
                result.push_back(matrix[r1][c]);
            }
            for(int r=r1+1; r<=r2 ; r++){
                result.push_back(matrix[r][c2]);
            }
            if(r1< r2 && c1< c2){
            for(int c=c2-1; c>c1;c--){
                result.push_back(matrix[r2][c]);
            }
            for(int r=r2; r>r1 ;r--){
                result.push_back(matrix[r][c1]);
            }
            }
            r1++;
            c1++;
            r2--;
            c2--;
        }
        return result;
        
    }
};

int main()
{
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    
    Solution object;
    
    vector<int>result=object.spiralOrder(matrix);
    cout<<"[";
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<",";
    }

    cout<<"]";
    return 0;
}
