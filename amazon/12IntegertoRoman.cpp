/******************************************************************************
@author - Smriti Gupta
@date created - March 9, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman_num="";
        vector<int>values= {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
        vector<string>symbols={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        for(int i=0;i<values.size() && num>=0;i++){
            while(values[i]<=num){
                num-=values[i];
                roman_num+=symbols[i];
            }
        }

        return roman_num;
        
    }
};

int main()
{
    int n=55;
    Solution obj;
    cout<<obj.intToRoman(n);

    return 0;
}
