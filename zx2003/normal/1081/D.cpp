#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,x,y,z,i,g[N],sz[N];
vector<int>e[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;++i)g[i]=i;for(i=1;i<=k;++i)scanf("%d",&x),sz[x]=1;
	for(i=1;i<=m;++i)scanf("%d%d%d",&x,&y,&z),e[i]={z,x,y};
	sort(e+1,e+m+1);
	for(i=1;i<=m;++i){
		z=e[i][0];x=gfa(e[i][1]);y=gfa(e[i][2]);if(x==y)continue;
		g[x]=y;sz[y]+=sz[x];if(sz[y]==k)break;
	}
	for(i=1;i<=k;++i)printf("%d%c",z,i==k?'\n':' ');
}