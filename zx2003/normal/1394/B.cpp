#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,i,j,l,eu[N],ev[N],u,v,w,d1[N],d2[N],ans;
vector<int>e[N];
bool b[99][99],bb[99];
void dfs(int d){
	if(d==k+1){++ans;return;}
	for(int i=1,v;i<=d;++i)if(v=i+d*(d-1)/2,!b[v][v]){
		for(j=1;j<v;++j)if(bb[j] && b[v][j])break;
		if(j==v)bb[v]=1,dfs(d+1),bb[v]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)scanf("%d%d%d",&u,&v,&w),eu[w]=u,ev[w]=v,++d1[u];
	for(i=1;i<=m;++i)u=eu[i],v=ev[i],e[v].push_back(++d2[u]+d1[u]*(d1[u]-1)/2);
	for(i=1;i<=n;++i){
		sort(e[i].begin(),e[i].end());
		for(j=0;j+1<e[i].size();++j)if(e[i][j]==e[i][j+1])b[e[i][j]][e[i][j]]=1;
		e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
		for(j=e[i].size()-1;j>=0;--j)for(int k=j-1;k>=0;--k)b[e[i][j]][e[i][k]]=1;
	}
	dfs(1);printf("%d\n",ans);
}