#include <bits/stdc++.h>
#include <fstream>
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
#define se second
#define mp make_pair
#define pb push_back

const int N=200010;
struct Edge{int to,nxt,w;}e[N];
int n,m,q,head[N],tot;

void addedge(int x,int y,int w){
    e[++tot]=(Edge){y,head[x],w};
    head[x]=tot;
}

int dfn[N],low[N],ti,st[N],tp,ins[N];
int color,col[N];
void tarjan(int x){
    st[++tp]=x,ins[x]=1,dfn[x]=low[x]=++ti;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(!dfn[y]) tarjan(y),low[x]=min(low[x],low[y]);
        else if(ins[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        ++color;
        do{
            col[st[tp]]=color,ins[st[tp]]=0;
        }while(st[tp--]!=x);
    }
}

int vis[N],istree[N];
ll gc[N],dep[N];
void dfs(int x){
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(vis[y]||col[x]!=col[y]) continue;
        istree[i]=1;
        dep[y]=dep[x]+e[i].w;
        dfs(y);
    }
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),l=rdi();
        addedge(x,y,l);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    for(int x=1;x<=n;x++){
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(col[x]!=col[y]) continue;
            gc[col[x]]=__gcd(gc[col[x]],dep[x]+e[i].w-dep[y]);
        }
    }
    q=rdi();
    while(q--){
        ll x=rdi(),s=rdi(),t=rdi();
        if(!gc[col[x]]) puts(!s?"YES":"NO");
        else puts((s%__gcd(gc[col[x]],t)?"NO":"YES"));
    }
    return 0;
}