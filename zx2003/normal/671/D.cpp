#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
struct node{int l,r,d,v,y,tg;inline void add(int x){v+=x;tg+=x;}}t[N];
inline void pushdown(int x){if(t[x].tg){if(t[x].l)t[t[x].l].add(t[x].tg);if(t[x].r)t[t[x].r].add(t[x].tg);t[x].tg=0;}}
int merge(int x,int y){
	if(!x || !y)return x|y;
	if(t[x].v>t[y].v)swap(x,y);
	pushdown(x);t[x].r=merge(t[x].r,y);
	if(t[t[x].l].d<t[t[x].r].d)swap(t[x].l,t[x].r);
	t[x].d=t[t[x].r].d+1;return x;
}
int n,m,x,y,c,i,rt[N],dep[N];
long long ans;
vector<int>e[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		for(;rt[y] && dep[t[rt[y]].y]>=dep[y];rt[y]=merge(t[rt[y]].l,t[rt[y]].r));
		if(!rt[y]){puts("-1");exit(0);}
		ans+=c=t[rt[y]].v;t[rt[y]].add(-c);rt[x]=merge(rt[x],rt[y]);
	}
}
int main(){
	scanf("%d%d",&n,&m);for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(i=1;i<=m;++i)scanf("%d%d%d",&x,&t[i].y,&t[i].v),rt[x]=merge(rt[x],i);
	dfs(1,0);printf("%lld\n",ans);
	return 0;
}