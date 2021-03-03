/******************************************************************************
@author -Smriti Gupta
@date created- March 3,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int max_time=releaseTimes[0];
        char result=keysPressed[0];
        for(int i=1;i<releaseTimes.size();i++){
            int time= releaseTimes[i]-releaseTimes[i-1];
            if(time>=max_time){
                //be careful for this maintain max for keys also  in case of same time
                if(time==max_time){
                    result=max(keysPressed[i],result);
                    max_time=time;
                }
                else{
                    max_time=time;
                    result=keysPressed[i];
                }
            }
                
            
        }
       return result; 
    }
};

int main()
{
   Solution obj;
   vector<int>releaseTimes = {9,29,49,50};
   string keysPressed = "cbcd";
   cout<<obj.slowestKey(releaseTimes, keysPressed);

    return 0;
}
