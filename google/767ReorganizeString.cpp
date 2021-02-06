/******************************************************************************
@author - Smriti Gupta
@date create- Feb 6,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


//comparator to arrange value according priority of second value
struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second < b.second; 
    } 
}; 

class Solution {
public:
    string reorganizeString(string S) {
        //map to keep a track of occurrences
        map<char,int>freq;
        map<char,int>::iterator it;
        string result="";
        
        //priority_queue to exhaust high frequency values first
        priority_queue<pair<char,int>, vector<pair<char,int>>, myComp> pq; 
        for(int i=0;i<S.size();i++){
            freq[S[i]]++;
        }
        for(it=freq.begin();it!=freq.end();it++){
            pq.push({it->first, it->second});
        }
        
        
        while(pq.size()>1){
            //we will keep removing two values from queue with highest occurrences
            pair<char,int>curr=pq.top();
            pq.pop();
            pair<char,int>next=pq.top();
            pq.pop();
            result+=curr.first;
            // cout<<result<<endl;
            // cout<<curr.first<<curr.second<<endl;
            result+=next.first;
            // cout<<next.first<<next.second<<endl;
            // cout<<result<<endl;
            
            //after every removal we will check if the occurrence is more than 1
            if(freq[curr.first]>1){
                //if yes - update the map and queue
                pq.push({curr.first, curr.second-1});
                freq[curr.first]--;
            }
            
            if(freq[next.first]>1){
                pq.push({next.first, next.second-1});
                freq[next.first]--;
            }
        }
        
        //checking the remaining values in queue
        //if the remaining occurrences are more than one - return empty string
        //else append it to result
        while(!pq.empty()){
            pair<char,int>curr=pq.top();
            pq.pop();
            if(freq[curr.first]>1){
               return ""; 
            }
            else 
             result+=curr.first;
        }
        return result;
    }
};

int main()
{
    
    string S = "aaabbc";
    
    Solution obj;
    cout<<obj.reorganizeString(S);

    return 0;
}
