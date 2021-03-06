/******************************************************************************
@author- Smriti Gupta
@date created - March 6, 21
*******************************************************************************/

// Kruskal's algorithm-implemented using the Disjoint set Union-Find data structure.

#include <bits/stdc++.h>

using namespace std;

class Solution {
    class DisjointSet{
        private:
        vector<int>parents;
        vector<int>weights;
        public:
        /* weighted Union -In this technique, in addition to the parent nodes, we also keep the weights of each of the nodes. 
        Every time we take union, the root node with more weight (i.e. having more elements in the corresponding set)
        is used as the parent node of the other node. We initialize the weight corresponding to each node as 1 initially,
        as each element belongs to it's own set in the beginning. 
        */
        
        // weighted union
        void Union(int a, int b){
            int rootA=Find(a);
            int rootB=Find(b);
            //if both a and b have same root(they belong to same set), 
            //no need to take union
            if(rootA==rootB)
                return ;
            if(this->weights[rootA]>this->weights[rootB]){
            /// In case rootA is having more weight
            // 1. Make rootA as the parent of rootB
            // 2. Increment the weight of rootA by rootB's weight
                this->parents[rootB]=rootA;
                this->weights[rootA]+=this->weights[rootB];
            }
            else{
                // Otherwise
                // 1. Make rootB as the parent of rootA
                // 2. Increment the weight of rootB by rootA's weight
                this->parents[rootA]=rootB;
                this->weights[rootB]+=this->weights[rootA];
            }
        }
        
        /*
        Path Compression-
        while obtaining the root, we compress the path by assigning the
       grandparent of the node as the parent (thereby skipping connections
       and moving nodes closer to the root).
       
       */
        int Find(int a){
            
            //traverse all the way to top to return the root node
            while(a!=this->parents[a]){
                //path compression
                // a's grandparent is now a's parent
                this->parents[a]=this->parents[parents[a]];
                a=this->parents[a];
            }
            return a;
        }
        
        //returns true if both a and b belongs to the same set
        bool isInSameGroup(int a, int b){
            return Find(a)==Find(b);
        }
        
        DisjointSet(int N){
            //setting initial parent node to itself
            // setting initial weights to 1
            this->parents.resize(N+1,0);
            this->weights.resize(N+1,0);
            for(int i=1;i<=N;i++){
                this->parents[i]=i;
                this->weights[i]=1;
            }
        }
        
    };
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        DisjointSet *disjointset = new DisjointSet(N);
        
        //sort the connections based on their weight
        sort(connections.begin(), connections.end() , [](const vector<int> &a , const vector<int> &b){
            return a[2]<b[2];
        });
        
        // keep a track of total edges
        int total_edges=0;
        
        //keep a track of total cost
        int cost=0;
        
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            
            //if both edges belongs to the same group,  dont add them
            if(disjointset->isInSameGroup(a,b))
                continue;
            
            //if a and b are not connected take union
            disjointset->Union(a,b);
            
            //increment cost 
            cost+=connections[i][2];
            
            // increment number of edges
            total_edges++;
        }
        
        // if all the nodes are connected, the MST will have N-1 edges
        if(total_edges==N-1){
            return cost;
        }
        else{
            return -1;
        }
        
        
    }
};


int main()
{
   int  N = 3;
   vector<vector<int>>connections = {{1,2,5},{1,3,6},{2,3,1}};
   Solution obj;
   cout<<"The minimum cost is: "<<obj.minimumCost(N, connections);

    return 0;
}
