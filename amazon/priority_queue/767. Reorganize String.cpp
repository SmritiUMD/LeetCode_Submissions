/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

//a comparator to arrange elements according to priority of second value in priority queue
struct myComp { 
   bool operator()( 
        pair<int, int>const &a, 
        pair<int, int>const &b) 
        
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
            result+=next.first;
           
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

  Solution obj;
  string S="aaabbbccd";
  cout<<obj.reorganizeString(S);
  
    return 0;
}
