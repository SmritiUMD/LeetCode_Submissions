/******************************************************************************
@author- Smriti Gupta
@date created- January 25,21
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class shortestpath{
    private:
    
    //member variables
    int inf=8564985;
    
    int V;
    
    vector<vector<int>>grid;
    //visited nodes -// visited[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
    vector<bool>visited;
    
    //The output array.  dist[i] will hold the shortest 
    // distance from src to i 
    vector<int>dist;
    
    vector<int>parent;
    
    int minDistance();
    
    public:
    
    shortestpath(int V, vector<vector<int>>grid){
        this->V=V;
        this->dist=vector<int>(V,inf);
        this->visited=vector<bool>(V,false);
        //initializing every distance as inifinite
        this->parent=vector<int>(V,inf);
        this->grid=grid;
        
    }
    
    void dijkstra(int src);
    
    void printSolution();
    

};



void shortestpath::printSolution(){
    cout<<"Edge \t Weight"<<endl;
    
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"-"<<i<<"\t"<<grid[i][parent[i]]<<"\n";
    }
}
int shortestpath::minDistance(){
    int min = inf;
    int min_index;
    
    for(int v=0;v<V;v++){
        if(!visited[v] && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
    
}

void shortestpath::dijkstra(int src){
    //distance of first node from itself
    dist[src]=0;
    //parent of source node doesnt exist
    parent[src]=-1;
    
    //updating the distance values for current vertex
    for(int i=0;i<V-1;i++){
        //picking the minimum distance vertex which is not visited yet
        int curr_vertex=minDistance();
        
        //mark the minDistance vetex as visited
        visited[curr_vertex]=true;
        
        //visiting adjacent nodes of the current picked vertex
        for(int v=0;v<V;v++){
            
            //update dist[v] only if it is not already visited, there is an edge exists between its current vertex and visited
            // the total weight of path from src to curr_vertex + curr_vertex to v shoud be less than src to v directly
            if(!visited[v] && grid[curr_vertex][v] && dist[curr_vertex]!=inf && dist[curr_vertex]+ grid[curr_vertex][v]<dist[v]){
                // update new distance for v
                dist[v]=dist[curr_vertex]+ grid[curr_vertex][v];
                //updateparent information
                parent[v]=curr_vertex;
            }
        }
    }
    
    //print solution
    printSolution();
}

using namespace std;

int main()
{
    int V=9;
    
    vector<vector<int>>grid = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    
    shortestpath obj(V, grid);
    obj.dijkstra(0);
   

    return 0;
}
