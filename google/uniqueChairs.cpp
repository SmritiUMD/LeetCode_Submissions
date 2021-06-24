/******************************************************************************
@author - Smriti Gupta
@date created  - June 24, 21

*******************************************************************************/

#include <bits/stdc++.h>


using namespace std;
 
int uniqueChairs(vector<int>&startTime, vector<int>&endTime){
    vector<pair<int,int>>times;
    for(int i = 0;i<startTime.size();i++){
        times.push_back({startTime[i], endTime[i]});
    }
    sort(times.begin(), times.end());
    priority_queue <int, vector<int>, greater<int> > pq;   
    pq.push(times[0].second);
    
    for(int i=1; i<times.size();i++){
        if(times[i].first>=pq.top())
            pq.pop();
        pq.push(times[i].second);
    
    }
   
    return pq.size();
}

int main()
{
    vector<int>startTime={1, 2, 6, 5, 3};
    vector<int>endTime={5, 5, 7, 6, 8};
    cout<<uniqueChairs(startTime, endTime);
    

    return 0;
}
