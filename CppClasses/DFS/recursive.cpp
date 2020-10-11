/******************************************************************************
@author Smriti Gupta
@date created- October 11,2020
*******************************************************************************/

#include<bits/stdc++.h> 

using namespace std;

class Graph{
    private:
        //number of nodes
        int V;
        //pointer to an arrar containing adjacency lists
        list<int> *adj;
        //recursive helper function 
        
        void helper(int v, bool visited[]);
        
    public: 
    
        //constructor of class graph
        
        Graph(int V);
        //function to add edge into Graph
        
        void addEdge(int u, int v);
        // DFS function
        void DFS(int v);
};
    //paramterized contructor, allocating memory for adjacency list

    Graph::Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
  
   //adding edge to the graph
    void Graph::addEdge(int u, int v)
    {
        
        adj[u].push_back(v);
    }
    
    
    
    void Graph::helper(int v,bool visited[])
    {
        //marking visited n0des as true
        visited[v]=true;
        cout<<v<<" ";
        
        list<int>::iterator i;
        //iterating over adjacent nodes of current node
        for(i=adj[v].begin(); i!=adj[v].end();i++){
            //visiting the node that is not already visited
            if(!visited[*i]){ 
                //call the recursive function if the node is not already visited and run the helper function again
                // as we are traversing in depth 
                helper(*i, visited);
            }
        }
        
    }
    
    //DFS function
    
    void Graph::DFS(int v)
    {
        
        // an arrray to keep a track of visited nodes
        bool *visited= new bool[V];
        for(int i=0;i<V;i++)
        {
            // marking all the nodes as false
            visited[i]=false;
        }
        // running the helper node to find the DFS solution
        helper(v,visited);
    }

int main()
{
    
    //creating the object
    Graph g(4); 
    //adding edges to the graph
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0;
}

