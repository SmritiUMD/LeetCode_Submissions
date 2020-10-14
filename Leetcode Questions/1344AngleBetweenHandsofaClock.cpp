/******************************************************************************
@author- Smriti Gupta
@date created- october-14,2020
*******************************************************************************/

#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle=(hour*30)+float(minutes*30)/float(60);
        if(hour_angle>=360) hour_angle-=360;
        
        float min_angle=(minutes*60)/10;
        if(min_angle>=360) min_angle-=360;
       
         double result =abs(hour_angle-min_angle);
        if (result>180) result=360-result;
       
        cout<<result;
    }
};

int main()
{
  int hour=6;
  int minutes =47;
   
   Solution obj;
   obj.angleClock(hour,minutes);

    return 0;
}
