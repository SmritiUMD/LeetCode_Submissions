/******************************************************************************
@author - Smriti Gupta
@date created - March 16,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

 class Union{
    vector<int>parent;
    // We use this to keep track of the size of each set.
    vector<int>rank;
    public:
    Union(int n){
        this->parent.resize(n);
        this->rank.resize(n,1);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
    }
     // The find method, with path compression.
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    
    // The union method, with optimization union by size. It returns True if a
    // merge happened, False if otherwise.
    bool findUnion(int a, int b){
        int rootA=find(a);
        int rootB=find(b);
        // Check if A and B are already in the same set.

        if(rootA==rootB)
            return false;
        //weighted merging
         // We want to ensure the larger set remains the root.
        if(rank[rootA]>rank[rootB]){
            parent[rootB]=rootA;
            // The rank of the set rooted at B is the sum of the 2.
            rank[rootA]+=rank[rootB];
        }
        else{
            // Make rootA the overall root.
            parent[rootA]=rootB;
             // The rank of the set rooted at A is the sum of the 2.
            rank[rootB]+=rank[rootA];
        }
       return true; 
    }
};



class Solution {
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Condition 1: The graph must contain n - 1 edges.
        if(edges.size()!=n-1)
            return false;
        Union obj(n);
        // Condition 2: The graph must contain a single connected component.
        for(auto i:edges){
            int A=i[0];
            int B=i[1];
            //if no merge happens- cycle is there
            if(!obj.findUnion(A,B)){
                return false;
            }
        }
        //no cycles so far - true
        return true;
        
    }
};

int main()
{
    Solution obj;
   
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    int n=5;
    cout<<obj.validTree(n,edges);
    

    return 0;
}
