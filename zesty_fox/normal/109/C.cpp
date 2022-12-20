#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
typedef long long ll;
const int N=100010;
struct Edge{int to,nxt,w;}e[N<<1];
int tot=1,head[N],siz[N],n;
ll f[N],g[N],ans;
void addedge(int x,int y,int w){
    e[++tot]=(Edge){y,head[x],w};
    head[x]=tot;
}

inline bool islucky(int x){
    while(x){
        if(x%10!=4&&x%10!=7) return false;
        x/=10;
    }
    return true;
}

void dfs(int x,int fa){
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        if(islucky(e[i].w)) f[x]+=siz[y];
        else f[x]+=f[y];
    }
}

void dfs1(int x,int fa,int inedge){
    if(x!=1) g[x]=islucky(e[inedge].w)?(n-siz[x]):(g[fa]+f[fa]-f[x]);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs1(y,x,i);
    }
}

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int x,y,w;scanf("%lld%lld%lld",&x,&y,&w);
        addedge(x,y,w);addedge(y,x,w);
    }
    dfs(1,0);dfs1(1,0,0);
    for(int i=1;i<=n;i++) ans+=f[i]*(f[i]-1)+g[i]*(g[i]-1)+f[i]*g[i]*2;
    cout<<ans<<endl;
    return 0;
}