/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

using namespace std;
#define ll long long int
 
vector<string>uniqueNames(vector<string>& filenames){
   
    
    vector<string>result;
    if(filenames.size()==0) return result;
     map<string,int>freq;
    
    set<string>seen;
   
   
    for(int i=0;i<filenames.size();i++){
        if(seen.find(filenames[i])==seen.end()){
            result.push_back(filenames[i]);
            seen.insert(filenames[i]);
            freq[filenames[i]]++;
        }
    
        else{
            string new_name=filenames[i]+to_string(freq[filenames[i]]);
            result.push_back(new_name);
            freq[filenames[i]]++;
         }
    }
    return result;
}
 

int main()
{
    vector<string>filenames={"system","access","access","system","access","system","access};
    vector<string>result=uniqueNames(filenames);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<",";
    }
    return 0;
}




