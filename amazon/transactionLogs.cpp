#include <bits/stdc++.h>

using namespace std;

//helper function to converst string into vector for simple pre processing
vector<string>string_to_vect(string str){
    string word = "";
    vector<string>result;
    for (auto x : str) 
    {
        if (x == ' ')
        {
           result.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    result.push_back(word);
    return result;
}


vector<string> processLogFile(int threshold , vector<string>& logs){
    
  map<string,int>freq;
  map<string,int>::iterator it;
  vector<string>result;
  for(int i=0;i<logs.size();i++){
      vector<string>curr= string_to_vect(logs[i]);
      
      if(curr[0]!=curr[1]){
          freq[curr[0]]++;
          freq[curr[1]]++;
      }
      else{
          freq[curr[1]]++;
      }
  }
  for(it=freq.begin(); it!=freq.end();it++){
      if(it->second >=threshold){
          result.push_back(it->first);
      }
  }
    
    return result;
}

int main()
{
    int threshold=2;
    vector<string>logs = {"88 99 200", "88 99 300", "99 32 100", "12 12 15"};
    vector<string>result=processLogFile(threshold, logs);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<",";
    }
   
    
    
    
    return 0;
}
