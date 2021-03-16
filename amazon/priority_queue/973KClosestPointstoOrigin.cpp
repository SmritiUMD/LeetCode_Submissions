/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef pair<float,pair<int,int>>pi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi, vector<pi>, greater<pi>>pq;
         vector<vector<int>>result;
        
        for(int i=0;i<points.size();i++){
            float distance=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({distance,{points[i][0],points[i][1]}});
        }
       
        while(k>0){
            pi current=pq.top();
            pq.pop();
            result.push_back({current.second.first, current.second.second})  ;
            k--;
        }
        return result;
        
    }
};


int main()
{

   vector<vector<int>>points = {{1,3},{-2,2}};
   Solution obj;
   int k=1;
   obj.kClosest(points,k);
  
    return 0;
}
