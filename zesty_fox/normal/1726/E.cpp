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

const int MOD=998244353,N=6e5+10;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

i64 fac[N],faci[N],sum[N];
void init(int n){
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    faci[n]=qpow(fac[n]);
    for(int i=n-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;

    sum[0]=sum[1]=1;
    for(int i=2;i<=n;i++) sum[i]=(sum[i-1]+(i-1)*sum[i-2])%MOD;
}

inline i64 C(int n,int m){
    return fac[n]*faci[m]%MOD*faci[n-m]%MOD;
}

int n;

void solve(){
    n=rdi();i64 ans=0;
    for(int i=0;i<=n/2;i+=2){
        i64 v1=C(n-i,i)*fac[i]%MOD*faci[i/2]%MOD;
        i64 v2=sum[n-2*i];
        ans+=v1*v2%MOD;
    }

    ans%=MOD;cout<<ans<<endl;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(N-10);
    int T=rdi();
    while(T--) solve();
    return 0;
}