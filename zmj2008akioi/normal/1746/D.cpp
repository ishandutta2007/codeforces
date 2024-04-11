#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long LL;
const int N=2e5+10;
int T,n,k,g[N],dep[N],w[N][2];LL f[N][2];std::vector<int> son[N];
void dfs(int u){
	int s=son[u].size();dep[u]+=g[u];
	if(!s){
	f[u][0]=(LL)w[u][0]*dep[u],f[u][1]=(LL)w[u][1]*dep[u];return;}
	int a=w[u][0]/s,b=(w[u][1]-1)/s+1;
	std::vector<LL> ext;f[u][0]=f[u][1]=0;
	for(int i:son[u]){
		w[i][0]=a,w[i][1]=b,dep[i]=dep[u],dfs(i),f[u][0]+=f[i][0];
		if(a!=b)ext.push_back(f[i][1]-f[i][0]);
	}
	f[u][1]=f[u][0];
	if(a==b)return;
	std::sort(ext.begin(),ext.end());
	std::reverse(ext.begin(),ext.end());
	for(int i=0,c=w[u][0]-a*s;i<c;++i)f[u][0]+=ext[i];
	for(int i=0,c=w[u][1]-a*s;i<c;++i)f[u][1]+=ext[i];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)son[i].clear();
		for(int p,i=2;i<=n;++i)scanf("%d",&p),son[p].push_back(i);
		for(int i=1;i<=n;++i)scanf("%d",&g[i]);
		w[1][0]=w[1][1]=k,dep[1]=0,dfs(1),printf("%lld\n",f[1][0]);
	}
	return 0;
}