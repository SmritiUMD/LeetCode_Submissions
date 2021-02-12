/******************************************************************************
@author - Smriti Gupta
@date - Feb 11,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

    
 class Solution {
    typedef pair<float, vector<int>> pi; 
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    
    //using priority queue (min_heap) to remove numbers in which are close to origin
        priority_queue<pi, vector<pi>, greater<pi> > pq; 
        vector<vector<int>>result;
        for(int i=0;i<points.size();i++){
            float dist=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({dist, points[i]});
        }
        while(K!=0){
            pair<float,vector<int>>curr=pq.top();
            // cout<<curr.first<<endl;
            result.push_back(curr.second);
            cout<<"["<<curr.second[0]<<","<<curr.second[1]<<"]"<<"-"<<curr.first<<endl;
            pq.pop();
            K--;
            
        }
        return result;
        
    }
};


int main()
{
    vector<vector<int>>points = {{3,3},{5,-1},{-2,4}}; 
    int K = 2;
    Solution obj;
    
    obj.kClosest(points,K);

    return 0;
}
