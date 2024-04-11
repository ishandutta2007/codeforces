#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010,MOD=1e9+7;
inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int p[N],pcnt,v[N],mu[N];
ll fac[N],faci[N];
void init(int lim){
    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
    faci[lim]=qpow(fac[lim]);
    for(int i=lim-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;

    v[1]=mu[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=p[++pcnt]=i,mu[i]=-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j];
            mu[p[j]*i]=(i%p[j]?-mu[i]:0);
        }
    }
}

inline ll C(int x,int y){
    if(x<y||x<0||y<0) return 0;
    return fac[x]*faci[x-y]%MOD*faci[y]%MOD;
}

int n,m;
vi ys;
ll ans;
void solve(){
    n=rdi(),m=rdi();

    ys.clear();
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            ys.pb(i);
            if(i*i!=n) ys.pb(n/i);
        }
    }

    ans=0;
    for(auto d:ys) ans=ans+mu[d]*C(n/d-1,m-1)%MOD;
    ans=(ans%MOD+MOD)%MOD;
    printf("%lld\n",ans);
}

int T;
int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(N-10);T=rdi();
    while(T--) solve();
    return 0;
}