#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=5e5+10,MOD=998244353;

int n;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

i64 a[N],fac[N],faci[N];
void init(){
    a[1]=1;
    for(int i=2;i<=n;i++) a[i]=qpow(i,i-1);
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    faci[n]=qpow(fac[n]);
    for(int i=n-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

inline i64 C(int n,int m){
    return fac[n]*faci[m]%MOD*faci[n-m]%MOD;
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi();
    if(n&1) {puts("0");return 0;}
    init();i64 sum=0;
    for(int i=1;i<n;i++)
        sum+=(i&1?-1:1)*C(n-1,i-1)*a[i]%MOD*a[n-i]%MOD*i%MOD*(n-i)%MOD;
    sum=(sum%MOD+MOD)%MOD;
    i64 ans=sum*qpow((i64)n*(n-1)/2%MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}