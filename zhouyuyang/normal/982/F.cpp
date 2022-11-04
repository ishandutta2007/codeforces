#include<bits/stdc++.h>
const int N=100005;
using namespace std;

int ban[N],vis[N];
vector<int> e[N];
int tried[N],n,m;

bool dfs(int x){
	if (ban[x]) return 0;
	vis[x]=1;
	for (int i=0;i<e[x].size();i++){
		int to=e[x][i];
		if (vis[to]==0){
			if (dfs(to)) return 1;
		}
		else if (vis[to]==1){
			for (int i=1;i<=n;i++)
				if (vis[i]!=1) tried[i]=1;
			return 1;
		}
	}
	vis[x]=2;
	return 0;
}

int a[N];

double SZB(){
	return 1.0*clock()/CLOCKS_PER_SEC;
}

bool check(){
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
			if (dfs(i)) return 0;
	return 1;
}
	
int main(){
    srand(time(NULL));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	for (int i=1;i<=n;i++)
		a[i]=i;
	random_shuffle(a+1,a+n+1);
	for (int i=1;SZB()<0.95&&i<=n;i++){
		if (tried[a[i]]) continue;
		ban[a[i]]=1;
		if (check()){
			printf("%d",a[i]);
			return 0;
		}
		ban[a[i]]=0;
	}
	puts("-1");
}