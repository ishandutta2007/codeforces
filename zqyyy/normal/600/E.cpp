#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
struct Segment_Tree{
	ll ans[N<<5];
	int tot,rt[N<<5],lc[N<<5],rc[N<<5],sum[N<<5];
	#define ls lc[p]
	#define rs rc[p]
	inline void upd(int p){
		if(sum[ls]>sum[rs])ans[p]=ans[ls],sum[p]=sum[ls];
		else if(sum[ls]<sum[rs])ans[p]=ans[rs],sum[p]=sum[rs];
		else ans[p]=ans[ls]+ans[rs],sum[p]=sum[ls];
	}
	void modify(int &p,int l,int r,int x,int y){
		if(!p)p=++tot;
		if(l==r){sum[p]+=y,ans[p]=l;return;}
		int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y);
		else modify(rs,mid+1,r,x,y);
		upd(p);
	}
	int merge(int l,int r,int x,int y){
		if(!x || !y)return x?x:y;
		if(l==r){sum[x]+=sum[y],ans[x]=l;return x;}
		int mid=(l+r)>>1;
		lc[x]=merge(l,mid,lc[x],lc[y]),rc[x]=merge(mid+1,r,rc[x],rc[y]);
		upd(x);return x;
	}
}T;
int n,c[N];
vector<int>G[N];
void dfs(int x,int fa){
	T.rt[x]=++T.tot;
	for(auto y:G[x])
		if(y^fa)dfs(y,x),T.merge(1,n,T.rt[x],T.rt[y]);
	T.modify(T.rt[x],1,n,c[x],1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);	
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",T.ans[T.rt[i]]);
	return 0;
}