/******************************************************************************
@author Smriti Gupta
@date created- October 11,2020
*******************************************************************************/

#include<bits/stdc++.h> 

using namespace std;


class Graph
{
    
    private:
        //number of nodes
        int V;
        //pointer to an arrar containing adjacency lists
        list<int> *adj;
       
        
    public: 
    
        //constructor of class graph
        
        Graph(int V);
        //function to add edge into Graph
        
        void addEdge(int u, int v);
        
        // BFS function to print traversal from a given source
        void BFS(int src);
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
    
    
    
   
    //BFS function
    
    void Graph::BFS(int src)
    {
        
        // an arrray to keep a track of visited nodes
        //mark all of them as not visited
        vector<bool>visited(V,false);
        
        //a queue for BFS
        
        queue<int>q;
        
        // mark current node as visited
        visited[src]=true;
        
        q.push(src);
        
        while(!q.empty())
        {
            //deque an element from queue and print
            src=q.front();
            q.pop();
            
            cout<<src<<" "<<endl;
                
            
            for(auto i=adj[src].begin(); i!=adj[src].end();i++)
            {
                if(!visited[*i])
                {
                    visited[*i]=true;
                    q.push(*i);
                }
            }
            
        }
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
    cout << "Following is  Breadth First Traversal"
            " (starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0;
}





