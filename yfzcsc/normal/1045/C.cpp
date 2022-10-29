#include<bits/stdc++.h>
#define maxn 200100
#define maxm 501000
using namespace std;
struct WXHAKIOI2018{
    struct edge{
        int r,nxt;
    }e[maxm<<2];
    int head[maxn<<1],esz;
    void addedge(int u,int v){
    //  printf("[Addedge:%d->%d]\n",u,v);
        e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
        e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
    }
}A,B;
int fa[maxn<<1][20],anses[maxn],tag[maxn<<2],dep[maxn<<1],n,m,q,tp;
int dfn[maxn],id,sta[maxn],low[maxn],tim,dist[maxn<<1];
void tarjan(int u,int f){
    sta[++tp]=u,dfn[u]=low[u]=++tim;
    bool flag=false;
    for(int t=A.head[u],v,x;t;t=A.e[t].nxt)
        if(A.e[t].r!=f||flag){
            if(!dfn[v=A.e[t].r]){
                tarjan(v,u),low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u]){
                    id++;
                    dist[id]=0;
                    do{
                        x=sta[tp--];
                        B.addedge(x,id);
                    }while(x!=v);
                    B.addedge(id,u);
                }   
            }
            else low[u]=min(low[u],dfn[v]);
             
        } else flag=true;
}
void pre(int u,int f){
    fa[u][0]=f,dep[u]=dep[f]+1;
    dist[u]+=dist[f];
    for(int i=1;fa[u][i-1];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int t=B.head[u];t;t=B.e[t].nxt)if(B.e[t].r!=f)
        pre(B.e[t].r,u);
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;d>>i;i++)if(d>>i&1)u=fa[u][i];
    if(u==v)return u;
    for(int i=18;i>=0;--i)if(fa[u][i]!=fa[v][i])
        u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int main(){
    scanf("%d%d%d",&n,&m,&q),id=n;
    for(int i=1;i<=n;++i)dist[i]=1;
    for(int i=1,u,v;i<=m;++i)
        scanf("%d%d",&u,&v),A.addedge(u,v);
    tarjan(1,0),pre(1,0);
    for(int i=1,u,v;i<=q;++i){
        scanf("%d%d",&u,&v);
        int lc=lca(u,v);
  		printf("%d\n",dist[u]+dist[v]-dist[lc]-dist[fa[lc][0]]-1);
    }
}