#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,vis[maxn],cas;
vector<int>G[maxn],my,O;
int get(){
	int x;
	scanf("%d",&x);
	return x;
}
int dfs(int u,int f,int t){
	if(u==t)return 1;
	int flg=0;
	for(auto v:G[u])if(v!=f)
		flg|=dfs(v,u,t);
	if(flg==1&&vis[u]==cas){
		printf("A %d\n",u),fflush(stdout);
		int z=get();
		for(auto c:O)if(c==z){
			printf("C %d\n",u),fflush(stdout);
			throw 1;
		}
		return 2;
	}
	return flg;
}
int main(){
	scanf("%d",&T);
	while(T--){
		++cas;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)G[i].clear();
		for(int i=2,u,v;i<=n;++i){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		my.clear(),O.clear();
		int k,y;
		scanf("%d",&k);
		while(k--)scanf("%d",&y),my.push_back(y),vis[y]=cas;
		scanf("%d",&k);
		while(k--)scanf("%d",&y),O.push_back(y);
		printf("B %d\n",O[0]),fflush(stdout);
		int z=get();
		try{
			if(vis[z]==cas){
				printf("C %d\n",z),fflush(stdout);
				throw 1;
			}
			dfs(my[0],0,z);	
		} catch(int z){
			continue;
		}
		puts("C -1"),fflush(stdout);
	}
}