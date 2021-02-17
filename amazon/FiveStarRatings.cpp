
/******************************************************************************
@author -Smriti Gupta
@date created -Feb 17,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

float fiveStarRating(vector<vector<int>>ratings, float t){
    float curr=0;
    for(int i=0;i<ratings.size();i++){
        curr+=float(ratings[i][0])/float(ratings[i][1]);
       
    }
    
    int count =0;

   int i = 0;

   int j = 0;

   while(i < ratings.size()){

       if(ceil(ratings[i][0] + j) *100 / (ratings[i][1] ) < t){
           j++;
           count++;
           
       }
       else {
           i++;
           j = 0;
           
       }

   }

   return count;

}
    
    
  



int main()
{
    
   vector<vector<int>>ratings = {{4,4},{1,2},{3,6}};
   int threshold=77;
   cout<<fiveStarRating(ratings,threshold);
    return 0;
}


