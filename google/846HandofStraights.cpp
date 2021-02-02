/******************************************************************************
@author - Smriti Gupta
@date created - Feb 2,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        sort(hand.begin(), hand.end());
        if(hand.size()%W !=0)
            return false;
        map<int,int>count;
        for(int i=0;i<hand.size();i++){
            count[hand[i]]++;
        }
        
        while(!count.empty()){
            //picking out the first card
            int first=count.begin()->first;
            //iterating for the numbers in w size to check if they are consecutive or not
            //we will keep incrementing by one and check if the number is 
            // already there in map, if yes then decrease the frequency
            for(int i=first;i<first+W;i++){
                if(count.find(i)==count.end())
                    return false;
                int current_count=count[i];
                if(current_count==1){
                    count.erase(i);
                }
                else{
                    count[i]-=1;
                }
            }
            
        }
        return true;
        
    }
};

int main()
{
   Solution obj;
   vector<int>hand = {1,2,3,6,2,3,4,7,8};,
   int W = 3;
   bool result=obj.isNStraightHand(hand, W);
   if(result==1) cout<<"yes"<<endl;
   else cout<<"false"<<endl;

    return 0;
}
