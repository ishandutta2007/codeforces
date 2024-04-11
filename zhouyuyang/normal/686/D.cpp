#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define N 300005
using namespace std;
struct data{int to,next;}e[N];
int fa[N],son[N],ans[N],head[N];
int n,m,x,tot;
inline void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void dfs(int x){
	son[x]=1;
	ans[x]=x;
	int maxn=0;
	for (int i=head[x];i;i=e[i].next){
		dfs(e[i].to);
		son[x]+=son[e[i].to];
		if (son[e[i].to]>son[maxn]) maxn=e[i].to;
	}
	if (son[x]/2<son[maxn]){
		int now=ans[maxn];
		while (2*son[now]<son[x]) now=fa[now];
		ans[x]=now;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	dfs(1);
	while (m--){
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
}