#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,m;
struct Segment_Tree{
	ll t[N<<2];
	int mx[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p){
		t[p]=t[ls]+t[rs];
		mx[p]=max(mx[ls],mx[rs]);
	}
	void build(int p,int l,int r){
		if(l==r){t[p]=mx[p]=read();return;}
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r),upd(p);
	}
	void modify(int p,int l,int r,int x,int y,int mod){
		if(l==r){t[p]=mx[p]=t[p]%mod;return;}
		if(mx[p]<mod)return;
		int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,mod);
		if(y>mid)modify(rs,mid+1,r,x,y,mod);
		upd(p);
	}
	void change(int p,int l,int r,int x,int y){
		if(l==r){t[p]=mx[p]=y;return;}
		int mid=(l+r)>>1;
		x<=mid?change(ls,l,mid,x,y):change(rs,mid+1,r,x,y);
		upd(p);
	}
	ll query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		int mid=(l+r)>>1;ll res=0;
		if(x<=mid)res+=query(ls,l,mid,x,y);
		if(y>mid)res+=query(rs,mid+1,r,x,y);
		return res;
	}
}T;
int main(){
	n=read(),m=read(),T.build(1,1,n);
	while(m--){
		int op=read(),x=read(),y=read(),z;
		if(op==1)printf("%lld\n",T.query(1,1,n,x,y));
		else if(op==2)z=read(),T.modify(1,1,n,x,y,z);
		else T.change(1,1,n,x,y);
	}
	return 0;
}