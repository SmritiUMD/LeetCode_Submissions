#include<bits/stdc++.h> 

using namespace std;

class graph{
    
    private:
    //nodes
        int V;
    //list to store nodes
        list<int> *adj;
    
    public:
    //parametrized constructor
        graph( int V); 
    //function to add edge
        void addEdge(int u, int v);
    //function to print graph
        void printgraph();
        };

    graph::graph(int V) 
    { 
        this->V = V; 
        adj = new list<int>[V]; 
    } 


    void graph::addEdge(int u, int v)
    {
        //adding edges to undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    void graph::printgraph()
    {
        for(int v=0;v<V; v++){
            cout << "\n Adjacency list of vertex "
                 << v << "\n head "; 
            for(auto x:adj[v])
            cout<<"->"<<x;
            cout<<endl;
        }
    }
    

int main()
{
    //object of class graph
    graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.printgraph();

    return 0;
}

