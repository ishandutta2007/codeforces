#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=1e6+7,inf=1e9;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
    e[++s_e]={y,head[x]},head[x]=s_e;
}
int d1,d2,rt,maxd;
void dfs(int x,int fa,int d){
    if(d>maxd)maxd=d,rt=x;
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;
	if(y!=fa)dfs(y,x,d+1);
    }
}
int n,s_dfn,dfn[N],dep[N],f[N][18];
bool flg[N];
void dfs1(int x,int fa){
    f[x][0]=fa,dfn[x]=++s_dfn,dep[x]=dep[fa]+1;
    for(int i=1;i<=17;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt)if(e[i].to!=fa)dfs1(e[i].to,x);
}
inline int LCA(int x,int y){
    if(x==y)return x;if(dfn[x]>dfn[y])swap(x,y);
    for(int i=17;~i;i--)if(dfn[f[y][i]]>dfn[x])y=f[y][i];
    return f[y][0];
}
inline int dist(int x,int y){return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);}
int deg[N];
queue<int>q;
vector<int>d;
vector<pair<int,pair<int,int> > >vec;
int main(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	add_e(x,y),add_e(y,x),deg[x]++,deg[y]++;
    }
    dfs(1,0,0),d1=rt,maxd=0,dfs(rt,0,0),d2=rt,dfs1(d1,0);
    {
	int x=d2;flg[d1]=1;
	while(x!=d1)flg[x]=1,d.push_back(x),x=f[x][0];
	d.push_back(d1);
    }
    for(int i=1;i<=n;i++)if(deg[i]==1)q.push(i);
    ll ans=0;
    while(!q.empty()){
	int x=q.front();q.pop();
	if(flg[x])continue;
	int dis1=dist(d1,x),dis2=dist(d2,x);
	if(dis1>dis2)ans+=dis1,vec.push_back({d1,{x,x}});
	else ans+=dis2,vec.push_back({d2,{x,x}});
	for(int i=head[x];i;i=e[i].nxt){
	    int y=e[i].to;
	    if(--deg[y]==1)q.push(y);
	}
    }
    while((int)d.size()>1)ans+=d.size()-1,vec.push_back({d2,{d.back(),d.back()}}),d.pop_back();
    printf("%lld\n",ans);
    for(auto i:vec)printf("%d %d %d\n",i.first,i.second.first,i.second.second);
    return 0;
}