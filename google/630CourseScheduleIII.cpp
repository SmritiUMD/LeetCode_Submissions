/******************************************************************************
@Author- Smriti GUpta
@date created - March 2,2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
 int scheduleCourse(vector<vector<int>>& courses) {
       sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int sum=0;
        priority_queue<int>q;
        for(int i =0;i<courses.size();i++ ){
            sum+=courses[i][0];
            q.push(courses[i][0]);
            if(sum>courses[i][1]){
                sum-=q.top();
                q.pop();
            }
                
            
        }
        
        
        return q.size();
        
    }
};

int main()
{
    Solution obj;
    
    vector<vector<int>>courses={{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    
    cout<<obj.scheduleCourse(courses);

    return 0;
}
