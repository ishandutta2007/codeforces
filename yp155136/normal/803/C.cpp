#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long LL;

int main () {
    LL n,k;
    cin >> n >> k;
    if (k > 1e6) {
        puts("-1");
        return 0;
    }
    else if (k*(k+1)/2 > n) {
        puts("-1");
        return 0;
    }
    LL can_gcd=1;
    LL haha=sqrt(n) + 5;
    for (LL gcd=1;haha>=gcd;gcd++) {
        if (log(gcd) + log(k) + log(k+1) - log(2) > log(1e18)) break;
        else if (gcd*(k*(k+1))/2 > n) break;
        else if (n%gcd!=0) continue;
        else {
            can_gcd=max(gcd,can_gcd);
            LL rev=n/gcd;
            if (log10(rev) + log10(k) + log10(k+1) - log10(2) > 18.2) continue;
            if (rev*k*(k+1)/2 <= n) {
                can_gcd=max(rev,can_gcd);
            }
        }
    }
    LL tot=n;
    for (int i=1;k>=i;i++) {
        if (i!=k) {
            printf("%lld ",can_gcd*i);
            tot-=can_gcd*i;
        }
        else {
            printf("%lld ",tot);
        }
    }
    puts("");
}