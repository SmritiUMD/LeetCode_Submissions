/******************************************************************************
@author - Smriti GUpta
@date created -November 5,20

*******************************************************************************/
#include<bits/stdc++.h> 

using namespace std;


class Solution {
    
vector<vector<int>>result;
private:
    void permutation(vector<int>temp, int end, int first){
        //set to keep a track of unique elements
        unordered_set<int>seen;
        if(end-1==first){
            result.push_back(temp);
        }
        else
        {
            for(int i=first;i<end;i++)
            {  
                // if i is in set - avoiding repeatative numbers
                if(seen.find(temp[i])==seen.end()){
                swap(temp[i],temp[first]);
                permutation(temp, end,first+1);
                swap(temp[i],temp[first]);
                //add the number in set to keep a track of numbers already counted
                seen.insert(temp[i]);
                //using this technique lead to some extra prmutations
                // while(i+1<end && temp[i]==temp[i+1]){
                //     i++;
                // }
                    
                }
                
            }
        }
    }
public:
 vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    permutation(nums,nums.size(), 0);
  
       return result;
       
        
    }
};

int main()
{
    vector<int>nums={1,1,2};
    Solution s;
    vector<vector<int>>result=s.permuteUnique(nums);
      
    for(int i=0;i<result.size();i++)
    {
        cout<<'{';
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j];
        }
        cout<<'}'<<endl;
    }

    return 0;
}
