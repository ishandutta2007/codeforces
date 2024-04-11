#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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

const int N=100010;
int n,MOD,w[N],q;

inline ll _phi(ll x){
    ll res=x;
    for(ll i=2;i<=x/i;i++){
        if(x%i) continue;
        while(x%i==0) x/=i;
        res=res/i*(i-1);
    }    
    if(x>1) res=res/x*(x-1);
    return res;
}

__gnu_pbds::gp_hash_table<ll,ll> ha;
inline ll phi(ll x){return ha.find(x)==ha.end()?ha[x]=_phi(x):ha[x];}
inline pair<ll,bool> qpow(ll x,pair<ll,bool> _y,ll MOD){
    ll y=_y.se?_y.fi%phi(MOD)+phi(MOD):_y.fi%phi(MOD),res=1;
    bool flg=0;
    if(x>=MOD&&(_y.fi||_y.se)) x%=MOD,flg|=1;
    while(y){
        if(y&1){
            res*=x;
            if(res>=MOD) flg|=1;
            res%=MOD;
        }
        x*=x;y>>=1;
        if(x>=MOD){
            x%=MOD;
            if(y) flg|=1;
        }
    }
    return mp(res,flg);
}

pair<ll,bool> dfs(int x,int lim,int MOD){
    if(MOD==1) return mp(0,1);
    else if(x>lim||w[x]==1) return mp(1,0);
    pair<ll,bool> tmp=dfs(x+1,lim,phi(MOD));
    return qpow(w[x],tmp,MOD);
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=rdi(),MOD=rdi();
    for(int i=1;i<=n;i++) w[i]=rdi();
    q=rdi();
    while(q--){
        int l=rdi(),r=rdi();
        printf("%lld\n",dfs(l,r,MOD).fi);
    }
    return 0;
}