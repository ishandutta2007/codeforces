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

const int N=110,MOD=998244853,INF=0x3f3f3f3f;
int n,m,g[N][N],ans1;

struct Edge{int to,nxt,f,w;}e[N*N*20];
int head[N*N*2],tot=1;
void addedge(int x,int y,int f,int w){
    e[++tot]=(Edge){y,head[x],f,w};head[x]=tot;
    e[++tot]=(Edge){x,head[y],0,-w};head[y]=tot;
}

int dis[N*N*2],pre[N*N*2],inq[N*N*2];
queue<int> q;
bool SPFA(int S,int T){
    memset(dis,0x3f,sizeof(int)*(T+2));
    dis[S]=0,inq[S]=1,q.push(S);
    while(!q.empty()){
        int x=q.front();q.pop();
        inq[x]=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f&&dis[y]>dis[x]+e[i].w){
                dis[y]=dis[x]+e[i].w;
                if(!inq[y]) inq[y]=1,q.push(y);
            }
        }
    }
    return dis[T]!=INF;
}

int vis[N*N*2];
int dfs(int x,int fl,int T){
    vis[x]=1;
    if(x==T) return fl;
    int rest=fl;
    for(int i=head[x];i&&rest;i=e[i].nxt){
        int y=e[i].to;
        if((!vis[y]||y==T)&&e[i].f&&dis[y]==dis[x]+e[i].w){
            int tmp=dfs(y,min(rest,e[i].f),T);
            e[i].f-=tmp,e[i^1].f+=tmp,rest-=tmp;
        }
    }
    return fl-rest;
}

int mincost,maxflow,S,T;
void MCMF(){
    while(SPFA(S,T)){
        memset(vis,0,sizeof(int)*(T+2));
        int fl=dfs(S,INF,T);
        maxflow+=fl,mincost+=fl*dis[T];
    }
}

int in[N],out[N],sum;
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]) out[i]++;
            if(g[j][i]) in[i]++;
        }
        sum+=out[i]*(out[i]-1)/2;
    }

    S=0,T=n*n+n+5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-in[i]-out[i];j++) addedge(i,T,1,out[i]+j-1);
        for(int j=i+1;j<=n;j++){
            if(g[i][j]||g[j][i]) continue;
            int id=i*n+j;
            addedge(S,id,1,0);
            addedge(id,i,1,0);
            addedge(id,j,1,0);
        }
    }

    MCMF();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(g[i][j]||g[j][i]) continue;
            int id=i*n+j;
            for(int k=head[id];k;k=e[k].nxt){
                int y=e[k].to;
                if(y>=1&&y<=n&&!e[k].f){
                    if(y==j) g[j][i]=1;
                    else g[i][j]=1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d",g[i][j]);
        puts("");
    }
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        g[x][y]=1;
    }
    solve();
    return 0;
}