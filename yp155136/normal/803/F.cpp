#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 +7;
const int MAX_N = 1e5 + 6;

LL pow(LL a,LL n) {
    if (n==1) return a;
    else if (n==0) return 1;
    LL ret=pow(a,n/2);
    ret*=ret;
    if (n&1) {
        ret%=mod;
        ret*=a;
    }
    return ret%mod;
}

int u[MAX_N];
int cnt[MAX_N];
int f[MAX_N];

bool Prime(int x) {
    for (int i=2;320>=i;i++) {
        if (i!=x && x%i==0) return false;
    }
    return true;
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++) {
        int x;
        scanf("%d",&x);
        for (LL j=1;320>=j;j++) {
            if (j*j > x) break;
            if (x%j==0) {
                cnt[j]++;
                if (x/j != j) cnt[x/j]++;
            }
        }
    }
    int nn=100000;
    for (int i=1;nn>=i;i++) {
        f[i] = pow(2,cnt[i])-1;
    }
    for (int i=1;nn>=i;i++) {
        u[i]=1;
    }
    for (LL i=2;nn>=i;i++) {
        if (Prime(i)) {
            for (LL j=i*i;nn>=j;j+=(i*i)) {
                u[j] = 0;
            }
            for (LL j=i;nn>=j;j+=i) {
                if (u[j] != 0) u[j] = -u[j];
            }
        }
    }
    LL ans=0;
    for (int i=1;nn>=i;i++) {
        ans += u[i]*f[i];
        ans = (ans%mod+mod)%mod;
    }
    printf("%lld\n",ans);
}