#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=600005;
int t[N],n,m,p[N],k,vis[N],s[2][N],ans[N*2],u[N],v[N],w[N],tot;
struct str{
	int v,x,f;
};
vector<str> g[N];
void add(int u,int v,int x){
	g[u].push_back({v,x,1});
	g[v].push_back({u,x,2});
}
void dfs(int i){
	vis[i]=1;
	for(;t[i]<g[i].size();++t[i])
		if(!ans[g[i][t[i]].x]){
			ans[g[i][t[i]].x]=g[i][t[i]].f;
			// cout<<g[i][t[i]].x<<endl;
			dfs(g[i][t[i]].v);
		}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		s[w[i]-1][u[i]]^=1;
		s[w[i]-1][v[i]]^=1;
	}
	int ss=0;
	tot=m;
	for(int i=1;i<=n;++i){
		if(s[0][i])
			++ss;
		if(s[0][i]^s[1][i]){
			if(s[0][i])
				add(2*n+1,i,++tot);
			else
				add(2*n+1,i+n,++tot);
		}
		else
			if(s[0][i])
				add(i,i+n,++tot);
	}
	for(int i=1;i<=m;++i)
		if(w[i]==1)
			add(u[i],v[i],i);
		else
			add(u[i]+n,v[i]+n,i);
	for(int i=1;i<=2*n+1;++i)
		if(!vis[i])
			dfs(i);
	printf("%d\n",ss);
	for(int i=1;i<=m;++i)
		printf("%d",ans[i]);
}