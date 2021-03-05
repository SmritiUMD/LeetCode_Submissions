/******************************************************************************
@author - Smriti Gupta
@date created - March 5, 2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool result;
    void helper(vector<int>& arr, int i){
        if(i<0 || i>=arr.size() || arr[i]<0)
            return ;
        //mark values as visited
        arr[i]=-arr[i];
        if(arr[i]==0){
            result=true;
            return ;
        }
        helper(arr, i+arr[i]);
        helper(arr,i-arr[i]);
        
    }
public:
    bool canReach(vector<int>& arr, int start) {
        result=false;
        helper(arr, start);
        return result;
        
        
    }
};
 
int main()
{
    Solution obj;
    vector<int>arr = {5,7,0,8,8,10};
    int start = 5;
   
    bool result=obj.canReach(arr, start);
    cout<<result;

    return 0;
}
