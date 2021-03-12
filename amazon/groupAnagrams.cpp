/******************************************************************************
@author- Smriti Gupta
@date created - March 12, 21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*sorted versions of anagrams would be same
    Time Complexity - sorting (KlogK)
    for iteration - O(N) - path length
    totoal - O(N*KlogK)
    */
public:
    vector<vector<string>> groupAnagrams(vector<string>& path) {
        //map - sorted string and original sgring if their sorted versions are same
        map<string,vector<string>>freq;
        map<string,vector<string>>::iterator it;
        vector<vector<string>>result;
        
        for(int i=0;i<path.size();i++){
           string x=path[i];
          sort(x.begin(),x.end());
           if(freq.find(x)!=freq.end())
               freq[x].push_back(path[i]);
        else{
            freq.insert({x,{path[i]}});
        }
        }
        
        for(it=freq.begin(); it!=freq.end() ;it++){
            result.push_back(it->second);
        }
        return result;
        
    }
};
int main()
{
  
  vector<string>path = {"eat","tea","tan","ate","nat","bat"};
  Solution obj;
  vector<vector<string>>result=obj.groupAnagrams(path);
  for(auto x:result){
      cout<<"group - ";
      for(auto y:x){
        cout<<y<<",";
    }
     cout<<endl;
     }
  
    return 0;
}
