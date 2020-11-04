/******************************************************************************
@author - Smriti Gupta
@date created- November 4,20
*******************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

class Solution {
    vector<vector<int>>result;
private:
    
    void permutation(vector<int>temp, int end, int first){
        if(end==first){
            result.push_back(temp);
        }
        else
        {
            for(int i=first;i<=end;i++)
            {
                swap(temp[i],temp[first]);
                permutation(temp, end,first+1);
                swap(temp[i],temp[first]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int>temp;
    permutation(nums,nums.size()-1, 0);
     for(int i =0;i<result.size();i++)
        {
            for(int j=0;j<result[0].size();j++)
            {
                cout<<result[i][j];
            }
                cout<<endl;
            }
            
       return result;     
        
    }
};
        
int main()
{
    vector<int>nums={1,2,3};
    Solution obj;
    obj.permute(nums);
   

    return 0;
}
