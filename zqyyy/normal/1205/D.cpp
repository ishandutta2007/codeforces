#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1007;
struct edge{int x,y,w;};
vector<edge>ans;
vector<int>G[N],d;
int n,rt,sz[N];
void find(int x,int fa){
    sz[x]=1;int max_sz=0;
    for(int y:G[x]){
	if(y==fa)continue;
	find(y,x),sz[x]+=sz[y];
	max_sz=max(max_sz,sz[y]);
    }
    max_sz=max(max_sz,n-sz[x]);
    if(max_sz<=n/2)rt=x;
}
int s_dfn,dfn[N];
void dfs(int x,int fa,int s){
    dfn[x]=++s_dfn,ans.push_back({x,fa,s*(dfn[x]-dfn[fa])});
    for(int y:G[x]){
	if(y==fa)continue;
	dfs(y,x,s);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	G[x].push_back(y),G[y].push_back(x);
    }
    find(1,0),find(rt,0);int sum=0,p=0;
    sort(G[rt].begin(),G[rt].end(),[](int x,int y){return sz[x]<sz[y];});
    for(int x:G[rt]){
	sum+=sz[x];
	if(sum>=n/3){p=x;break;}
    }
    int s=1;
    for(int x:G[rt]){
	dfs(x,rt,s);
	if(x==p)s_dfn=0,s=sum+1;
    }
    for(auto x:ans)printf("%d %d %d\n",x.x,x.y,x.w);
    return 0;
}