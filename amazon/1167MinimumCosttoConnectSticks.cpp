/******************************************************************************
@author -Smriti Gupta
@date created- March 3,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int total_sum=0;
        //use priority queue to maintain the sorted order 
        //if you use vector and sort it, some cases may fail
        //you need to use curr_sum is sorted order too 
     
        priority_queue<int, vector<int>, greater<int>> order;
        for(int i=0;i<sticks.size();i++){
            order.push(sticks[i]);
        } 
        while(order.size()>1){
            int s_1=order.top();
            order.pop();
            int s_2=order.top();
            order.pop();
            int curr_sum=s_1+s_2;
            total_sum+=curr_sum;
            order.push(s_1+s_2);
        }
        return total_sum;
    }
};

int main()
{
   Solution obj;
    vector<int>sticks = {2,4,3};
    cout<<obj.connectSticks(sticks);
   
    return 0;
}
