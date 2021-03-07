/******************************************************************************
@author- Smriti Gupta
@date created - March 6, 21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

 class DisjointSet{
        private:
        vector<int>parents;
        vector<int>weights;
        public:
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

class Solution
{
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet *set = new DisjointSet(n);
        
        int count = n;
        
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(!set->isInSameGroup(a,b)){
                count--;
                 set->Union(a,b);
            }
           
        }
        return count;
        
    }
};


int main()
{
   int  N = 3;
   vector<vector<int>>connections = {{1,2},{1,3},{2,3}};
   Solution obj;
   cout<<obj.countComponents(N, connections);

    return 0;
}
