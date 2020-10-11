/******************************************************************************
@author Smriti Gupta
@date created October 10,2020
                          
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
    
    
    
   
    //DFS function
    
    void Graph::DFS(int src)
    {
        
        // an arrray to keep a track of visited nodes
        vector<bool>visited(V,false);
	//push the source node in the graph
        stack<int>s;
        s.push(src);

        while(!s.empty())
        {
	//pop the top node from the stack as current
            int current=s.top();
            s.pop();
            //if the node is node visited
            if(!visited[current])
            {	
		// mark it as true
                visited[current]=true;
                cout<<current<<" "<<endl;
                
            }
		//explore the adjacent nodes of the current element and push to 		//stack if not visited
            for(auto i=adj[current].begin(); i!=adj[current].end();i++)
            {
                if(!visited[*i])
                {
                    s.push(*i);
                }
            }
            
        }
    }
       

int main()
{
    
    //creating the object
    Graph g(5); 
    //adding edges to the graph
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(0); 
  
    return 0;
}

