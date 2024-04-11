#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 1006;

LL a[MAX_N];

int main () {
    int n;
    LL k;
    scanf("%d %lld",&n,&k);
    for (int i=1;n>=i;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    LL ans=0;
    for (int i=1;n>=i;i++) {
        while (k < (a[i] + 1)/2) {
            ans++;
            k*=2;
        }
        k = max(k,a[i]);
    }
    printf("%lld\n",ans);
}