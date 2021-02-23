/******************************************************************************
@author - Smriti Gupta
@date created- Feb 23, 21

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};


class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int open=0;
        int close=1;
        vector<vector<int>>events;
        for(int i=0;i<schedule.size();i++){
            for(Interval id:schedule[i]){
            //storing start time with open tag
            // and end time with close tag
            events.push_back({id.start,open});
            events.push_back({id.end,close});
            }
        }
        
        sort(events.begin() ,events.end());
        vector<Interval>ans;
        int prev=-1;
        int bal=0;
        //for open- update bal +=1
        //and for close- update bal-=1
        //add the intervals with bal 0  with last time stamp to final ans
        for(auto i : events){
            if(bal==0 && prev >=0){
                ans.push_back({prev,i[0]});
                
            }
            bal+=i[1]==open ? 1:-1;
            prev=i[0];
        }
        return ans;
        
    }
};



int main()
{
   
   Solution s;
   vector<vector<Interval>>intervals={{{1,2},{5,6}},{{1,3}},{{4,10}}};
   
   vector<Interval>result=s.employeeFreeTime(intervals);
   for(auto i:result){
       cout<<i.start<<","<<i.end<<endl;
   }

    return 0;
}
