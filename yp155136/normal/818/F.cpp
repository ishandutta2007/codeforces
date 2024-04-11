#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
    int q;
    cin >>q;
    while (q--) {
        LL n;
        cin >> n;
        if (n==1) {
            puts("0");
        }
        else if (n==2) {
            puts("1");
        }
        else if (n<=5) {
            printf("%lld\n",n-1);
        }
        else {
            LL ans=n-1;
            LL L=0,R=2e9+7;
            while (R-L!=1) {
                LL mid=(L+R)>>1;
                if (mid*mid + mid - 2*n <= 0) L=mid;
                else R=mid;
            }
            LL x=L;
            printf("%lld\n",max(n-x+x*(x-1)/2,2*n-2*(x+1)) );
        }
    }
}