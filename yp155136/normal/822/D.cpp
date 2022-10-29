#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 5e6 + 6;
const LL mod=1e9+7;

LL p[MAX_N];

void build() {
    p[0]=p[1]=1;
    for (int i=2;MAX_N>i;i++) {
        if (p[i]==0) {
            p[i]=i;
            for (int j=i;MAX_N>j;j+=i) {
                if (p[j]==0) p[j]=i;
            }
        }
    }
}

LL f(LL a) {
    LL ret=0;
    //cout<<"a="<<a<<endl;
    while (a!=1) {
        ret += (a/p[a]) * ((p[a])*(p[a]-1)/2);
        ret%=mod;
        a/=p[a];
    }
    //cout<<"ret="<<ret<<endl;
    return ret;
}

int main () {
    build();
    LL t,l,r;
    scanf("%lld %lld %lld",&t,&l,&r);
    LL ans=0;
    LL pow=1;
    for (LL i=l;r>=i;i++) {
        if (i!=l) {
            pow=pow*t%mod;
        }
        ans += pow*f(i);
        ans%=mod;
    }
    printf("%lld\n",ans);
}