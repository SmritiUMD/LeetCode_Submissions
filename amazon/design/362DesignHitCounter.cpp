/******************************************************************************
@author - Smriti Gupta
@date- April 9,21

*******************************************************************************/
/*
Time Complexity

hit - Since inserting a value in the queue takes place in O(1)O(1) time, hence hit method works in O(1)O(1).

getHits - Assuming a total of nn values present in the queue at a time and the total number of timestamps 
encountered throughout is NN. In the worst case scenario, we might end up removing all the entries from the 
queue in getHits method if the difference in timestamp is greater than or equal to 300. Hence in the worst case
, a "single" call to the getHits method can take O(n)O(n) time. However, we must notice that each timestamp is
processed only twice (first while adding the timestamp in the queue in hit method and second while removing 
the timestamp from the queue in the getHits method). Hence if the total number of timestamps encountered throughout 
is NN, the overall time taken by getHits method is O(N)O(N). This results in an amortized time complexity of O(1)
for a single call to getHits method.

Overall Space - O(n)
*/

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
