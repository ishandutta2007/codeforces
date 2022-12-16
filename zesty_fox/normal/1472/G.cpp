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

const int N=200010;
int T,n,m,head[N],tot;
struct Edge{int to,nxt;}e[N<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

queue<int> q;
int dis[N];
void bfs(int s){
    memset(dis,0x3f,sizeof(int)*(n+5));
    while(!q.empty()) q.pop();
    dis[s]=0;q.push(s);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]>dis[x]+1){
                dis[y]=dis[x]+1;
                q.push(y);
            }
        }
    }
}

int ans[N],deg[N],topo[N],cur;
void toposort(){
    memset(ans,0x3f,sizeof(int)*(n+5));
    memset(deg,0,sizeof(int)*(n+5));
    cur=0;
    for(int x=1;x<=n;x++){
        ans[x]=dis[x];
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]<=dis[x]) ans[x]=min(ans[x],dis[y]);
            else deg[y]++;
        }
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int x=q.front();q.pop();
        topo[++cur]=x;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]<=dis[x]) continue;
            deg[y]--;
            if(!deg[y]) q.push(y);
        }
    }
}

void solve(){
    n=rdi(),m=rdi();
    memset(head,0,sizeof(int)*(n+5));tot=0;
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);
    }
    bfs(1);toposort();
    for(int id=cur;id>=1;id--){
        int x=topo[id];
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]<=dis[x]) continue;
            ans[x]=min(ans[x],ans[y]);
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
}

int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}