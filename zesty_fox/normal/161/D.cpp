#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=50010,M=500010,INF=0x3f3f3f3f;
typedef long long ll;
struct Edge{int to,nxt;}e[M<<1];
int head[N],tot,m,n,k,rt=1,vis[N],dis[N],sz[N],f[N],tmp[N],cnt,siz;
ll ans,ans1,ans2,minx;
void addedge(int x,int y){
    e[++tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot;
}

void getroot(int x,int fa){
    f[x]=0,sz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa||vis[y]) continue;
        getroot(y,x);
        sz[x]+=sz[y];
        f[x]=max(f[x],sz[y]);
    }
    f[x]=max(f[x],siz-sz[x]);
    if(f[x]<minx) rt=x,minx=f[x];
}

void getdis(int x,int fa){
    tmp[++cnt]=dis[x];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa||vis[y]) continue;
        dis[y]=dis[x]+1;
        getdis(y,x);
    }
}

ll calc(int x,int dist){
    cnt=0;dis[x]=dist;
    getdis(x,0);
    ll sum=0;int l=1,r=cnt;
    sort(tmp+1,tmp+cnt+1);
    while(l<r){
        if(tmp[l]+tmp[r]<=k) sum+=r-l,++l;
        else --r;
    }
    return sum;
}

void dfs(int x){
    vis[x]=1;ans+=calc(x,0);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(vis[y]) continue;
        ans-=calc(y,1);
        siz=sz[y];minx=INF;
        getroot(y,0);
        dfs(rt);
    }
}

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    k=m-1;minx=INF;siz=n;
	getroot(1,0);
	dfs(rt);
    ans1=ans;ans=0;
    memset(vis,0,sizeof(vis));
    k=m;minx=INF;siz=n;
    getroot(1,0);
	dfs(rt);
    ans2=ans;
    printf("%lld\n",ans2-ans1);
	return 0;
}