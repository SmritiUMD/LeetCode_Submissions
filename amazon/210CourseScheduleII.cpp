/******************************************************************************
@Author- Smriti Gupta
@date created - March 2,2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    0 indegree- no prerequisite courses required
    push all the courses with 0 indegree into queue/stack.
    process all the nodes of queue by reducing the in degree of its neighbors by 1. 
    After removal of 0 indegree nodes from the graph, the indegree of its neighbors becomes 1. 
    Add the poped node into topological sorted order.
    
    
    */
  
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        map<int,vector<int>>graph;
        vector<int>top_order(numCourses);
        
        //creating a graph
        for(int i=0;i<prerequisites.size();i++){
            // collecting all the elements with 0 indegree 
            //by incrementing indices(course numbers) to 1
            indegree[prerequisites[i][0]]++;
            if(graph.find(prerequisites[i][1])==graph.end()){
                graph.insert({prerequisites[i][1],{prerequisites[i][0]}});
            }
             else{
                 graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
             }                
                             
            }
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                // cout<<i;
                q.push(i);
            }
        }
        int i=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            //add the processed node to topological sorted order 
            top_order[i]=node;
            i++;
            if(graph.find(node)!=graph.end()){
                for(auto neigh:graph[node]){
                    indegree[neigh]--;
                    if(indegree[neigh]==0){
                        q.push(neigh);
                    }
                }
            }
            
        }
        //if all the courses have been processed
         if(i==numCourses){
             return top_order;
         }  
           
        //else return empty vector
        return {};
    }
};

int main()
{
    Solution obj;
    int numCourses = 4;
    vector<vector<int>>prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int>result=obj.findOrder(numCourses,prerequisites);
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }

    return 0;
}
