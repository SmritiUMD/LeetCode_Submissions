/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/


#include <iostream>

using namespace std;



bool canThreePartsEqualSum(vector<int>& arr) {
    int sum = 0;
    for(int i=0;i<arr.size();i++)
        sum += arr[i];
    if(sum % 3 != 0)
        return false;
    int sum3 = sum/3, partitions = 0;
    sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == sum3){
            ++partitions;
            sum = 0;
        }
    }
    return partitions >= 3;
}
int main() {
  vector<int> arr({0,2,1,-6,6,-7,9,1,2,0,1}); 
  cout<<canThreePartsEqualSum(arr);
  return 0;

}

