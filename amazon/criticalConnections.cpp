/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/


/*
Critical Points

Data center critical connections
REfer- https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
*/

#include <bits/stdc++.h>

using namespace std;


class Solution{
    
     list<int> *adj;
 

void helper(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            helper(v, visited, disc, low, parent, ap); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[u] == -1 && children > 1) 
               ap[u] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != -1 && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
     

public:

vector<int>CriticalNodes(vector<pair<int,int>>& edges, int V){
    
    adj= new list<int>[V];
    vector<int>result;
   
    
    //creating undirected graph
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    // / Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    
    //iterate over the nodes and find critical points using helper function
    for(int i=0;i<V;i++){
        if(visited[i]==false)
          helper(i,visited,disc,low,parent,ap);
    }
    
    for(int i =0 ;i <V;i++){
        if(ap[i]==true)
            result.push_back(i);
    }
    return result;
    
    
    }


};
int main() {
  int num = 7;

 vector<pair<int,int>>edges = {{0,1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3,4}};
 
 Solution obj;
 
 vector<int>result=obj.CriticalNodes(edges, num);
 for(int i=0;i<result.size();i++){
     cout<<result[i]<<",";
 }
   
   
  return 0;

}

