#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,m,q,o,u,v,d[N],i,f[N],h[N],xb,dd,sz[N],j,bbb,w,s,len[N];
double ans;
bool bb[N];
struct edge{
	int to,next;
}e[N<<1];
struct node{
	int ss,s;double vs;
};
vector<node> a[N];
map<pair<int,int>,double> mm;
int gfa(int x){return x==f[x]?x:f[x]=gfa(f[x]);}
void dfs1(int x,int fa,int dep){
	if(dep>dd)dd=dep,u=x;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs1(e[i].to,x,dep+1);
}
void dfs2(int x,int fa){
	if(d[x]>dd)dd=d[x],v=x;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)d[e[i].to]=d[x]+1,dfs2(e[i].to,x);
}
void dfs3(int x,int fa,int dep){
	if(dep>d[x])d[x]=dep;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs3(e[i].to,x,dep+1);
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=1;i<=n;++i)f[i]=i;
	for(i=1;i<=m;++i){
		scanf("%lld%lld",&u,&v);
		e[++xb]=(edge){v,h[u]},h[u]=xb;
		e[++xb]=(edge){u,h[v]},h[v]=xb;f[gfa(u)]=gfa(v);
	}
	for(i=1;i<=n;++i)++sz[gfa(i)];
	for(i=1;i<=n;++i)
		if(gfa(i)==i){
			a[i].resize(sz[i]);bb[i]=1;
			dd=u=-1;dfs1(i,0,0);
			dd=v=-1;dfs2(u,0);
			dfs3(v,0,0);len[i]=dd;
			a[gfa(i)].resize(dd+1);
		}
	for(i=1;i<=n;++i){
		++a[gfa(i)][d[i]].ss;
		if(d[i]>(int)a[gfa(i)].size()-1)return 1;
	}
	for(i=1,bbb=sqrt(n);i<=n;++i)
		if(bb[i])
			for(j=1,a[i][0].s=a[i][0].ss;j<=len[i];++j){
				a[i][j].vs=a[i][j-1].vs+1ll*j*a[i][j].ss;
				a[i][j].s=a[i][j-1].s+a[i][j].ss;
			}
	while(q--){
		scanf("%lld%lld",&u,&v);u=gfa(u);v=gfa(v);
		if(u==v){puts("-1");continue;}
		if(sz[u]>sz[v] || (sz[u]==sz[v] && u>v))i=u,u=v,v=i;
		if(sz[u]>=bbb && sz[v]>=bbb && mm.count(make_pair(u,v))){
			printf("%.8f\n",mm[make_pair(u,v)]/sz[u]/sz[v]);
			continue;
		}
		ans=a[u].back().vs*sz[v];
		ans+=a[v].back().vs*sz[u];
		ans+=1ll*sz[u]*sz[v];
		double s=0;
		for(i=0,w=max(len[u],len[v]);i<=len[u];++i)
			if(0<=w-i-1 && w-i-1<=len[v]){
				ans-=a[v][w-i-1].vs*a[u][i].ss+1ll*a[v][w-i-1].s*a[u][i].ss;
				ans-=1ll*a[v][w-i-1].s*a[u][i].ss*i;
				s+=1ll*a[u][i].ss*a[v][w-i-1].s;
			}
		ans+=s*w;
		if(sz[u]>=bbb && sz[v]>=bbb)mm[make_pair(u,v)]=ans;
		printf("%.8f\n",ans/sz[u]/sz[v]);
	}
	return 0;
}