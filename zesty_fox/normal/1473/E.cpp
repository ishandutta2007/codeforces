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
#define mp make_pair

#define id(x,y) (((x)-1)*4+(y)+1)
const int N=1000010;
int n,m,tot,head[N];
struct Edge{int to,nxt;ll w;}e[N<<2];
ll dis[N];
void add_edge(int x,int y,ll w){
    e[++tot]=(Edge){y,head[x],w};
    head[x]=tot;

}
void addedge(int x,int y,ll w){
    for(int i=0;i<4;i++){
        add_edge(id(x,i),id(y,i),w);
        if(!(i&1)) add_edge(id(x,i),id(y,i|1),0);
        if(!(i&2)) add_edge(id(x,i),id(y,i|2),2*w);
        if(!(i&1)&&!(i&2)) add_edge(id(x,i),id(y,i|1|2),w);
    }
}

priority_queue<pair<ll,int> > q;
bool vis[N];
void dijsktra(int st){
    memset(dis,0x3f,sizeof(dis));
    dis[id(st,0)]=0;q.push(mp(dis[id(st,0)],id(st,0)));
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(vis[y]) continue;
            if(dis[y]>dis[x]+e[i].w){
                dis[y]=dis[x]+e[i].w;
                q.push(mp(-dis[y],y));
            }
        }
    }
}

signed main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();ll w=rdl();
        addedge(x,y,w);addedge(y,x,w);
    }
    dijsktra(1);
    for(int i=2;i<=n;i++) printf("%lld ",dis[id(i,3)]);
    puts("");
    return 0;
}