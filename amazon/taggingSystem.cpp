/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;



/*
Tagging system -

Largest Lexicographical string with at most k consecutive elements
*/

 
string getLargestString(string s,long int k)
{
 
    vector<int> frequency_array(26, 0);
 
   
    for (int i = 0;
         i < s.length(); i++) {
 
        frequency_array[s[i] - 'a']++;
    }
 
    string ans = "";
    for (int i = 25; i >= 0;) {
        if (frequency_array[i] > k) {
            int temp = k;
            string st(1, i + 'a');
            while (temp > 0) {
                ans += st;
                temp--;
            }
 
            frequency_array[i] -= k;
            int j = i - 1;
            while (frequency_array[j]
                       <= 0
                   && j >= 0) {
                j--;
            }

            if (frequency_array[j] > 0
                && j >= 0) {
                string str(1, j + 'a');
                ans += str;
                frequency_array[j] -= 1;
            }
            else {
                break;
            }
        }

        else if (frequency_array[i] > 0) {
            int temp = frequency_array[i];
            frequency_array[i] -= temp;
            string st(1, i + 'a');
            while (temp > 0) {
                ans += st;
                temp--;
            }
        }
        else {
            i--;
        }
    }
    return ans;
}
 

int main()
{
    string S = "cbddd";
    int k = 2;
    cout << getLargestString(S, k)
         << endl;
    return 0;
}

