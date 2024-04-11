#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+7;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
	e[++s_e]=(Edge){y,head[x]},head[x]=s_e;
}
int s_dfn,dfn[N],sz[N],f[N][18],dep[N];
void dfs(int x,int fa){
	dfn[x]=++s_dfn,sz[x]=1,dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1;i<=17;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt)if(e[i].to^fa)dfs(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline int LCA(int x,int y){
	if(x==y)return x;if(dfn[x]>dfn[y])swap(x,y);
	for(int i=17;~i;i--)
		if(dfn[f[y][i]]>dfn[x])y=f[y][i];
	return f[y][0];
}
struct D{
	int tim,dis,col,id;
	bool operator <(const D &q) const {
		return tim^q.tim?tim>q.tim:col>q.col;
	}
}dis[N];
priority_queue<D>q;
int n,Q,m,k;
int tp,stk[N],a[N],s[N],v[N];
bool vis[N];
vector<int>d;
vector<pii>G[N];
inline void addedge(int x,int y,int w){
	G[x].push_back(pii(y,w)),G[y].push_back(pii(x,w));
}
inline void work(){
 	k=read(),m=read();
	for(int i=1;i<=k;i++)s[i]=read(),v[i]=read(),d.push_back(s[i]);
	for(int i=1;i<=m;i++)a[i]=read(),d.push_back(a[i]);
	for(int i=1;i<=k;i++)q.push(dis[s[i]]=D{0,0,i,s[i]});
	sort(d.begin(),d.end(),[](int x,int y){return dfn[x]<dfn[y];});
	for(int i=d.size()-2;~i;i--)d.push_back(LCA(d[i],d[i+1]));
	sort(d.begin(),d.end(),[](int x,int y){return dfn[x]<dfn[y];});
	d.erase(unique(d.begin(),d.end()),d.end()),tp=0;
	for(auto x:d){
		while(tp && dfn[stk[tp]]+sz[stk[tp]]-1<dfn[x])tp--;
		if(tp)addedge(x,stk[tp],dep[x]-dep[stk[tp]]);stk[++tp]=x;
	}
	for(auto x:d)dis[x]=D{1000000000,1000000000,0,x};
	for(int i=1;i<=k;i++)q.push(dis[s[i]]=D{0,0,i,s[i]});
	while(!q.empty()){
		int x=q.top().id,dist=q.top().dis,c=q.top().col;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(auto i:G[x]){
			int y=i.fi,di=dist+i.se;
			D res=D{(di+v[c]-1)/v[c],di,c,y};
			if(dis[y]<res){
				dis[y]=res;
				q.push(res);
			}
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",dis[a[i]].col);puts("");
	for(auto x:d)G[x].clear(),vis[x]=0;
	d.clear();
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);
	}
	dfs(1,0),Q=read();
	while(Q--)work();
	return 0;
}