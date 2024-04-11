#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 2e5 + 6;
const int mod = 1e9 + 7;

LL pow(LL a,LL n) {
    if (n==0) return 1;
    else if (n==1) return a%mod;
    LL ret=pow(a,n/2);
    ret*=ret;
    if (n&1) {
        ret%=mod;
        ret*=a;
    }
    return ret%mod;
}

LL a[MAX_N];
LL fact[MAX_N];

LL C(LL n,LL m) {
    LL ret=fact[n] * pow(fact[m],mod-2);
    ret%=mod;
    ret*=pow(fact[n-m],mod-2);
    return ret%mod;
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++) {
        scanf("%lld",&a[i]);
    }
    fact[0]=1;
    for (int i=1;MAX_N>i;i++) {
        fact[i] = fact[i-1]*i;
        fact[i]%=mod;
    }
    if (n%2==1) {
        if (n==1) {
            printf("%lld\n",a[1]);
            return 0;
        }
        else if (n%4 == 1) {
            LL nn=n/2+1;
            LL ans=0;
            for (int i=1,ii=1;n>=i;i+=2,ii++) {
                ans += a[i]*C(nn-1,ii-1);
                ans%=mod;
            }
            printf("%lld\n",ans);
        }
        else {
            LL a1=0,a2=0,a3=0;
            LL nn=n/2;
            for (int i=1,ii=1;n-2>=i;i+=2,ii++) {
                a1 += a[i]*C(nn-1,ii-1);
                a1%=mod;
            }
            for (int i=2,ii=1;n>=i;i+=2,ii++) {
                a2 += a[i]*C(nn-1,ii-1);
                a2%=mod;
            }
            for (int i=3,ii=1;n>=i;i+=2,ii++) {
                a3 += a[i]*C(nn-1,ii-1);
                a3%=mod;
            }
            LL ans=a1+2*a2-a3;
            printf("%lld\n",(ans%mod+mod)%mod);
        }
    }
    else {
        LL odd=0;
        LL nn=n/2;
        for (int i=1,ii=1;n>=i;i+=2,ii++) {
            odd += a[i]*C(nn-1,ii-1);
            odd%=mod;
        }
        LL even=0;
        for (int i=2,ii=1;n>=i;i+=2,ii++) {
            even += a[i]*C(nn-1,ii-1);
            even%=mod;
        }
        LL ans=0;
        if (n%4==0) ans=odd-even;
        else ans=odd+even;
        printf("%lld\n",(ans%mod+mod)%mod);
    }
}