#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N=300005,M=300005;
struct Gragh{
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,m,v[N],vis[N];
int in[N],q[N],head,tail,dp[N][26];
char s[N];
bool dfs_round(int x,int mark){
	if (vis[x])
		return vis[x]==mark&&in[x];
	vis[x]=mark;
	in[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (dfs_round(g.y[i],mark))
			return 1;
	in[x]=0;
	return 0;
}
bool round(){
	memset(vis,0,sizeof vis);
	memset(in,0,sizeof in);
	int mark=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
			if (dfs_round(i,++mark))
				return 1;
	return 0;
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for (int i=1;i<=n;i++)
		v[i]=s[i]-'a';
	g.clear();
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g.add(a,b);
	}
	if (round()){
		puts("-1");
		return 0;
	}
	memset(dp,0,sizeof dp);
	memset(in,0,sizeof in);
	for (int i=1;i<=m;i++)
		in[g.y[i]]++;
	head=tail=0;
	for (int i=1;i<=n;i++)
		if (!in[i])
			q[++tail]=i;
	int ans=0;
	while (head<tail){
		int x=q[++head];
		dp[x][v[x]]++;
		for (int i=0;i<26;i++)
			ans=max(ans,dp[x][i]);
		for (int i=g.fst[x];i;i=g.nxt[i]){
			int y=g.y[i];
			for (int j=0;j<26;j++)
				dp[y][j]=max(dp[y][j],dp[x][j]);
			if (!--in[y])
				q[++tail]=y;
		}
	}
	printf("%d",ans);
	return 0;
}