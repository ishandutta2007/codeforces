#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define N [101000]
using namespace std;

int n,m,x,y,rt,zz,id,dep N,fa N,pre N;
vector<pii>G N;
ll ans N,c N,d,e;

void dfs(int x,int fff){
	dep[x]=dep[fa[x]=fff]+1;
	for (auto y:G[x]) if (y.fi-fff){
		if (dep[y.fi]){
			if (!(dep[x]-dep[y.fi]&1)&&!zz)
				rt=y.fi, zz=x, id=y.se;
		}else{
			pre[y.fi]=y.se; dfs(y.fi,x);
		}
	}
	c[fff]-=ans[pre[x]]=e=c[x];
}


int main(){
	cin.tie(0); cin>>n>>m;
	for (int i=1;i<=n;++i) cin>>c[i];
	for (int i=1;i<=m;++i){
		cin>>x>>y;
		G[x].push_back({y,i}), G[y].push_back({x,i});
	}
	dfs(1,0);
	if (rt){
		if (e&1) return 0*puts("NO");
		for (int t=rt;t-1;t=fa[t]) ans[pre[t]]+=dep[t]&1? -e: e; 
		ans[id]+=d=(dep[rt]&1? e: -e)/2;
		for (int fl=1;zz-rt;zz=fa[zz]) ans[pre[zz]]+=(fl=-fl)*d;
	}else if (e) return 0*puts("NO");
	puts("YES");
	for (int i=1;i<=m;++i) printf("%I64d\n",ans[i]);
}