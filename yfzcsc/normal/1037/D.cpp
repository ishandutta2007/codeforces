#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int n,vis[maxn],fa[maxn],a[maxn],b[maxn];
vector<int>G[maxn];
queue<int>Q;
int main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]]=i;
	if(a[1]!=1)return puts("No"),0;
	int pos=1;
	Q.push(a[1]);
	while(Q.size()){
		int u=Q.front();
		Q.pop();
		vis[u]=1;
		if(a[pos++]!=u)return puts("No"),0;
		sort(G[u].begin(),G[u].end(),[](int x,int y){return b[x]<b[y];});
		for(auto v:G[u])if(!vis[v])Q.push(v);
	}
	puts("Yes");
}