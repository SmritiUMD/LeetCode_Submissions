/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;



vector<pair<int,int>>memoryUtilization(vector<int>& foregroundTasks, vector<int> &backgroundTasks ,int K){
    map<int,vector<pair<int,int>>>freq;
    for(int i=0;i<foregroundTasks.size();i++){
         if(foregroundTasks[i]==K){
                freq[K].push_back({i,-1});
            }
        for(int j=0;j<backgroundTasks.size();j++){
           
            if(backgroundTasks[j]==K){
                freq[K].push_back({-1,K});
            }
            else{
            int sum=foregroundTasks[i]+backgroundTasks[j];
            if(sum<=K){
                freq[sum].push_back({i,j});
            }
            }
        }
    }
    map<int,vector<pair<int,int>>>::iterator it;
    for(it=freq.begin(); it!=freq.end();it++){
        cout<<it->first<<"-";
        for(int j=0;j<it->second.size();j++){
            cout<<it->second[j].first<<","<<it->second[j].second<<" ";
        }
        cout<<endl;
    }
  
    
    
    return freq.rbegin()->second;
    
}
int main() {
  vector<int>foregroundTasks ={1, 7, 2, 4, 5, 6};
  vector<int>backgroundTasks = {1, 1, 2};
   int K = 10;
   vector<pair<int,int>>result=memoryUtilization(foregroundTasks, backgroundTasks, K);
   for(int i=0;i<result.size();i++){
       cout<<result[i].first<<","<<result[i].second <<endl;
   }
  return 0;

}

