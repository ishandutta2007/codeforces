#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

ll abs(ll x) {
    if (x>0) return x;
    else return -x;
}

int main () {
    int k;
    while (scanf("%d",&k) != EOF) {
        ll b[k];
        ll tmp=0;
        ll ans=0;
        for (int x=0;k>x;x++) {
            scanf("%I64d",&b[x]);
            ans += abs(tmp-b[x]);
            tmp=b[x];
        }
        printf("%I64d\n",ans);
    }
}