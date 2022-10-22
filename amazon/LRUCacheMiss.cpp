/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/






#include <bits/stdc++.h>

using namespace std;

int LRUcatchmiss(vector<int>array, int size){
 if(array.size()==0) return 0;
    int count=0;
    set<int>cache;
    for(int i=0;i<array.size();i++){
        if(cache.find(array[i])!=cache.end()){
            cache.erase(array[i]);
        }
        else{
            count++;
            if(size==cache.size()){
                cache.erase(0);
            }
            cache.insert(array[i]);
        }
    }
    return count;
    
}

int main(){
    vector<int>array={2,3,3,2,4,3};
    int size=2;
    cout<<LRUcatchmiss(array, size);
    return 0;
}
