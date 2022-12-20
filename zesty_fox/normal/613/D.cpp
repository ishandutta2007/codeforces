#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
#define rdl read<ll>
#define fi first
#define sec second
#define pb push_back
#define mp make_pair

const int N=100010,INF=0x3f3f3f3f;
int n,q,k,key[N];
struct Edge{int to,nxt;};
struct Graph{
    int head[N],tot;
    Edge e[N<<1];
    void addedge(int x,int y){
        e[++tot]=(Edge){y,head[x]};
        head[x]=tot;
    }
};

struct Tree:public Graph{
    int dfn[N],ti,f[N][19],dep[N];
    void dfs(int x,int fa){
        dfn[x]=++ti;f[x][0]=fa;dep[x]=dep[fa]+1;
        for(int i=1;i<=18;i++) f[x][i]=f[f[x][i-1]][i-1];
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(y==fa) continue;
            dfs(y,x);
        }
    }
    int lca(int x,int y){
        if(dep[x]<dep[y]) swap(x,y);
        for(int i=18;i>=0;i--){
            if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        }
        if(x==y) return x;
        for(int i=18;i>=0;i--){
            if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
        }
        return f[x][0];
    }
}t;

struct Virtual_Tree:public Graph{
    int dp[N][2],d[N],st[N],tp;
    void build_vtree(Tree& t,int* key,int cnt){
        memcpy(d,key,sizeof(int)*(cnt+1));
        sort(d+1,d+cnt+1,[&](int x,int y){return t.dfn[x]<t.dfn[y];});
        head[1]=0,tot=0;st[tp=1]=1;
        for(int i=1;i<=cnt;i++){
            if(d[i]==1) continue;
            int lc=t.lca(d[i],st[tp]);
            if(lc!=st[tp]){
                while(t.dfn[lc]<t.dfn[st[tp-1]]){
                    addedge(st[tp-1],st[tp]);
                    tp--;
                }
                if(t.dfn[lc]!=t.dfn[st[tp-1]]){
                    head[lc]=0,addedge(lc,st[tp]);
                    st[tp]=lc;
                }
                else addedge(lc,st[tp]),tp--;
            }
            head[d[i]]=0,st[++tp]=d[i];
        }
        for(int i=1;i<tp;i++) addedge(st[i],st[i+1]);
    }
    void dfs_dp(int,int);
}vt;

int iskey[N];
void Virtual_Tree::dfs_dp(int x,int fa){
    dp[x][0]=(!iskey[x])*n,dp[x][1]=iskey[x]*n;
    int minx=INF,sum=1,cnt=0;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        cnt+=iskey[y];dfs_dp(y,x);
        if(iskey[x]) dp[x][0]+=min(dp[y][1],dp[y][0]+1);
        else{
            minx=min(minx,dp[y][0]-dp[y][1]);
            sum+=min(dp[y][0],dp[y][1]);
            dp[x][1]+=dp[y][1];
        }
        //dp[x][0]=min(dp[x][0],INF);
        //dp[x][1]=min(dp[x][1],INF);
    }
    if(!iskey[x]&&cnt<=1) dp[x][0]=dp[x][1]+minx;
    if(!iskey[x]) dp[x][1]=min(dp[x][1],sum);
}

void solve(){
    k=rdi();
    for(int i=1;i<=k;i++) iskey[key[i]=rdi()]=1;
    for(int i=1;i<=k;i++){
        int x=key[i];
        if(iskey[t.f[x][0]]){
            for(int j=1;j<=k;j++) iskey[key[j]]=0;
            puts("-1");return;
        }
    }
    vt.build_vtree(t,key,k);
    vt.dfs_dp(1,0);
    printf("%d\n",min(vt.dp[1][0],vt.dp[1][1]));
    for(int j=1;j<=k;j++) iskey[key[j]]=0;
}

int main(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        t.addedge(x,y);t.addedge(y,x);
    }
    t.dfs(1,0);
    q=rdi();
    while(q--) solve();
    return 0;
}