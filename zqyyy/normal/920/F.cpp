#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3e5+7,M=1e6+7;
int n,m,a[N],d[M];
struct Segment_Tree{
	ll t[N<<2];int mx[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p){
		t[p]=t[ls]+t[rs];
		mx[p]=max(mx[ls],mx[rs]);
	}
	void build(int p,int l,int r){
		if(l==r){t[p]=mx[p]=a[l];return;}
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		upd(p);
	}
	void modify(int p,int l,int r,int x,int y){
		if(mx[p]<=2)return;
		if(l==r){t[p]=mx[p]=d[t[p]];return;}
		int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y);
		if(y>mid)modify(rs,mid+1,r,x,y);
		upd(p);
	}
	ll query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		int mid=(l+r)>>1;ll res=0;
		if(x<=mid)res=query(ls,l,mid,x,y);
		if(y>mid)res+=query(rs,mid+1,r,x,y);
		return res;	
	}
}T;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=1e6;i++)
		for(int j=i;j<=1e6;j+=i)d[j]++;
	T.build(1,1,n);
	while(m--){
		int op=read(),l=read(),r=read();
		if(op==1)T.modify(1,1,n,l,r);
		else printf("%lld\n",T.query(1,1,n,l,r));
	}
	return 0;	
}