#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define inf 2147483640
#define MOD 1000000007
#define Pi acos(-1.0)
#define free(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
using namespace std;
 
const int maxn=100010;
LL fac[maxn],ifac[maxn];
int F,W,H,n;
LL P,Q;
 
LL C(LL n,LL m) {
    if (n==m && n==-1) return 1;
    return n<0||m<0||n<m ? 0 : fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
LL power(LL a,LL b) {
    LL res=1;
    while (b) {
        if (b&1) (res*=a)%=MOD;
        b>>=1;(a*=a)%=MOD;
    }
    return res;
}
int main() {
    scanf("%d%d%d",&F,&W,&H);
    n=F+W;
    fac[0]=1;for (int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[100000]=power(fac[100000],MOD-2);
    for (int i=100000;i;i--) ifac[i-1]=ifac[i]*i%MOD;
    for (int i=1;i<=n;i++) {
        int w=(i&1) ? 1 : 2;
        for (int j=i>>1;j<=(i+1)>>1;j++) {
            LL q=C(F-1,j-1)*C(W-1,i-j-1)%MOD*w%MOD;
            LL p=C(F-1,j-1)*C(W-1LL*(i-j)*H-1,i-j-1)%MOD*w%MOD;
            (Q+=q)%=MOD,(P+=p)%=MOD;
        }
    }
    printf("%I64d",P*power(Q,MOD-2)%MOD);
    return 0;
}