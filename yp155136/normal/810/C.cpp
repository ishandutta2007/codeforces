#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int MAX_N = 3e5 + 6;

LL ppow(LL a,LL n) {
    if (n==0) return 1;
    else if (n==1) return a;
    LL ret=ppow(a,n/2);
    ret*=ret;
    if (n&1) {
        ret%=mod;
        ret*=a;
    }
    return ret%mod;
}

LL a[MAX_N];

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    LL ans=0;
    LL tot=0;
    for (int i=2;n>=i;i++) {
        tot += (a[i]-a[1])*ppow(2,i-2);
        tot %= mod;
    }
    ans = tot;
    //cout<< (2*ppow(2,n-2)) % mod<<endl;
    for (int i=2;n>=i;i++) {
        tot -= (a[i] - a[i-1])*(ppow(2,n-i+1)-1);
        //cout<<"i=  "<<i<<" , tot = "<<tot<<endl;
        tot = (tot%mod+mod)%mod;
        tot = tot* ppow(2,mod-2);
        tot%=mod;
        ans += tot;
        ans%=mod;
        ans = (ans%mod+mod)%mod;
    }
    printf("%lld\n",ans%mod);
}