/******************************************************************************
@author - Smriti GUpta
@date created- Feb 13,2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


/*
Sorting the boxes according to the number of units to maximize the number of units to be loaded.
*/
class Solution {
    struct Comparator{
    bool operator()(vector<int> const& p1, vector<int> const& p2){
        return p1[1]>p2[1];
    }
  
};


public:
    int maximumUnits(vector<int>unitsPerBox, vector<int>boxes, int truckSize) {
        vector<vector<int>>boxTypes(boxes.size(), vector<int>(2,0));
        for(int i=0;i<boxes.size();i++){
            boxTypes.push_back({boxes[i],unitsPerBox[i]});
            
        }
  
       sort(boxTypes.begin(), boxTypes.end(), Comparator());
       int unitCount=0;
       for(int i=0;i<boxTypes.size();i++){
           int boxCount=min(truckSize, boxTypes[i][0]);
           unitCount+=boxCount*boxTypes[i][1];
           truckSize-=boxCount;
           if(truckSize==0)
                break;
       }
        return unitCount;
    }

 };
int main()

{
    vector<int>boxes={5,2,4,3};
    vector<int>unitsPerBox={10,5,7,9};
    int truckSize=10;
    Solution obj;
    cout<<obj.maximumUnits(unitsPerBox, boxes, truckSize);
   

    return 0;
}

