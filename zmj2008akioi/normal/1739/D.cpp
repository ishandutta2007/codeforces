#include <cstdio>
#include <vector>
const int N=2e5+10;
int T,n,k,c,f[N],g[N],p[N];std::vector<int> son[N];
template<typename T>T md(T x,T y){return (x+y)/2;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
void dfs(int u){
	f[u]=g[u]=0;
	for(int i:son[u])dfs(i),cmax(f[u],f[i]),g[u]+=g[i];
	if(++f[u]>=c)f[u]=0,g[u]+=p[u]!=1;
}
bool check(int d){c=d,dfs(1);return g[1]<=k;}
int bsc(){
	int mid,l=1,r=n-1;
	while(l!=r){
		mid=md(l,r);
		if(check(mid))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	p[1]=1,scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)son[i].clear();
		for(int i=2;i<=n;++i)scanf("%d",&p[i]),son[p[i]].push_back(i);
		printf("%d\n",bsc());
	}
	return 0;
}