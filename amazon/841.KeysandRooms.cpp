/******************************************************************************
@author - Smriti Gupta
@date created- March 7,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>seen(rooms.size(),false);
        seen[0]=true;
        //to do list to open the rooms( stores all the available keys)
        stack<int>keys;
        keys.push(0);
        //running DFS to open all the rooms
        while(!keys.empty()){
            int curr_key=keys.top();
            keys.pop();
            //opening all the rooms that can be opened from current key
            for(int neigh:rooms[curr_key]){
                if(!seen[neigh]){
                    seen[neigh]=true;
                    keys.push(neigh);
                }
            }
        }
        //check if any room is not opened yet
        for(bool x: seen){
            if(!x)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<int>>rooms={{1},{2},{3},{}};
    Solution  obj;
    cout<<obj.canVisitAllRooms(rooms);
    
    return 0;
}
