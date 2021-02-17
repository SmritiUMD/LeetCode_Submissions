/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21
Similar two 4sum - leetcode

*******************************************************************************/



#include <bits/stdc++.h>

using namespace std;

class Solution{
    

public: 

/*

Brute Forcing 

int numberOfOptions(vector<int>jeans, vector<int>shoes, vector<int>skirts, vector<int> tops, int budget)
{
    int result = 0;
    for(int i=0; i<jeans.length; i++)r
    {
        for(int j=0; j<shoes.length; j++)
        {
            for(int k=0; k<skirts.length; k++)
            {
                for(int l=0; l < tops.length; l++)
                {
                    if( (jeans[i] + shoes[j] + skirts[k] + tops[l]) <= budget )
                    {
                        result++;
                    }
                }
            }
        }
    }
    
    return result;
}

*/

int getOptions( vector<int>a, vector<int>b, vector<int>c, vector<int>d, int dollars){
 
 int longest= max(a.size(),max(b.size(),max(c.size(),d.size())));
 if(d.size()==longest){
     return helper(d,a,b,c,dollars);
 }
 if(a.size()==longest){
     return helper(a,b,c,d,dollars);
 }
 if(c.size()==longest){
     return helper(c,a,b,d,dollars);
 }
 if(b.size()==longest){
     return helper(b,a,c,d,dollars);
 }
}

private:
int helper(vector<int>longest, vector<int>a, vector<int>b, vector<int>c, int dollars){
  
  
    sort(longest.begin(), longest.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int>abSum(a.size()*b.size());
    int index = 0;
    for (int ai : a) {
        if (ai >= dollars) {
            break;
        }
        for (int bi : b) {
            if (bi >= dollars) {
                break;
            }

            if (ai + bi < dollars) {
                abSum[index++] = ai + bi;
            } else {
                break;
            }
        }
    }
    
    int abcIndex = 0;
    vector<int>abcSum(index * c.size());
    for (int i = 0; i < index; i++) {
        if (abSum[i] == 0) {
            break;
        }

        for (int ci : c) {
            if (ci >= dollars) {
                break;
            }

            if (abSum[i] + ci < dollars) {
                abcSum[abcIndex++] = abSum[i] + ci;
            } else {
                break;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < abcIndex; i++) {
        if (abcSum[i] == 0) {
            break;
        }

        for (int di : longest) {
            if (abcSum[i] + di <= dollars) {
                result++;
            } else {
                break;
            }
        }
    }

    return result;
}
    
    
};

int main() {
    
    Solution obj;
    cout<<obj.getOptions({6}, {1, 10*1000000, 1, 1}, {4, 5, 6*1000000}, {1}, 1000000000);
    return 0;
     
}
    
