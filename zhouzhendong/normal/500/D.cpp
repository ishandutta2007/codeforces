#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005,M=200005;
int n,q;
int a[N],b[N],c[N];
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
int fa[N],size[N];
void dfs(int x,int pre){
	size[x]=1,fa[x]=pre;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			dfs(g.y[i],x);
			size[x]+=size[g.y[i]];
		}
}
LL calc(int x,LL d){
	return d*size[x]*(n-1)-d*size[x]*(size[x]-1);
}
int main(){
	scanf("%d",&n);
	g.clear();
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		g.add(a[i],b[i]);
		g.add(b[i],a[i]);
	}
	dfs(1,0);
	LL tot=0;
	for (int i=1;i<n;i++){
		if (fa[a[i]]==b[i])
			swap(a[i],b[i]);
		tot+=calc(b[i],c[i]);
	}
	scanf("%d",&q);
	LL val=1LL*n*(n-1)*(n-2)/6;
	while (q--){
		int i,v;
		scanf("%d%d",&i,&v);
		tot+=calc(b[i],v-c[i]);
		c[i]=v;
		printf("%.10lf\n",1.0*tot*(n-2)/val);
	}
	return 0;
}