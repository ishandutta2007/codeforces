#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005;
struct Gragh{
	int cnt,y[N*2],nxt[N*2],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,u,v;
int size[N],ved[N];
LL ans;
void dfs(int x,int pre){
	size[x]=1;
	if (x==v)
		ved[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			dfs(g.y[i],x);
			if (ved[g.y[i]])
				ved[x]=1;
			size[x]+=size[g.y[i]];
		}
}
int main(){
	scanf("%d%d%d",&n,&u,&v);
	ans=1LL*n*(n-1);
	g.clear();
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g.add(x,y),g.add(y,x);
	}
	dfs(u,0);
	int v1=1,v2=size[v];
	for (int i=g.fst[u];i;i=g.nxt[i])
		if (!ved[g.y[i]])
			v1+=size[g.y[i]];
	ans-=1LL*v1*v2;
	printf("%I64d",ans);
	return 0;
}