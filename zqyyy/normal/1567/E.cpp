#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
struct A{
	int lt,rt,lc,rc;
	ll cnt;
	int l,r;
	A operator +(const A &q) const {
		A t;
		t.lt=lt,t.rt=q.rt,t.l=l,t.r=q.r;
		t.lc=lc,t.rc=q.rc,t.cnt=cnt+q.cnt;
		if(rt<=q.lt){
			t.cnt+=1ll*rc*q.lc;
			if(lc==r-l+1)t.lc+=q.lc;
			if(q.rc==q.r-q.l+1)t.rc+=rc;
		}
		return t;
	}
};
struct Segment_Tree{
	A t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p){t[p]=t[ls]+t[rs];}
	void build(int p,int l,int r){
		if(l==r){
			int tmp=read();
			t[p]={tmp,tmp,1,1,1,l,r};
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		upd(p);
	}
	void modify(int p,int x,int y){
		if(t[p].l==t[p].r){
			t[p]={y,y,1,1,1,t[p].l,t[p].r};
			return;
		}
		int mid=(t[p].l+t[p].r)>>1;
		x<=mid?modify(ls,x,y):modify(rs,x,y);
		upd(p);
	}
	A query(int p,int x,int y){
		if(x<=t[p].l && t[p].r<=y)return t[p];
		int mid=(t[p].l+t[p].r)>>1;
		if(y<=mid)return query(ls,x,y);
		if(x>mid)return query(rs,x,y);
		return query(ls,x,y)+query(rs,x,y);
	}
}T;
int n,Q;
int main(){
	n=read(),Q=read(),T.build(1,1,n);
	while(Q--){
		int op=read(),x=read(),y=read();
		if(op==1)T.modify(1,x,y);
		else printf("%lld\n",T.query(1,x,y).cnt);
	}
	return 0;
}