#include<bits/stdc++.h>
using namespace std;

int n, fa[1001000];
vector<int>G[1001000];

int f[1001000][2][22];

void dfs(int x){
	if (G[x].size()==0){
		f[x][1][0]=x-1;
		for (int i=1;i<=21;++i)
			f[x][1][i]=n;
		return;
	}
	f[x][1][0]=x-1;
	if (x!=1){
		memset(f[x][0],33,sizeof f[x][0]);
		for (auto y:G[x]){
			dfs(y);
			for (int i=1;i<=21;++i){
				f[x][1][i]=max(min(f[x][1][i],f[y][1][i-1]),min(f[x][0][i],f[y][1][i]));
			}
			for (int i=1;i<=21;++i){
				f[x][0][i]=min(f[x][0][i],f[y][1][i-1]);
			}
		}
	}else{
		memset(f[x][0],33,sizeof f[x][0]);
		for (auto y:G[x]){
			dfs(y);
			for (int i=1;i<=21;++i){
				f[x][0][i]=min(f[x][0][i],f[y][1][i]);
			}
			for (int i=1;i<=21;++i){
				f[x][1][i]=f[x][0][i];
			}
		}
	}
}

int main(){
	cin>>n; ++n;
	for (int i=2;i<=n;++i){
		scanf("%d",&fa[i]);
		G[fa[i]].push_back(i);
	}
	dfs(1);
	
	f[1][1][0]=1;
	/*
	for (int i=1;i<=n;++i){
		for (int j=0;j<=10;++j)
			printf(" %d",f[i][1][j]);
		puts("");
	}
	*/
	for (int i=1;i<=21;++i)
		for (int T=f[1][1][i]-f[1][1][i-1];T--;)
			printf("%d ",i);
	puts("");
}