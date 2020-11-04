/******************************************************************************
@author- Smriti Gupta
@date created- November 4,2020

*******************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

class Solution {
    
    map<string,string>phone={{"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},{"6","mno"},{"7","pqrs"},{"8","tuv"},{"9","wxyz"}};
    vector<string>result;
    
private:
    void backtrack(string combination, string next_digits){
        if(next_digits.size()==0){
            result.push_back(combination);
        }
        else
        {
            // get the first digit 
            string digit=next_digits.substr(0,1);
            // get the corresponding alphabets
            string letters=phone[digit];
                // iterate over the alphabets
            for(int i=0;i<letters.size();i++)
            {
                    // get the letters once at a time
                string letter=phone[digit].substr(i,1);
                    // add the letters to the combination and run the recursive function again
                backtrack(combination+letter,next_digits.substr(1));
            }
        }
    }


    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()!=0)
        {
            backtrack("", digits);
            
        }
        // cout<<result;
        return result;
    }
};

int main()
{
    string s="23";
    Solution obj;
    obj.letterCombinations(s);
   

    return 0;
}
