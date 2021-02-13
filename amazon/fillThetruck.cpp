/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
   
   int findMaxUnitBox(vector<int>boxes, vector<int>unitsPerBox){
         int maxUnitBoxIndex = -1;
        int maxUnits = 0;
        for (int i = 0; i < boxes.size(); i++) {
            if (unitsPerBox[i] > maxUnits) {
                maxUnits = unitsPerBox[i];
                maxUnitBoxIndex = i;
            }
        }
        return maxUnitBoxIndex;
   }
    
public:
    int maximumUnits(vector<int>boxes, vector<int>unitsPerBox, int truckSize) {
        int unitCount = 0;
        int remainingTruckSize = truckSize;
        while (remainingTruckSize > 0) {
            int maxUnitBoxIndex = findMaxUnitBox(boxes, unitsPerBox);
            // check if all boxes are used
            if (maxUnitBoxIndex == -1) break;
            // find the box count that can be put in truck
            int boxCount =
                min(remainingTruckSize, boxes[maxUnitBoxIndex]);
            unitCount += boxCount * unitsPerBox[maxUnitBoxIndex];
            remainingTruckSize -= boxCount;
            // mark box with index maxUnitBoxIndex as used
            unitsPerBox[maxUnitBoxIndex] = -1;
        }
        return unitCount;
    }
};
*/



//O(nlogn) By sorting the boxes according to units inside

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
