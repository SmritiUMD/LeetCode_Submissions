/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>freq;
        map<int,int>::iterator it;
        vector<int>result;
        priority_queue<pair<int,int>, vector<pair<int, int>>>pq;
        for(int i =0; i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(it=freq.begin(); it!=freq.end();it++){
            pq.push({it->second, it->first});
        }
        while(k>0){
           result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};
int main()
{

  Solution obj;
  vector<int>nums = {1,1,1,2,2,3};
  int k = 2;
  obj.topKFrequent(nums,k);
  
    return 0;
}
