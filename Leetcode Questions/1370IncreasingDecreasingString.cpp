/******************************************************************************

@author-Smriti Gupta
@date created-Nov29,20
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string sortString(string s)
    {
        if(s.empty())
            return s;
        map<char,int>freq;
        map<char,int>:: iterator it;
        map<char,int>:: reverse_iterator it1;
        
        for(int i=0;i<s.size();i++)
        {
            freq[s.at(i)]++;
        }
        string ans;
        bool check =true;
        while(check)
        {
            check=false;
            for(it=freq.begin();it!=freq.end();it++)
            {
                if(it->second>0)
                {
                  ans.push_back(it->first);  
                  it->second--;
                  check=true;
                }
            }
            for(it1=freq.rbegin();it1!=freq.rend();it1++)
            {
                if(it1->second>0)
                {
                    ans.push_back(it1->first);
                    it1->second--;
                    check=true;
                }
            }
            
        }
        
        return ans;
    }
};

int main()
{
    string s="aaaabbbbcccc";
    Solution sort;
    cout<<sort.sortString(s);

    return 0;
}
