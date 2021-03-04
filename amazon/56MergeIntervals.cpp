/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1 || intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        for(int i=0;i<intervals.size();i++){
            int s=result.size();
            if(s==0 || result[s-1][1]<intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result[s-1][1]=max(result[s-1][1],intervals[i][1]);
            }
            
                                 
                                 
        }
     return result;
        
    }
};
int main()
{
    Solution obj;
    vector<vector<int>>intervals={{1,3},{2,6},{8,10},{15,18}};
    obj.merge(intervals);

    return 0;
}
