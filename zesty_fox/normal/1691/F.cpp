#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010,MOD=1e9+7;

int n,k;
i64 ans;
vi e[N];

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

i64 c[N];
void init(){
    c[k]=1;
    for(int i=k+1;i<=n;i++) c[i]=c[i-1]*i%MOD*qpow(i-k)%MOD;
}

int siz[N];
void dfs(int x,int fa){
    siz[x]=1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
    static int sz[N],tp;tp=0;
    i64 sum=0;
    for(auto y:e[x]){
        sz[++tp]=(y==fa?n-siz[x]:siz[y]);
        sum+=c[sz[tp]];
    }
    sum%=MOD;
    for(int i=1;i<=tp;i++) ans+=(i64)sz[i]*(n-sz[i])%MOD*(c[n-sz[i]]-(sum-c[sz[i]]))%MOD;
    ans+=n*(c[n]-sum)%MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();init();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0);ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}