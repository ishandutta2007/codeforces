#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],deg[N],vis[N],leaf[N],cnt[N];
int n,x,y,num,tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	leaf[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&deg[e[i].to]<=2)
			dfs(e[i].to,x);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		deg[x]++; deg[y]++;
	}
	for (int i=1;i<=n;i++)
		if (deg[i]==1) dfs(i,0);
	for (int i=1;i<=n;i++)
		for (int j=head[i];j;j=e[j].next)
			if (leaf[e[j].to]) cnt[i]++;
	for (int i=1;i<=n;i++){
		if (leaf[i]) continue;
		num=0;
		for (int j=head[i];j;j=e[j].next)
			if (!leaf[e[j].to]&&deg[e[j].to]-min(cnt[e[j].to],2)>=2)
				num++;
		if (num>2) return puts("No"),0;
	}
	puts("Yes");
}