#include<bits/stdc++.h>
#define db double
#define has (x*10000000ll+y)
using namespace std;

vector<int>G[101000],val[101000],p[101000];
vector<long long>sum[101000];
int n,m,T,bel[101000],f[101000],g[101000],now;

void dfs(int x,int fff){
	bel[x]=now;
	for (auto y:G[x]) if (y!=fff){
		dfs(y,x);
		f[x]=max(f[x],f[y]+1);
	}
}

void ddd(int x,int fff,int els){
	g[now]=max(g[now],f[x]+els);
	p[now].push_back(x);
	val[now].push_back(f[x]=max(f[x],els));
	int se=els,cnt=0;
	for (auto y:G[x]) if (y!=fff){
		if (f[x]==f[y]+1) cnt++;
		else se=max(se,f[y]+1);
	}
	for (auto y:G[x]) if (y!=fff){
		ddd(y,x,f[x]==f[y]+1&&cnt==1? se+1: max(f[x],se)+1);
	}
}

void doit(){
	dfs(now,-1);
	ddd(now,-1,0);
	sort(val[now].begin(),val[now].end());
	long long s=0;
	for (auto x:val[now]) sum[now].push_back(s),s+=x;
	sum[now].push_back(s);
}

unordered_map<long long,db>mp;
db que(int x,int y){
	if (p[x].size()>p[y].size()) swap(x,y);
	if (mp.count(has)) return mp[has];
	db res=0.0; int up=max(g[x],g[y]),d,q,sz=p[y].size();
	for (auto u:p[x]){
		d=up-f[u]-1;
		q=lower_bound(val[y].begin(),val[y].end(),d)-val[y].begin();
		res+=(db)q*up+sum[y][sz]-sum[y][q]+(db)(sz-q)*(f[u]+1);
	}
	res=res/p[x].size()/sz;
	return mp[has]=res;
}

int main(){
	scanf("%d%d%d",&n,&m,&T);
	int x,y;
	for (;m--;) scanf("%d%d",&x,&y), G[x].push_back(y), G[y].push_back(x);
	for (now=1;now<=n;now++) if (!bel[now]) doit();
	for (;T--;) scanf("%d%d",&x,&y), bel[x]==bel[y]? puts("-1"): printf("%.10lf\n",que(bel[x],bel[y]));
}