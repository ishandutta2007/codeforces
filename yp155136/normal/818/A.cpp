#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long LL;

int main () {
    LL n,k;
    cin >> n >>k;
    LL L=0,R=1e13 + 6;
    //cout<<n<<' '<<k<<endl;
    while (R-L != 1) {
        LL mid=(L+R)>>1;
        if (log10(k) + log10(mid) >= 18.2) R=mid;
        else if (mid + k*mid <= n/2) L=mid;
        else R=mid;
    }
    cout<<L<<' '<<L*k<<' '<<n-L-L*k<<endl;
}