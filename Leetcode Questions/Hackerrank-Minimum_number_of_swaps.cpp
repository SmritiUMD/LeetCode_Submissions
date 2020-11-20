/******************************************************************************
@author- Smriti Gupta
@date created - November 20,20
*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    
    
    
    // Complete the minimumSwaps function below.
    int minimumSwaps(vector<int> arr) {
        int size =arr.size();
        vector<bool>visited(size+1,false);
        map<int,int>p;
        for(int i=1;i<size+1;i++){
             p.insert(pair<int, int>(i, arr[i-1])); 
        }
        int count=0;
        int p_size=p.size();
        for(int k=1;k<=p_size;k++){
            int nextNode=0;
           if(visited[k]==false){
               visited[k]=true;
               if(k==p[k]){
                   continue;
               }
               else{
                   int c=p[k];
                   while(!visited[c]){
                       visited[c]=true;
                       nextNode=p[c];
                       c=nextNode;
                       count++;
                   }
               }
           } 
        }
    
    return count;

}
};

int main()
{
    Solution obj;
    vector<int>nums={1, 3, 5, 2, 4, 6, 7};
    cout<<obj.minimumSwaps(nums);

    return 0;
}
