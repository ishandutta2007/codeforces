#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,a[N],i,st[N],w,p[N],sz[N];
vector<int>e[N];
void dfs(int x,int i){
	p[x]=i;
	int d=i-1;
	for(int y:e[x])dfs(y,d),d-=sz[y];
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i),a[i]==-1?a[i]=i+1:0;
		st[w=1]=n+1;
		for(i=n;i;--i){
			for(;w>1 && st[w]<a[i];--w);
			if(st[w]!=a[i])break;st[++w]=i;
		}
		if(i){puts("-1");continue;}
		for(i=1;i<=n+1;++i)e[i].clear(),sz[i]=1;
		for(i=1;i<=n;++i)e[a[i]].push_back(i),sz[a[i]]+=sz[i];
		dfs(n+1,n+1);
		for(i=1;i<=n;++i)printf("%d%c",p[i],i==n?'\n':' ');
	}
	return 0;
}