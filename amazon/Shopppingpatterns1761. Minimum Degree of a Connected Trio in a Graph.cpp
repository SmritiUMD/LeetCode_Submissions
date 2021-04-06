/******************************************************************************
@author - Smriti Gupta 
@date created - April 6,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>>graph(n+1, vector<bool>(n+1,false));
        vector<int>degree(n+1);
        for(int i=0;i<edges.size();i++){
            graph[min(edges[i][0],edges[i][1])][max(edges[i][0], edges[i][1])]=true;
            degree[min(edges[i][0],edges[i][1])]++;
            degree[max(edges[i][0],edges[i][1])]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(graph[i][j]){
                    for(int k=j+1;k<=n;k++){
                        if(graph[j][k] && graph[i][k]){
                            ans=min(ans,degree[i]+degree[j]+degree[k]-6);
                        }
                    }
                }
            }
        }
                       
    return ans==INT_MAX ? -1 : ans;
    }
};

int main()
{
  
  Solution obj;
  vector<vector<int>>edges={{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
  int n=6;
  cout<<obj.minTrioDegree(n,edges);
   
   

    return 0;
}
