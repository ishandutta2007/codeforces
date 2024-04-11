#include<bits/stdc++.h>
using namespace std;

vector<int>v[303000],G[303000];
int n,m,ans[303000],mx,used[303000];

void dfs(int x,int fff){
	for (int y:v[x]) if (ans[y])
		used[ans[y]]=1;
	int pos=1;
	for (int y:v[x]) if (!ans[y]){
		while (used[pos]) pos++;
		mx=max(pos,mx);
		used[ans[y]=pos]=1;
	}
	for (int y:v[x]) used[ans[y]]=0;
	for (int y:G[x]) if (y!=fff)
		dfs(y,x);
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=n;i++)
		for (scanf("%d",&y);y--;v[i].push_back(x)) scanf("%d",&x);
	for (int i=1;i<n;i++)
		scanf("%d%d",&x,&y), G[x].push_back(y),G[y].push_back(x);
	dfs(rand()%n+1,0);
	printf("%d\n",max(mx,1));
	for (int i=1;i<=m;i++) printf("%d ",max(ans[i],1));
}