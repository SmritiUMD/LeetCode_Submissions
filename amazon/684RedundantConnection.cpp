/******************************************************************************
@Author- Smriti GUpta
@date created - March 2,2021
*******************************************************************************/

/*
 the graph, we will check 2 conditions before adding that edge into the graph:
    1.if that edge already exists in the graph
    'and'
    2. if there is some cycle adter adding this edge)DFS.
    If both are true - means redundant
    */

#include <bits/stdc++.h>

using namespace std;

class Solution {
    set<int>seen;
    map<int,vector<int>>graph;
    
    bool dfs(int src, int target){
        if(seen.find(src)==seen.end()){
            seen.insert(src);
            if(src==target) 
                return true;
            for(int neigh:graph[src]){
                if(dfs(neigh, target))
                    return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        //creating empty graph
        for(int i=0;i<edges.size();i++){
           graph.insert({});
        }
        //iterate over edges 
        for(auto edge:edges){
            seen.clear();
            
            //if edge exists in the graph and dfs is true(cycle detected) this connection is redundant
            if(graph.find(edge[0])!=graph.end() && graph.find(edge[1])!=graph.end() && dfs(edge[0], edge[1])){
            return edge;
            }
            else{
                //else add the edge in graph
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
        }
        
        
       return {}; 
    }
};

int main()
{
    Solution obj;
    
    vector<vector<int>>edges={{1,2}, {1,3}, {2,3}};
    vector<int>result=obj.findRedundantConnection(edges);
    cout<<result[0]<<","<<result[1]<<endl;

    return 0;
}
