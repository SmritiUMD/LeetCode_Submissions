/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
// Using DFS
/*For every city call dfs function to check if any other city is connected to it or not
*/
// class Solution {
//     vector<bool>visited;
//     vector<vector<int>>isConnected;
//     void dfs(int index){
//         for(int j=0;j<isConnected.size();j++){
//             if(isConnected[index][j]==1 && !visited[j]){
//                 visited[j]=true;
//                 dfs(j);
//             }
//     }
//     }
//      public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         visited.resize(isConnected.size(),false);
//         this->isConnected=isConnected;
//         int count=0;
//         for(int i=0;i<isConnected.size();i++){
//             if(!visited[i]){
//                 dfs(i);
//                 count++;
//             }
//         }
        
//         return count;
        
//     }
// };

class Solution {
    //using union find
    vector<int>parent;
    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return find(parent[i]);
    }
    //if they doesnt belong to same parent, make x parent of y
    void union_(int x, int y){
        int xset=find(x);
        int yset=find(y);
        if(xset!=yset){
            parent[xset]=yset;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.resize(isConnected.size(),-1);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    union_(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1)
                count++;
        }
        return count;
        
        
        
    }
};

int main()
{
    Solution obj;
    vector<vector<int>>isConnected={{1,1,0},{1,1,0},{0,0,1}};
    cout<<obj.findCircleNum(isConnected);
    

    return 0;
}
