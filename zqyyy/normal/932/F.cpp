#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
const ll INF=1e18;
struct Lc_Tree{
	struct Line{ll k,b;}a[N];
	int cnt,tot,t[N<<6],ls[N<<6],rs[N<<6];
	inline ll calc(int i,int x){return a[i].k*x+a[i].b;}
	void modify(int &p,int l,int r,int i){
		if(!p){t[p=++tot]=i;return;}
		int mid=(l+r)>>1;
		if(calc(i,mid)<calc(t[p],mid))swap(t[p],i);
		if(calc(i,l)<calc(t[p],l))modify(ls[p],l,mid,i);
		if(calc(i,r)<calc(t[p],r))modify(rs[p],mid+1,r,i);
	}
	ll query(int p,int l,int r,int x){
		if(!t[p])return INF;
		ll res=calc(t[p],x);if(l==r)return res;
		int mid=(l+r)>>1;
		if(x<=mid)return min(res,query(ls[p],l,mid,x));
		else return min(res,query(rs[p],mid+1,r,x));
	}
	ll qry(int rt,int x){return query(rt,-1e5,1e5,x);}
	inline void insert(int &rt,ll k,ll b){
		a[++cnt]={k,b},modify(rt,-1e5,1e5,cnt);
	}
	int merge(int p,int q,int l,int r){
		if(!p || !q)return p|q;
		if(l==r)return calc(t[p],l)<calc(t[q],l)?p:q;
		int mid=(l+r)>>1;
		ls[p]=merge(ls[p],ls[q],l,mid),rs[p]=merge(rs[p],rs[q],mid+1,r);
		return modify(p,l,r,t[q]),p;
	}
}T;
int n,a[N],b[N],rt[N];
vector<int>G[N];
ll f[N];
void dfs(int x,int fa){
	if(fa && (int)G[x].size()==1)
		return T.insert(rt[x],b[x],0);
	for(int y:G[x]){
		if(y==fa)continue;
		dfs(y,x),rt[x]=T.merge(rt[x],rt[y],-1e5,1e5);
	}
	f[x]=T.qry(rt[x],a[x]),T.insert(rt[x],b[x],f[x]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",f[i]);
	return 0;
}