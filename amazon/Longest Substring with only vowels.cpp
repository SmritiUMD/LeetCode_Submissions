/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/





#include <bits/stdc++.h>

using namespace std;

int sustring(string str){

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

	int gap, vowelLen = 0;

	priority_queue<int>q;   
	//to give the max lengths of the vowel string
	for(auto i : str){
		if(vowels.find(i) == vowels.end()){
			if(vowelLen){
				q.push(vowelLen);  
				//if we find consonents push the found vowelLength in queue;
				gap++;
			}
			vowelLen=0;
		}
		else{
			vowelLen++;
		}
	}
	if(vowelLen){
		q.push(vowelLen);
	}
	int sum = 0;
	if(gap <=2){    
	    // if gap is <= 2,  for eg. aaaabbaaaabbaaaa, 
	    //we an remove those two `bb` and return the rest of the string.
		while(!q.empty()){  
		    //empty the whole queue
			sum+=q.top();
			q.pop();
		}
	
	}
	else{
		int k = 2;
		while(k && !q.empty()){ 
		    //or just the top 2 elements of the queue
			sum+=q.top();
			q.pop();
			k--;
		}
	
	}
	return sum;
}

int main() {
    
    string s="onlineassessment";
   
   cout<<sustring(s);
    return 0;
}
