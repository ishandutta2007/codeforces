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

const int N=1000010,MOD=1e9+7;

int v[N],p[N],pcnt,phi[N];

ll fac[N],faci[N];
ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

void init(int lim){
    v[1]=1,phi[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,phi[i]=i-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j],phi[p[j]*i]=i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j];
        }
    }

    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
    faci[lim]=qpow(fac[lim]);
    for(int i=lim;i>=1;i--) faci[i-1]=faci[i]*i%MOD;
}

inline ll C(int x,int y){
    if(x<y) return 0;
    return fac[x]*faci[y]%MOD*faci[x-y]%MOD;
}

int n,k,q,cnt[N];
ll ans;

void modify(int x){
    ans=(ans+(C(cnt[x]+1,k)-C(cnt[x],k)+MOD)*phi[x]%MOD+MOD)%MOD;
    cnt[x]++;
}

void insert(int x){
    for(int i=1;i<=x/i;i++){
        if(x%i==0){
            modify(i);
            if(i*i!=x) modify(x/i);
        }
    }
    ans=(ans%MOD+MOD)%MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi(),q=rdi();init(N-10);
    for(int i=1;i<=n;i++) insert(rdi());
    while(q--) insert(rdi()),printf("%lld\n",ans);
    return 0;
}