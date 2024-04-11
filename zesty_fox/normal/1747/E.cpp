// LUOGU_RID: 96654789
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=1e7+10,MOD=1e9+7;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,m;

int fac[N],faci[N],pw2[N];
void init(int lim){
    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=(i64)fac[i-1]*i%MOD;
    faci[lim]=qpow(fac[lim]);
    for(int i=lim-1;i>=0;i--) faci[i]=(i64)faci[i+1]*(i+1)%MOD;
    pw2[0]=1;
    for(int i=1;i<=lim;i++) pw2[i]=pw2[i-1]*2%MOD;
}

inline i64 C(int n,int m){
    return (i64)fac[n]*faci[m]%MOD*faci[n-m]%MOD;
}

void solve(){
    n=rdi(),m=rdi();init(n+m);
    i64 ans=0;
    for(int i=0;i<=min(n,m);i++){
        int s=n+m-i-1;
        ans+=C(n,i)*C(m,i)%MOD*(((i64)(i+2)*pw2[s]+(s?(i64)s*pw2[s-1]:0))%MOD)%MOD;
    }
    ans%=MOD;
    cout<<ans<<'\n';
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}