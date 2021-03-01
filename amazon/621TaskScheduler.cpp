/******************************************************************************
@author - Smriti GUpta
@date created - Feb 28,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
//         keeping the frequency of each task( task 'A' - index 1)
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        //sort the frequecies to retrieve the maximum idle time
        sort(freq.begin(),freq.end());
        int f_max=freq[25];
        int idle_time=(f_max-1)*n;
        
        for(int i=freq.size()-2;i>=0 && idle_time>0;i--){
            // cout<<freq[i]<<endl;
            idle_time-=min(f_max-1,freq[i]);
           

        }
        
        idle_time=max(0,idle_time);
        
        //busy slots+idle slots
        return idle_time+tasks.size();
        
        
    }
};

int main()
{
    Solution obj;
    vector<char>tasks={'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n=2;
    cout<<obj.leastInterval(tasks, n);

    return 0;
}
