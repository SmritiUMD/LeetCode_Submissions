/******************************************************************************
@author- Smriti Gupta
@date created- February 1,21
*******************************************************************************/

/**A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it.
If such an index does not exist, return -1.
**/

#include <bits/stdc++.h>

using namespace std;


 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 
class BinaryMatrix
{
    private: 
    
    vector<vector<int>>binaryMatrix;
    
public:

    BinaryMatrix(matrix)
    {
        this->binaryMatrix=matrix;
    } 
    
     int get(int row, int col)
     {
         return binaryMatrix[row][col];
     }
     
     vector<int> dimensions(){
         return {binaryMatrix.size(),binaryMatrix[0].size()};
     }
 };
 

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix* binaryMatrix) {
     
        int row=binaryMatrix.dimensions()[0];
        int col=binaryMatrix.dimensions()[1];
        int smallestIdx=col;
        for(int i=0;i<row;i++){
            int low=0;
            int hi=col-1;
            while(low<hi){
                int mid=(low+hi)/2;
                if(binaryMatrix.get(i,mid)==0){
                    low=mid+1;
                }
                else{
                    hi=mid;
                }
            }
            if(binaryMatrix.get(i,low)==1){
                smallestIdx=min(smallestIdx,low);
            }
        
        }
        return smallestIdx==col ? -1:smallestIdx;
    } 
};


int main(){
    vector<vector<int>mat={{0,0},{0,1}};
    
BinaryMatrix o(mat);
Solution obj;
cout<<obj.leftMostColumnWithOne(binaryMatrix);

 return 0;
 
}

 

