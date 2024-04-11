#include <bits/stdc++.h>
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
#define pb push_back
#define mp make_pair

const int N=210,MOD=1e9+7,INV2=500000004;
inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n;
vi e[N];

ll f[N][N];
void init(){
    for(int i=1;i<=n;i++) f[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=(f[i-1][j]+f[i][j-1])*INV2%MOD;
        }
    }
}

int lc[N][N],fa[N],dep[N];
vi subt[N];
void dfs(int x,int fat){
    fa[x]=fat,dep[x]=dep[fat]+1;
    subt[x]=vi({x});
    for(auto y:e[x]){
        if(y==fat) continue;
        dfs(y,x);
        for(auto tmp:subt[y]) subt[x].pb(tmp);
    }
}

ll ans;
void solve(int rt){
    dfs(rt,0);
    for(int x=1;x<=n;x++){
        int y=x;
        while(y) lc[x][y]=lc[y][x]=y,y=fa[y];
        int tmp=e[x].size();
        for(int i=0;i<tmp;i++){
            if(e[x][i]==fa[x]) continue;
            for(int j=i+1;j<tmp;j++){
                if(e[x][j]==fa[x]) continue;
                for(auto k:subt[e[x][i]]){
                    for(auto l:subt[e[x][j]]){
                        lc[k][l]=lc[l][k]=x;
                    }
                }
            }
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<x;y++){
            int lca=lc[x][y];
            (ans+=f[dep[x]-dep[lca]][dep[y]-dep[lca]])%=MOD;
        }
    }
}

int main(){
    n=rdi();init();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    for(int i=1;i<=n;i++) solve(i);
    ans=ans*qpow(n)%MOD;
    cout<<ans<<endl;
    return 0;
}