#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],q,x,y,i,j,f1[20][N],dep[N],f2[20][N],dep2[N],ans[N],aa[N];
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int dt=dep[y]-dep[x],i;for(i=0;1<<i<=dt;++i)if(dt>>i&1)y=f1[i][y];if(x==y)return x;
	for(i=19;i>=0;--i)if(f1[i][x]!=f1[i][y])x=f1[i][x],y=f1[i][y];return f1[0][x];
}
vector<int>e[N];
int dfn[N],id[N],ri[N],dcnt;
void dfs(int x){dfn[id[x]=++dcnt]=x;for(int y:e[x])dfs(y);ri[x]=dcnt;}
void upd(int&a,int b){if(dep[a]>dep[b])a=b;}
int bi[N];
void add(int x){for(;x<=n;x+=x&-x)++bi[x];}
int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
struct que{int l,r,k,i;};
vector<que>qu[N];
vector<int>path[N];
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;++i)scanf("%d",f1[0]+i),e[f1[0][i]].push_back(i),dep[i]=dep[f1[0][i]]+1;
	for(i=1;i<20;++i)for(j=1;j<=n;++j)f1[i][j]=f1[i-1][f1[i-1][j]];
	dfs(1);
	scanf("%d",&m);
	for(i=1;i<=n;++i)f2[0][i]=i;
	for(i=1;i<=m;++i){
		scanf("%d%d",a+i,b+i);if(id[a[i]]>id[b[i]])swap(a[i],b[i]);path[id[a[i]]].push_back(id[b[i]]);
		x=lca(a[i],b[i]);upd(f2[0][a[i]],x);upd(f2[0][b[i]],x);
	}
	for(i=n;i>1;--i)upd(f2[0][f1[0][i]],f2[0][i]);
	for(i=1;i<20;++i)for(j=1;j<=n;++j)f2[i][j]=f2[i-1][f2[i-1][j]];
	for(i=2;i<=n;++i)dep2[i]=dep2[f2[0][i]]+1;
	scanf("%d",&q);
	for(i=1;i<=q;++i){
		scanf("%d%d",&x,&y);if(id[x]>id[y])swap(x,y);
		if(id[x]<=id[y] && id[y]<=ri[x]){
			int od=dep2[y];
			for(j=19;j>=0;--j)if(dep[f2[j][y]]>dep[x])y=f2[j][y];
			ans[i]=dep[f2[0][y]]<=dep[x]?od-dep2[y]+1:-1;aa[i]=-1;
		}else{
			int l=lca(x,y),odx=dep2[x],ody=dep2[y];
			for(j=19;j>=0;--j){
				if(dep[f2[j][x]]>dep[l])x=f2[j][x];
				if(dep[f2[j][y]]>dep[l])y=f2[j][y];
			}
			if(dep[f2[0][x]]>dep[l] || dep[f2[0][y]]>dep[l]){ans[i]=-1;continue;}
			ans[i]=odx-dep2[x]+ody-dep2[y];
			qu[id[x]-1].push_back((que){id[y],ri[y],-1,i});
			qu[ri[x]].push_back((que){id[y],ri[y],1,i});
		}
	}
	for(i=1;i<=n;++i){
		for(int x:path[i])add(x);
		for(auto u:qu[i])aa[u.i]+=u.k*(ask(u.r)-ask(u.l-1));
	}
	for(i=1;i<=q;++i)if(aa[i]!=-1 && ans[i]!=-1)ans[i]+=aa[i]==0?2:1;
	for(i=1;i<=q;++i)printf("%d\n",ans[i]);
}