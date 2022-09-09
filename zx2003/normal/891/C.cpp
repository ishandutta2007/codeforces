#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=500005;
int u[N],v[N],w[N],n,m,i,f[N],g[N],T,qq,a[N],k,x,y,j;
vector<pair<int,int> >q[N],e[N];
bool wa[N];
inline int gfa(int x){return f[x]==x?x:f[x]=gfa(f[x]);}
inline int gfa2(int x){
	return (a[x]<T?a[x]=T,g[x]=f[x]:0),(g[x]==x?x:g[x]=gfa2(g[x]));
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",u+i,v+i,w+i),e[w[i]].push_back(make_pair(u[i],v[i]));
	for(i=1;i<=n;++i)f[i]=i;
	for(scanf("%d",&qq),i=1;i<=qq;++i){
		scanf("%d",&k);
		while(k--)scanf("%d",&x),q[w[x]].push_back(make_pair(i,x));
	}
	for(i=1;i<500001;++i){
		sort(q[i].begin(),q[i].end());
		for(j=0;j<int(q[i].size());++j){
			T+=!j || q[i][j-1].first<q[i][j].first;
			x=gfa2(u[q[i][j].second]),y=gfa2(v[q[i][j].second]);
			if(x==y)wa[q[i][j].first]=1;
				else g[x]=y;
		}
		for(j=0;j<int(e[i].size());++j)f[gfa(e[i][j].first)]=gfa(e[i][j].second);
	}
	for(i=1;i<=qq;++i)puts(wa[i]?"NO":"YES");
	return 0;
}