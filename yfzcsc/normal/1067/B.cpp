#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k,tg[maxn],fa[maxn],rm,cas,mx,id,ru,rv; 
vector<int>G[maxn];
void dfs(int u,int f,int d=0){
	if(d>mx)mx=d,id=u;
	for(auto v:G[u])if(v!=f)
		dfs(v,u,d+1);
}
void fnd(int u,int f,int t){
	fa[u]=f;
	if(u==t){
		rm=u;
		for(int i=1;i<=k;++i)rm=fa[rm];
		return ;
	}
	for(auto v:G[u])if(v!=f)
		fnd(v,u,t);
}
void no(){
	puts("No");
	exit(0);
}
int chk(int u,int f){
	if(G[u].size()==1)return 1;
	if(f==0&&G[u].size()<3)no();
	if(f&&G[u].size()-1<3)no();
	int ret=0;
	for(auto v:G[u])if(v!=f){
		int s=chk(v,u);
		if(!ret)ret=s;
		else if(ret!=s)no();
	}
	return ret+1;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	ru=id;
	mx=0,id=0,dfs(ru,0);
	rv=id;
	if(mx!=2*k)return puts("No"),0;
	fnd(ru,0,rv);
	chk(rm,0);
	puts("Yes");
}