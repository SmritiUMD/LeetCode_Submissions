/******************************************************************************
@author - Smriti Gupta
@date created - March 17,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

 class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign =1;
        int result = 0;
        if(s.size()==0)
            return 0;
        //check for the leading spacs
        while(i<s.size() && s[i]==' ')
            i++;
        //check for the sign
        if(i<s.size() && s[i]=='+' || s[i]=='-'){
            sign = (s[i++]=='-') ? -1:1;
            
        }
        
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
//             2147483647 if result==INT_MAX/10  means 214748364 and last number is greater than 7 i.e. INT_MAX%10
            if(result>INT_MAX/10 || (result==INT_MAX/10 && s[i]-'0' > INT_MAX % 10)){
                return (sign==1)? INT_MAX: INT_MIN;
            }
            result=result*10+(s[i++]-'0');
            // i++;
        }
        
        
        return result*sign;
        
    }
};

int main()
{
    Solution obj;
    string s = "422";
   
    cout<<obj.myAtoi(s);
    

    return 0;
}
