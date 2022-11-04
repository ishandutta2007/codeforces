#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,k,res,cnt,x,y;
int a[N],fl[N],tg[N],sz[N],dp[N];
vector<int> g[N];
void init(int v){
	res=cnt=0;
	for (int i=1;i<=n;i++)
		cnt+=(fl[i]=(a[i]>=v));
	memset(tg,0,sizeof(tg));
}
void dfs1(int x,int fa){
	sz[x]=1;
	for (int i=0;i<g[x].size();i++)
		if (g[x][i]!=fa)
			dfs1(g[x][i],x),sz[x]+=sz[g[x][i]];
}
void dfs2(int x,int fa){
	if (res>=k) return;
	int all=0,mx1=0,mx2=0;
	for (int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if (to==fa) continue;
		dfs2(to,x);
		tg[x]+=tg[to];
		if (dp[to]==sz[to])
			all+=dp[to];
		else if (dp[to]>mx1)
			mx2=mx1,mx1=dp[to];
		else if (dp[to]>mx2)
			mx2=dp[to];
	}
	if (!fl[x]) dp[x]=0;
	else{
		dp[x]=all+mx1+1;
		tg[x]++;
	}
	if (n-sz[x]==cnt-tg[x])
		all+=n-sz[x];
	if (fl[x])
		res=max(res,all+mx1+mx2+1);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int l=1,r=1000000,ans;
	dfs1(1,0);
	while (l<=r){
		int mid=(l+r)/2;
		init(mid);
		dfs2(1,0);
		if (res>=k)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}