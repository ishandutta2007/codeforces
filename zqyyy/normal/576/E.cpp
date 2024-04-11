#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=5e5+7;
struct edge{int x,y;}e[N],q[N];
struct node{int c,x,y;};
int tp;
node stk[N<<1];
struct DSU{
#define M (N<<1)
	int pa[M],sz[M];
	inline void init(int n){
		iota(pa+1,pa+n+1,1),fill(sz+1,sz+n+1,1);
	}
	int find(int x){return pa[x]^x?find(pa[x]):x;}
#undef M
}d[51];
inline void unin(int c,int x,int y){
	x=d[c].find(x),y=d[c].find(y);
	if(x==y)return;
	if(d[c].sz[x]>d[c].sz[y])swap(x,y);
	stk[++tp]={c,x,y},d[c].pa[x]=y,d[c].sz[y]+=d[c].sz[x];
}
inline void undo(){
	int c=stk[tp].c,x=stk[tp].x,y=stk[tp--].y;
	d[c].pa[x]=x,d[c].sz[y]-=d[c].sz[x];
}
int n,m,K,Q,nxt[N],c[N];
namespace sgt{
	vector<int>vec[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	void modify(int p,int l,int r,int x,int y,int i){
		if(x<=l && r<=y)return vec[p].push_back(i);
		int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,i);
		if(y>mid)modify(rs,mid+1,r,x,y,i);
	}
	void dfs(int p,int l,int r){
		int lst=tp;
		for(int i:vec[p])
			if(c[i])unin(c[i],e[i].x+n,e[i].y),unin(c[i],e[i].x,e[i].y+n);
		if(l==r){
			int i=q[l].y,j=q[l].x;
			bool o=d[i].find(e[j].x)!=d[i].find(e[j].y);
			puts(o?"YES":"NO");
			if(o)::c[j]=i;
		}else{
			int mid=(l+r)>>1;
			dfs(ls,l,mid),dfs(rs,mid+1,r);
		}
		for(int i=1;i<=K;i++)
			while(tp>lst)undo();
	}
#undef ls
#undef rs
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),K=read(),Q=read();
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),nxt[i]=Q+1;
	for(int i=1;i<=Q;i++)q[i].x=read(),q[i].y=read();
	for(int i=Q;i;i--){
		int x=q[i].x;
		if(i<nxt[x]-1)sgt::modify(1,1,Q,i+1,nxt[x]-1,x);
		nxt[x]=i;
	}
	for(int i=1;i<=K;i++)d[i].init(n<<1);
	sgt::dfs(1,1,Q);
	return 0;
}