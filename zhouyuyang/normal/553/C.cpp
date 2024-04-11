#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100100
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],f[N],vis[N],co[N],a[N],b[N];
int n,m,x,y,z,tot,cnt,ans;
void add(int x,int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
}
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
void dfs(int x){
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			co[e[i].to]=co[x]^1;
			dfs(e[i].to);
		}
		else if (!(co[x]^co[e[i].to])){
			puts("0");
			exit(0);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if (z){
			x=get(x),y=get(y);
			if (x^y) f[x]=y;
		}
		else a[++tot]=x,b[tot]=y;
	}
	for (int i=1;i<=tot;i++){
		x=get(a[i]),y=get(b[i]);
		add(x,y); add(y,x);
	}
	ans=500000004;
	for (int i=1;i<=n;i++)
		if (get(i)==i&&!vis[i]){
			dfs(i);
			ans=ans*2%1000000007;
		}
	printf("%d\n",ans);
}