#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct edge{
	int to,next,id;
}e[N*2];
int head[N],tot;
int ans[N],v[N],vis[N];
int n,s,m;
void add(int x,int y,int id){
	e[++tot]=(edge){y,head[x],id};
	head[x]=tot;
}
void dfs(int x){
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			dfs(e[i].to);
			ans[abs(e[i].id)]=v[e[i].to];
			v[x]+=v[e[i].to];
			if (e[i].id<0)
				ans[abs(e[i].id)]*=-1;
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i]),s+=v[i];
	if (s) return puts("Impossible"),0;
	puts("Possible");
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,i); add(y,x,-i);
	}
	dfs(1);
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}