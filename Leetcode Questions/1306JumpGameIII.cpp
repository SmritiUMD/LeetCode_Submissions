/******************************************************************************
@author- Smriti Gupta
@date created- November 3,20
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    bool canReach(vector<int>& arr, int start) {
    
        if( start>=arr.size() || arr[start]<0 || start < 0) {
            cout<<"false";
            return false;
        }
        if(arr[start]==0){
        cout<<"true";    
         return true;
        }
// mark the visited values as negative
        else arr[start]*=-1;
        return(canReach(arr, start+arr[start]) || canReach(arr,start-arr[start]));
            
        
       
        
    }
};


int main()
{
 vector<int>nums={2,3,1,1,4};
 Solution s;
 int start =3;
 s.canReach(nums, start);

    return 0;
}
