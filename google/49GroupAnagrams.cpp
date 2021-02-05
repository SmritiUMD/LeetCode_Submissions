/******************************************************************************
@author - Smriti Gupta
@date created - Feb 5.21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& path) {
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
    vector<string>path={"eat","tea","tan","ate","nat","bat"};
    Solution obj;
    
    vector<vector<string>>result=obj.groupAnagrams(path);
    for(int i=0;i<result.size();i++){
        cout<<"[";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
   

    return 0;
}
