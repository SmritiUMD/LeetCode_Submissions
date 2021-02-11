/******************************************************************************
@author - Smriti Gupta
@date - Feb 11,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Solution {
    
    //comparator to arrange value according priority of second value
struct myComp { 
   bool operator()( 
        pair<string, int> a, 
        pair<string, int> b) 
        
    { 
        if(a.second==b.second) return a.first>b.first;
        return a.second < b.second; 
    } 
}; 

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>freq;
        map<string,int>::iterator it;
        vector<string>result;
        for(int i=0;i<words.size();i++){
            freq[words[i]]++;
        }
        priority_queue<pair<string,int>, vector<pair<string,int>>, myComp> pq; 
        for(it=freq.begin();it!=freq.end();it++){
            pq.push({it->first,it->second});
            
        }
        while(k!=0){
            pair<string,int>curr=pq.top();
            result.push_back(curr.first);
            cout<<curr.first<<",";
            pq.pop();
            k--;
            
        }
        return result;
        
    }
};


int main()
{
    vector<string> s = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    Solution obj;
    
    obj.topKFrequent(s,k);

    return 0;
}
