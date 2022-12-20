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

const int N=80010,INF=0x3f3f3f3f;
struct Edge{int to,nxt,c;}e[N<<4];
int head[N],cur[N],tot=1;
void addedge(int x,int y,int c){
    e[++tot]=(Edge){y,head[x],c};head[x]=tot;
    e[++tot]=(Edge){x,head[y],0};head[y]=tot;
}

namespace Dinic{
int S,T,dep[N];
queue<int> q;
bool bfs(){
    memset(dep,0,sizeof(dep));
    for(int i=1;i<=T;i++) cur[i]=head[i];
    while(!q.empty()) q.pop();
    dep[S]=1;q.push(S);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(!e[i].c||dep[y]) continue;
            dep[y]=dep[x]+1;q.push(y);
            if(y==T) return true;
        }
    }
    return false;
}
int dfs(int x,int fl){
    if(x==T||!fl) return fl;
    int rest=fl;
    for(int i=cur[x];i&&rest;i=e[i].nxt){
        cur[x]=i;
        int y=e[i].to;
        if(dep[y]!=dep[x]+1||!e[i].c) continue;
        int tmp=dfs(y,min(rest,e[i].c));
        e[i].c-=tmp;e[i^1].c+=tmp;
        rest-=tmp;
    }
    return fl-rest;
}
int maxflow;
void solve(){
    while(bfs()) maxflow+=dfs(S,INF);
}
}
using namespace Dinic;

#define id(x,y,z) (((x)-1)*m+(y)+(z)*n*m)
const int M=210;
int n,m,cnt,vis[N],point;
char tmp[M][M];
int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) scanf("%s",tmp[i]+1);
    S=n*m*2+1,T=n*m*2+2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(tmp[i][j]=='.') continue;
            cnt++;
            if(tmp[i-1][j]=='#'&&!vis[id(i,j,0)]){
                vis[id(i,j,0)]=1,point++;
                addedge(S,id(i,j,0),1);
            }
            if(tmp[i][j-1]=='#'&&!vis[id(i,j-1,1)]){
                vis[id(i,j-1,1)]=1,point++;
                addedge(id(i,j-1,1),T,1);
            }
            if(tmp[i-1][j]=='#'){
                if(tmp[i][j+1]=='#') addedge(id(i,j,0),id(i,j,1),1);
                if(tmp[i][j-1]=='#') addedge(id(i,j,0),id(i,j-1,1),1);
            }
            if(tmp[i+1][j]=='#'){
                if(tmp[i][j+1]=='#') addedge(id(i+1,j,0),id(i,j,1),1);
                if(tmp[i][j-1]=='#') addedge(id(i+1,j,0),id(i,j-1,1),1);
            }
        }
    }
    solve();
    printf("%d\n",cnt-(point-maxflow));
    return 0;
}