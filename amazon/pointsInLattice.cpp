/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/



#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
vector<int> lattice(int ax, int ay, int bx, int by) {
        int dx = bx - ax, dy = by - ay;
        // rotate 90
        int rx = dy, ry = -dx;
        // reduce
        int g = abs(gcd(rx, ry));
        rx /= g;
        ry /= g;
return {bx + rx, by + ry};
    }

int main() {
vector<int>result=lattice(-1,3,3,1);
   cout<<result[0]<<","<<result[1]<<endl;
    
}
