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
int n,Q;
char str[N];
struct Segment_Tree{
#define M (N<<2)
	int t[M],sum[M],lmx[M],rmn[M];
	int lv[M],rv[M],mxv[M];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p){
		sum[p]=sum[ls]+sum[rs];
		lmx[p]=max(lmx[ls],sum[ls]+lmx[rs]);
		rmn[p]=min(rmn[rs],sum[rs]+rmn[ls]);
		lv[p]=max({lv[ls],mxv[ls]+lmx[rs],lv[rs]-sum[ls]});
		rv[p]=max({rv[rs],mxv[rs]-rmn[ls],rv[ls]+sum[rs]});
		mxv[p]=max(mxv[ls]+sum[rs],mxv[rs]-sum[ls]);
		t[p]=max({t[ls],t[rs],lv[rs]-rmn[ls],rv[ls]+lmx[rs]});
	}
	void build(int p,int l,int r){
		if(l==r){
			int v=str[l]=='('?1:-1;
			t[p]=mxv[p]=lv[p]=rv[p]=1,sum[p]=v;
			lmx[p]=max(v,0),rmn[p]=min(v,0);
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r),upd(p);
	}
	void modify(int p,int l,int r,int x,int v){
		if(l==r){
			t[p]=mxv[p]=lv[p]=rv[p]=1,sum[p]=v;
			lmx[p]=max(v,0),rmn[p]=min(v,0);
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,v);
		else modify(rs,mid+1,r,x,v);
		upd(p);
	}
#undef M
}T;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=(read()-1)<<1,Q=read();
	scanf("%s",str+1),T.build(1,1,n);
	printf("%d\n",T.t[1]);
	while(Q--){
		int x=read(),y=read();
		swap(str[x],str[y]);
		T.modify(1,1,n,x,str[x]=='('?1:-1);
		T.modify(1,1,n,y,str[y]=='('?1:-1);
		printf("%d\n",T.t[1]);
	}
	return 0;
}