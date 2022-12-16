#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2000010,MOD=1e9+7,INV2=500000004;

int n,m,k;

ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

ll fac[N],faci[N];

void init(int lim){
    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
    faci[lim]=qpow(fac[lim]);
    for(int i=lim-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

ll C(int x,int y){
    if(x<0||y<0||x<y) return 0;
    return fac[x]*faci[y]%MOD*faci[x-y]%MOD;
}

void solve(){
    n=rdi(),m=rdi(),k=rdi();ll ans=0;
    if(m==n) ans=n;
    else{
        ll pw=qpow(INV2,n);
        for(int i=0;i<=m;i++,(pw*=2)%=MOD){
            int x=n-i,y=m-i;
            ans+=i*C(x-1,y)%MOD*pw%MOD;
        }
        ans%=MOD;
    }
    (ans*=k)%=MOD;
    cout<<ans<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();init(N-10);
    while(T--) solve();
    return 0;
}