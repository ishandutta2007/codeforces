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

const int N=200010;

struct Edge{int to,nxt;}e[N<<1];
int head[N],tot,deg[N];

void addedge(int x,int y){
    e[++tot]={y,head[x]};
    head[x]=tot;
}

namespace Find_diam{
vi p;

int dis[N];
void dfs1(int x,int fa,int &res){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dis[y]=dis[x]+1;
        if(dis[y]>dis[res]) res=y;
        dfs1(y,x,res);
    }
}

bool find_path(int x,int fa,int dest,vi &pa){
    pa.pb(x);
    if(x==dest) return true;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        if(find_path(y,x,dest,pa)) return true;
    }
    pa.pop_back();return false;
}

void find_d(){
    int x=1;
    dfs1(1,0,x);
    int y=x;dis[x]=0;
    dfs1(x,0,y);
    find_path(x,0,y,p);
}
}
using Find_diam::p;

int n;
int lg2[N],dep[N];
void init_lg(){
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
}

int f[N][21];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;f[x][0]=fa;
    for(int i=1;i<=lg2[dep[x]];i++) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x);
    }
}

int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2[dep[x]-dep[y]];i>=0;i--)
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return y;
    for(int i=lg2[dep[x]];i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

int dist(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}

bool ond[N];

int rt;
ll ans;
vector<array<int,3> > steps;

void operate(int x,int y,int typ){
    steps.pb({x,y,typ?y:x});
}

void solve1(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!ond[i]&&deg[i]==1) q.push(i);
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        int dis1=dep[x]-1,dis2=dist(x,p.back());
        operate(x,dis1>dis2?p.front():p.back(),0);
        ans+=max(dis1,dis2);
        deg[f[x][0]]--;
        if(!ond[f[x][0]]&&deg[f[x][0]]==1) q.push(f[x][0]);
    }
}

void solve2(){
    int siz=p.size();
    for(int i=0;i<siz-1;i++) ans+=siz-i-1,operate(p[i],p.back(),0);
}

int main(){
    n=rdi();init_lg();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
        deg[x]++,deg[y]++;
    }
    Find_diam::find_d();
    for(auto x:p) ond[x]=1;
    rt=p.front(),dfs(rt,0);
    solve1(),solve2();
    printf("%lld\n",ans);
    for(auto tmp:steps){
        for(int i=0;i<3;i++) printf("%d ",tmp[i]);
        puts("");
    }
    return 0;
}