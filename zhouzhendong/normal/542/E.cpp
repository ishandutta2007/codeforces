#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=1005;
int n,m;
vector <int> e[N],s;
int c[N],vis[N];
int dfs(int x,int d){
	if (~c[x])
		return c[x]==d;
	s.push_back(x);
	c[x]=d;
	for (auto y : e[x])
		if (!dfs(y,d^1))
			return 0;
	return 1;
}
int q[N],dis[N],head,tail;
int dfs2(int s){
	memset(vis,0,sizeof vis);
	head=tail=0;
	q[++tail]=s,dis[s]=0,vis[s]=1;
	while (head<tail){
		int x=q[++head];
		for (auto y : e[x])
			if (!vis[y])
				vis[y]=1,dis[y]=dis[x]+1,q[++tail]=y;
	}
	return dis[q[tail]];
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(c,-1,sizeof c);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (!~c[i]){
			s.clear();
			if (!dfs(i,0))
				return puts("-1"),0;
			int now=0;
			for (auto S : s)
				now=max(now,dfs2(S));
			ans+=now;
		}
	printf("%d",ans);
	return 0;
}