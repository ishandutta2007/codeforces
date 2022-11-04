#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
struct edge{int to,next;}e[N*2];
int f[N],g[N],head[N],vis[N];
int sz[N],fa[N],n,m,Q,tot;
map<pair<int,int>,double> mp;
vector<int> W[N];
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int dfs1(int x){
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			dfs1(e[i].to);
			g[x]=max(g[x],g[e[i].to]+1);
		}
}
int dfs2(int x,int fa,int v){
	int mx1=-233,mx2=-233;
	f[x]=max(v,g[x]);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			if (g[e[i].to]>mx1)
				mx2=mx1,mx1=g[e[i].to];
			else if (g[e[i].to]>mx2)
				mx2=g[e[i].to];
		}
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			int tmp=-233;
			if (g[e[i].to]==mx1)
				tmp=mx2;
			else tmp=mx1;
			dfs2(e[i].to,x,max(tmp+2,v+1));
		}
}
void work(int x){
	dfs1(x);
	dfs2(x,0,0);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		fa[get(x)]=get(y);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) work(i);
	for (int i=1;i<=n;i++){
		int x=get(i),p=f[i];
		if (W[x].size()<=p) W[x].resize(p+1);
		W[x][p]++; sz[x]++;
	}
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=get(x); y=get(y);
		if (x==y){
			puts("-1");
			continue;
		}
		if (W[x].size()>W[y].size()) swap(x,y);
		if (W[x].size()==W[y].size()&&x>y) swap(x,y);
		if (mp.find(make_pair(x,y))!=mp.end()){
			printf("%.15lf\n",mp[make_pair(x,y)]);
			continue;
		}
		ll ans=1ll*(W[y].size()-1)*sz[x]*sz[y];
		ll G0=0,G1=0;
		for (int i=0;i<W[x].size();i++){
			G1+=W[y][W[y].size()-1-i];
			G0+=G1;
			ans+=G0*W[x][i];
		}
		double Ans=1.0*ans/sz[x]/sz[y];
		printf("%.15lf\n",mp[make_pair(x,y)]=Ans);
	}
}