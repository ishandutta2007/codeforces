#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],sz[N],mx[N],rt[N];
int ans[N*2][3],sta[N],fa[N];
int n,tot,cnt,top;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	sz[x]=1; mx[x]=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			sz[x]+=sz[e[i].to];
			mx[x]=max(mx[x],sz[e[i].to]);
		}
	if (sz[x]*2>=n&&mx[x]*2<=n) rt[x]=1;
}
void change(int x,int y,int z){
	ans[++cnt][0]=x;
	ans[cnt][1]=y;
	ans[cnt][2]=z;
}
void solve(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x])
			fa[e[i].to]=x,solve(e[i].to);
	sta[++top]=x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	for (int v=1;v<=n;v++){
		if (!rt[v]) continue;
		for (int i=head[v];i;i=e[i].next)
			if (!rt[e[i].to]){
				fa[e[i].to]=v; sta[top=1]=v;
				solve(e[i].to);
				change(v,e[i].to,sta[2]);
				for (int i=2;i<top;i++)
					if (sta[i+1]!=fa[sta[i]])
						change(sta[i],fa[sta[i]],sta[i+1]);
				for (int i=top-3;i>=1;i--)
					change(sta[i],sta[i+1],sta[top-1]);
			}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
}