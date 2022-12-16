#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
struct Edge{int to,nxt;}e[N<<1];
int head[N],tot,n,m,ans;
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}
int f[N],flg[N],cnt[N];
int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
void merge(int x,int y){
    int x1=find(x),y1=find(y);
    if(x1!=y1){
        f[y1]=x1;
        if(cnt[x]>1||cnt[y]>1) flg[x1]=1;
        flg[x1]+=flg[y1];
    }
}
int dfn[N],low[N],ti,st[N],tp,vis[N];
int color,col[N];
void tarjan(int x){
    dfn[x]=low[x]=++ti;
    st[++tp]=x;vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        color++;
        while(1){
            col[st[tp]]=color;
            vis[st[tp]]=0;
            if(st[tp]==x) break;
            tp--;
        }
        col[x]=color;vis[x]=0;tp--;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=color;i++) f[i]=i;
    for(int i=1;i<=n;i++) cnt[col[i]]++;
    for(int i=1;i<=color;i++) if(cnt[i]>1) flg[i]=1;
    for(int x=1;x<=n;x++){
        for(int i=head[x];i;i=e[i].nxt){
            int x1=col[x],y1=col[e[i].to];
            if(x1!=y1&&find(x1)!=find(y1)) merge(x1,y1);
        }
    }
    for(int i=1;i<=color;i++){
        if(f[i]==i&&flg[i]==0) ans+=cnt[i]-1;
        else ans+=cnt[i];
    }
    cout<<ans<<endl;
    return 0;
}