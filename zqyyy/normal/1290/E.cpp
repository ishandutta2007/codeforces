#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=150007,inf=1e9;
int n,a[N],pos[N];
struct Segment_Tree{
#define M (N<<2)
	ll sum[M];
	int mx[M],cmx[M],num[M],len[M];
	int tg[M],mxtg[M];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p){
		sum[p]=sum[ls]+sum[rs],len[p]=len[ls]+len[rs];
		if(mx[ls]>mx[rs])mx[p]=mx[ls],num[p]=num[ls],cmx[p]=max(cmx[ls],mx[rs]);
		else if(mx[ls]<mx[rs])mx[p]=mx[rs],num[p]=num[rs],cmx[p]=max(mx[ls],cmx[rs]);
		else mx[p]=mx[ls],num[p]=num[ls]+num[rs],cmx[p]=max(cmx[ls],cmx[rs]);
	}
	void build(int p,int l,int r){
		mx[p]=cmx[p]=-inf,sum[p]=num[p]=len[p]=tg[p]=0,mxtg[p]=-1;if(l==r)return;
		int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void ptg(int p,int v){
		mx[p]+=v,cmx[p]+=v,sum[p]+=(ll)v*len[p],tg[p]+=v;
		if(~mxtg[p])mxtg[p]+=v;
	}
	inline void pt(int p,int v){
		if(v<mx[p])sum[p]+=(ll)num[p]*(v-mx[p]),mx[p]=mxtg[p]=v;
	}
	inline void spread(int p){
		if(tg[p])ptg(ls,tg[p]),ptg(rs,tg[p]),tg[p]=0;
		if(~mxtg[p])pt(ls,mxtg[p]),pt(rs,mxtg[p]),mxtg[p]=-1;
	}
	void change(int p,int l,int r,int x,int y,int v){
		if(v>=mx[p])return;
		if(x<=l && r<=y && v>=cmx[p])return pt(p,v);
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)change(ls,l,mid,x,y,v);
		if(y>mid)change(rs,mid+1,r,x,y,v);
		upd(p);
	}
	void modify(int p,int l,int r,int x,int y,int v){
		if(x<=l && r<=y)return ptg(p,v);
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,v);
		if(y>mid)modify(rs,mid+1,r,x,y,v);
		upd(p);
	}
	void changep(int p,int l,int r,int x,int v){
		if(l==r){
			len[p]=num[p]=1,sum[p]=mx[p]=v;
			return;
		}
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)changep(ls,l,mid,x,v);
		else changep(rs,mid+1,r,x,v);
		upd(p);
	}
	ll query(){return sum[1];}
#undef M
#undef ls
#undef rs
}T;
struct Fenwick{
	int c[N];
	inline void clear(){fill(c+1,c+n+1,0);}
	inline void add(int p,int x){for(;p<=n;p+=p&-p)c[p]+=x;}
	inline int ask(int p){int res=0;for(;p;p^=p&-p)res+=c[p];return res;}
}t;
ll ans[N];
inline void work(){
	T.build(1,1,n),t.clear();
	for(int i=1;i<=n;i++)pos[a[i]]=i;
	for(int i=1;i<=n;i++){
		int p=pos[i],c=t.ask(p);
		t.add(p,1);
		if(p<n)T.modify(1,1,n,p+1,n,1);
		if(p>1)T.change(1,1,n,1,p-1,c);
		T.changep(1,1,n,p,i),ans[i]+=T.query();
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	work(),reverse(a+1,a+n+1),work();
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]-(ll)i*i);
	return 0;
}