/******************************************************************************
@author- Smriti Gupta
@date created- october 21,2020


*******************************************************************************/

#include<bits/stdc++.h> 
using namespace std;


class Solution 

{
    int n;
    vector<vector<int>>paths;


public:
    
    Solution(vector<vector<int>>& path, int x);
    
    vector<int> gardenNoAdj(vector<vector<int>>& y);
    
    void print();
    // to store result;
    vector<int>result;
    
};

 // using initializer list to initialize vector
 Solution::Solution(vector<vector<int>>& y ,int x):
        n(x), result(x,-1),paths(y)
        {
            
        } 
 vector<int>Solution::gardenNoAdj(vector<vector<int>>& y) 
 {
     vector<int>flowers;
     vector<vector<int>>graph(n+1);
     //bidirectional graph
    for(int i=0;i<paths.size();i++)
    {
        graph[paths[i][0]].push_back(paths[i][1]);
        graph[paths[i][1]].push_back(paths[i][0]);
        
    }
    //current node
    int node;
    
    //neighbour
    
    int neighbour;
    
    for(int i=1;i<=n;i++)
    {
        
        node =i;
        
        //initialize flowers - for any node we have four choices
        flowers={1,2,3,4};
        
        //number of neighbours for each node
        neighbour=graph[node].size();
            
        //iterate over nodes and check the neighbour flower type and set -1 for every flower 
        //tracked in the neighbour garden
        for(int j=0;j<neighbour;j++)
        {
            //first we will check in result if that flower is already choosen
            //if result[neighbour]==-1, means it has no flower
            if(result[graph[node][j]-1]!=-1)
            {
                flowers[result[graph[node][j]-1]-1]=-1;
            }
        }
        
            
        // check the flower vector and get the first -1, means it is not in neighbour of current garden
        for(int j=0;j<4;j++)
        {
            if(flowers[j]!=-1)
            {
                //the node starts from 1, and the index start from 0
                result[node-1]=j+1;
                break;
            }
        }
        
        
    }
        return result;
        
        
    }
    
    void Solution::print()
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<endl;
        }
    }


int main()
{
    vector<vector<int>>paths={{1,2},{2,3},{3,1}};
    int n=3;
    Solution s(paths,n);
    s.gardenNoAdj(paths);
    s.print();
    return 0;
}
