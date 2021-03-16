/******************************************************************************
@Author- Smriti GUpta
@date created - March 2,2021
*******************************************************************************/

/*since we need to return the redundant edge in the graph which comes ast in the graph, we will check 2 conditions 
before adding that edge into the graph:
    1.if that edge already exists in the graph
    'and'
    2. if there is some cycle adter adding this edge->DFS.
    If both are true - means redundant
    */

#include <bits/stdc++.h>

using namespace std;
/*
// Using DFS- O(n^2)
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
*/
// Using Union Find - O(n)

class Union{
    vector<int>parent;
    vector<int>rank;
    public:
    Union(int size){
        this->parent.resize(size+1,0);
        for(int i=0;i<size+1;i++){
            parent[i]=i;
        }
        this->rank.resize(size+1,0);
    }
    public:
    //if current node have parent equal to the node, return parent
    //(the node has not traversed yet , we will start from this.)
    //otherwise, keep traversing back till the root node to find the parent
    int find(int i){
       
        if(parent[i]==i)
           return parent[i];
        return parent[i]=find(parent[i]);
    }
    
    bool findUnion(int x, int y){
        int x_r=find(x);
        int y_r=find(y);
        //if both have common parent - overlapping
        if(x_r==y_r)
            return false;
        // else check the rank to assign the parents
        if(rank[x_r]>rank[y_r])
            parent[x_r]=y_r;
        else if(rank[x_r]<rank[y_r])
            parent[y_r]=x_r;
        else{
            parent[y_r]=x_r;
            //x_r is the child of y_r so its rank will increase by 1.
            //as we move away from the current node, the rank will increase
            rank[x_r]++;
            }
            
        return true;
    }
    
};

class Solution {
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Union obj(edges.size() );
        //traverse over the edges and is their is overlapping- connection is redundant
        for(int i=0;i<edges.size();i++){
            if(!obj.findUnion(edges[i][0],edges[i][1]))
                return edges[i];
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
