#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

LL check(LL x) {
    LL ret=x;
    while (x>0) {
        ret -=x%10;
        x/=10;
    }
    return ret;
}

int main () {
    LL n,s;
    cin >> n >> s;
    LL L=9,R=4e18;
    while (R-L!=1) {
        LL mid=(L+R)>>1;
        if (check(mid) >= s) R=mid;
        else L=mid;
    }
    cout<<max(0LL,n-R+1)<<endl;
}