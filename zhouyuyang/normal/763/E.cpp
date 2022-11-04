#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct edge{int to,next;}e[N*10];
int head[N],t[N],dfn[N],vis[N];
int tot,n,T;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void upd(int x){
	for(;x<=n;x+=x&(-x)) t[x]++;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
void dfs(int x){
	if (dfn[x]) return;
	dfn[x]=++T;
	for (int i=head[x];i;i=e[i].next)
		dfs(e[i].to);
}
int check(int x,int a,int b){
	if (vis[x]) return 0;
	int ans=1;
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to<a||e[i].to>b) continue;
		if (dfn[e[i].to]<dfn[x]) ans=0;
	}
	return ans;
}
int main(){
	int k,m,q;
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]){
			dfs(i);
			upd(i);
			vis[i]=1;
		}
	scanf("%d",&q);
	while (q--){
		int x,y,ans=0;
		scanf("%d%d",&x,&y);
		for (int i=x;i<=min(y,x+k-1);i++) ans+=check(i,x,y);
		for (int i=max(x+k,y-k+1);i<=y;i++) ans+=check(i,x,y);
		printf("%d\n",ask(y)-ask(x-1)+ans);
	}
}