/******************************************************************************
@author - Smriti Gupta
@date- April 9,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


 class HitCounter {
    queue<int>hits;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits.push(timestamp);
        
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!hits.empty()){
            int diff=timestamp-hits.front();
            if(diff>=300){
                hits.pop();
            }
            else
                break;
        }
        return hits.size();
        
    }
};

int main()
{
     HitCounter* obj = new HitCounter();
     
    vector<int>timestamp={1,2,3,5,6,7,8,300,305};
    for(int i=0;i<timestamp.size();i++){
        obj->hit(timestamp[i]);
        
    }
   
   
    cout<<obj->getHits(305);
}
