#include<bits/stdc++.h>
#define N 505
using namespace std;
int mp[N][N],in[N],deg[N],vis[N];
int n,m;
void dfs(int x){
	vis[x]=1;
	for (int i=1;i<=n;i++)
		if (!vis[i]&&mp[x][i])
			if ((--deg[i])<=0) dfs(i);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=1; in[y]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			deg[j]=in[j],vis[j]=0;
		deg[i]--;
		for (int j=1;j<=n;j++)
			if (deg[j]<=0&&!vis[j]) dfs(j);
		int GG=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]) GG=1;
		if (!GG) return puts("YES"),0;
	}
	puts("NO");
}