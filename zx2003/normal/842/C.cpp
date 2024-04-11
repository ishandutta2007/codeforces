#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200010;
vector<int> d[N];
int n,u,v,i,h[N],a[N],f[N],xb,g[N],s[N],dep[N];
struct edge{
	int to,next;
}e[N<<1];
inline void addedge(int u,int v){
	e[++xb]=(edge){v,h[u]};
	h[u]=xb;
	e[++xb]=(edge){u,h[v]};
	h[v]=xb;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	g[x]=gcd(g[fa],a[x]);
	int i=d[x].size()-1;
	for(;i>=0;--i)if(s[d[x][i]]>=dep[x]-2)break;
	f[x]=max(d[x][i],g[fa]);
	for(i=0;i<(int)d[x].size();++i)++s[d[x][i]];
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs(e[i].to,x);
	for(i=0;i<(int)d[x].size();++i)--s[d[x][i]];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		for(u=1;u*u<a[i];++u)if(a[i]%u==0)d[i].push_back(u);
		v=d[i].size();
		if(u*u==a[i])d[i].push_back(u);
		for(u=v-1;u>=0;--u)d[i].push_back(a[i]/d[i][u]);
	}
	for(i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	g[1]=a[1];
	dep[1]=1;
	for(i=0;i<(int)d[1].size();++i)++s[d[1][i]];
	for(i=h[1];i;i=e[i].next)dfs(e[i].to,1);
	for(i=1;i<=n;++i)printf("%d ",max(f[i],g[i]));
	return 0;
}