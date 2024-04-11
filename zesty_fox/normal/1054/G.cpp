#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define rdl read<ll>

const int N=2010;
int T,n,m;
bitset<N> bel[N],s[N];

int head[N],tot;
struct Edge{int to,nxt,w;}e[N*N*2];
void addedge(int x,int y,int w){
    e[++tot]=(Edge){y,head[x],w};
    head[x]=tot;
}

int vis[N],ti,dis[N],to[N];
vector<int> g[N];
void prim(){
    ++ti;memset(dis,0xcf,sizeof(dis));
    dis[1]=0;
    for(int i=1;i<=n;i++){
        int p,maxn=-1;
        for(int j=1;j<=n;j++){
            if(vis[j]>=ti||dis[j]<maxn) continue;
            maxn=dis[j],p=j;
        }
        vis[p]=ti;
        for(int j=head[p];j;j=e[j].nxt){
            int y=e[j].to;
            if(vis[y]>=ti||dis[y]>e[j].w) continue;
            dis[y]=e[j].w;to[y]=p;
        }
    }
}

void dfs(int x,int id,int& cnt){
    cnt++;vis[x]=ti;
    for(auto y:g[x]){
        if(!s[id][n-y]||vis[y]>=ti) continue;
        dfs(y,id,cnt);
    }
}

bool check(){
    for(int i=1;i<=m;i++){
        int siz=s[i].count();
        for(int j=1;j<=n;j++){
            if(s[i][n-j]){
                int cnt=0;++ti;dfs(j,i,cnt);
                if(cnt!=siz) return false;
                else break;
            }
        }
    }
    return true;
}

void clean(){
    tot=0;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=n;i++) bel[i].reset();
    for(int i=1;i<=n;i++) g[i].clear();
}

void solve(){
    cin>>n>>m;
    clean();
    for(int i=1;i<=m;i++){
        cin>>s[i];
        for(int j=1;j<=n;j++){
            if(s[i][n-j]) bel[j][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int w=(bel[i]&bel[j]).count();
            addedge(i,j,w);addedge(j,i,w);
        }
    }
    prim();
    for(int i=2;i<=n;i++){
        int x=i,y=to[i];
        g[x].push_back(y);g[y].push_back(x);
    }
    if(!check()) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=2;i<=n;i++) cout<<to[i]<<' '<<i<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--) solve();
    return 0;
}