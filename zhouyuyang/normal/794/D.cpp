#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],col[N],used[N*2];
int n,m,tot,vis[N];
ll hsh[N],v[N];
ll rnd(){
	ll v=0;
	for (int i=1;i<=4;i++)
		v=(v<<15)+rand();
	return v;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (hsh[e[i].to]==hsh[x])
			col[e[i].to]=col[x];
	for (int i=head[x];i;i=e[i].next){
		if (vis[e[i].to]) continue;
		if (!col[e[i].to])
			for (int j=col[x]-1;j<=col[x]+1;j++)
				if (!used[j]){
					col[e[i].to]=j;
					used[j]=1;
					break;
				}
		dfs(e[i].to);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		hsh[i]=v[i]=rnd();
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		hsh[x]+=v[y]; hsh[y]+=v[x];
	}
	col[1]=300001;
	used[col[1]]=1;
	dfs(1);
	for (int i=1;i<=n;i++)
		if (!col[i]){
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i=1;i<=n;i++)
		printf("%d ",col[i]);
}