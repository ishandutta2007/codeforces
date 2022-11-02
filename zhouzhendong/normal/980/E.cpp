#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
struct gragh{
	int cnt,y[N*2],nxt[N*2],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,lim,depth[N],fa[N],anst[N][21];
int vis[N],tot=0,ans[N];
void dfs(int x,int pre){
	fa[x]=anst[x][0]=pre;
	depth[x]=depth[pre]+1;
	for (int i=1;i<=20;i++)
		anst[x][i]=anst[anst[x][i-1]][i-1];
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre)
			dfs(g.y[i],x);
}
int main(){
	scanf("%d%d",&n,&lim);
	lim=n-lim;
	g.clear();
	for (int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		g.add(a,b),g.add(b,a);
	}
	dfs(n,0);
	memset(vis,0,sizeof vis);
	vis[n]=tot=1;
	vis[0]=1;
	for (int i=n-1;i>=1;i--){
		if (vis[i])
			continue;
		int j=i;
		for (int k=20;k>=0;k--)
			if (!vis[anst[j][k]])
				j=anst[j][k];
		if (tot+depth[i]-depth[j]+1>lim)
			continue;
		tot+=depth[i]-depth[j]+1;
		vis[j]=1;
		for (int k=i;k!=j;k=fa[k])
			vis[k]=1;
	}
	tot=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
			ans[++tot]=i;
	for (int i=1;i<=tot;i++)
		printf("%d ",ans[i]);
	return 0;
}