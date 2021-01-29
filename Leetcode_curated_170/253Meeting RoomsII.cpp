#include <bits/stdc++.h>

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>start_time;
        vector<int>end_time;
        if(intervals.size()==0) return 0;
        for(int i=0; i<intervals.size();i++){
            start_time.push_back(intervals[i][0]);
            end_time.push_back(intervals[i][1]);
        }
        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());
        
        int used_rooms=0;
        
        int start_ptr=0;
        int end_ptr=0;
        
        //we will check if the current start time of meeting is greater than the last meeting time so we can reuse the room
        while(start_ptr<intervals.size()){
            if(start_time[start_ptr]>=end_time[end_ptr]){
                used_rooms-=1;
                end_ptr+=1;
            }
            // otherwise we need to take another room
            used_rooms+=1;
            start_ptr+=1;
        }
        return used_rooms;
        
    }
};

int main(){
Solution obj;
vector<vector<int>>intervals={{0,30},{5,10},{15,20}};
cout<<obj.minMeetingRooms(intervals);
};
//O(Nlogn)- sorting arrays and cosidering N intervals
