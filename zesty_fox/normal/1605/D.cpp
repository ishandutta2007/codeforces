#include <bits/stdc++.h>

using namespace std;

using ll=long long;
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010;

vi e[N],d[N];
int n,p[N],vis[N];

void dfs(int x,int fa,int dep){
    d[dep].pb(x);
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x,dep+1);
    }
}

void solve(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0,1);int sum=0;
    for(int i=1;i<=n;i+=2) sum+=d[i].size();
    for(int i=__lg(n);i>=0;i--){
        int L=(1<<i),R=min((1<<(i+1))-1,n),cnt=R-L+1;
        if(sum>=cnt){
            for(int j=L;j<=R;j++) vis[j]=1;
            sum-=cnt;
        }
    }

    vi sel[2];
    for(int i=1;i<=n;i++) sel[vis[i]].pb(i);

    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)d[i].size();j++){
            p[d[i][j]]=sel[i&1].back();
            sel[i&1].pop_back();
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
    puts("");

    for(int i=1;i<=n;i++) e[i].clear(),d[i].clear(),vis[i]=0;
}

int T;
int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    T=rdi();
    while(T--) solve();
    return 0;
}