#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+7,M=1e6+7;
struct lr{
	int l,r,w;
	bool operator <(const lr &q) const {
		return w<q.w;	
	}
}a[N];
struct Segment_Tree{
	int t[M<<2],tg[M<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p){t[p]=min(t[ls],t[rs]);}
	inline void spread(int p){
		if(!tg[p])return;
		t[ls]+=tg[p],tg[ls]+=tg[p];
		t[rs]+=tg[p],tg[rs]+=tg[p],tg[p]=0;
	}
	void modify(int p,int l,int r,int x,int y,int w){
		if(x<=l && r<=y){
			t[p]+=w,tg[p]+=w;
			return;
		}
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,w);
		if(y>mid)modify(rs,mid+1,r,x,y,w);
		upd(p);
	}
}T;
int n,m;
int main(){
	n=read(),m=read()-1;
	for(int i=1;i<=n;i++)a[i].l=read(),a[i].r=read()-1,a[i].w=read();
	sort(a+1,a+n+1);int ans=1e9;
	for(int l=1,r=0;l<=n;l++){
		while(r<n && !T.t[1])r++,T.modify(1,1,m,a[r].l,a[r].r,1);
		if(!T.t[1])break;ans=min(ans,a[r].w-a[l].w);
		T.modify(1,1,m,a[l].l,a[l].r,-1);
	}
	return cout<<ans,0;
}