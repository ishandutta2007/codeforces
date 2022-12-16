#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define int long long
using namespace std;
struct Edge{
    int to,nxt,w;
}e[2000005],e1[2000005];
int n,m,head[1000005],head1[1000005],tot,tot1,st,vis[1000005];
int dfn[1000005],low[1000005],now,belong[1000005],cnt,sum[1000005];
int f[1000005],res,in[1000005],ans;
stack<int> s;
void addedge(int x,int y,int w){
    e[++tot].to=y;
    e[tot].w=w;
    e[tot].nxt=head[x];
    head[x]=tot;
}

void addedge1(int x,int y,int w){
    e1[++tot1].to=y;
    e1[tot1].w=w;
    e1[tot1].nxt=head1[x];
    head1[x]=tot1;
}

void tarjan(int x){
    dfn[x]=low[x]=++now;vis[x]=1;
    s.push(x);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        cnt++;
        int tmp;
        while(!s.empty()){
            tmp=s.top();s.pop();
            vis[tmp]=0;
            belong[tmp]=cnt;
            if(tmp==x) break;
        }
    }
}

inline int calc(int x){
    int y=sqrt(x*2);
    while(y*(y+1)/2>x) y--;
    return x*(y+1)-y*(y+1)*(y+2)/6;
}

int dfs(int x){
    if(f[x]) return f[x];
    for(int i=head1[x];i;i=e1[i].nxt){
        int y=e1[i].to;
        f[x]=max(f[x],dfs(y)+calc(e1[i].w));
    }
    return f[x]+=sum[x];
}

signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%lld%lld%lld",&x,&y,&w);
        addedge(x,y,w);
    }
    scanf("%lld",&st);
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=e[j].nxt){
            int y=e[j].to;
            if(belong[i]==belong[y]) sum[belong[i]]+=calc(e[j].w);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=e[j].nxt){
            int y=e[j].to;
            if(belong[i]!=belong[y]) 
                addedge1(belong[i],belong[y],e[j].w+sum[belong[y]]),in[belong[y]]++;
        }
    }
    while(!s.empty()) s.pop();
    for(int i=1;i<=cnt;i++){
        if(!in[i]) s.push(i);
        f[i]=-0x3f3f3f3f3f3f3f3f;
    }
    f[belong[st]]=sum[belong[st]];
    while(!s.empty()){
        int x=s.top();s.pop();
        for(int i=head1[x];i;i=e1[i].nxt){
            int y=e1[i].to;
            in[y]--;
            if(!in[y]){
                s.push(y);
            }
            f[y]=max(f[y],f[x]+e1[i].w);
        }
    }
    for(int i=1;i<=cnt;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}