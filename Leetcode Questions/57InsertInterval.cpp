/******************************************************************************
@author- Smriti Gupta
@date created- October 23, 2020
*******************************************************************************/

#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    void insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());
        int index=0;
        vector<vector<int>>result;
        int start=newInterval[0];
        int end=newInterval[1];
        
        //insert all the elements that have first element less than the first element of newInterval
        while( index<intervals.size() && start>intervals[index][0] )
        {
            result.push_back(intervals[index++]);
        }
        
        //check if result in empty or the last element of last pair is less than the first element of the newInterval
        //insert as it is
        
        if(result.empty() || result[result.size()-1][1]<start)
        {
            result.push_back(newInterval);
        }
        
        //if not then replace the last element of the last pair with the maximum of that with the last element of newInterval
        else{
            result[result.size()-1][1]=max(result[result.size()-1][1],end);
        }
        // do the same thing for remaining elements 
        while(index<intervals.size()){
            auto interval=intervals[index++];
            int new_start=interval[0];
            int new_end=interval[1];
            if(result[result.size()-1][1]<new_start){
                result.push_back(interval);
            }
            else{
                result[result.size()-1][1]=max(result[result.size()-1][1], new_end);
            }
        }
        
        
        for(int i=0;i<result.size();i++)
        {
                cout<<"["<<result[i][0]<<","<<result[i][1]<<"]";
            
        }
    }
};


int main()
{
    vector<vector<int>>intervals={{1,3},{6,9}};
    vector<int>newInterval={2,5};
   Solution s;
   s.insert(intervals, newInterval);
    
   

    return 0;
}
