#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=5e5+7;
int n,a[N],f[N];
struct b1t{
	int c[N];
#define lb(x) ((x)&-(x))
	inline void clear(){for(int i=1;i<=n;i++)c[i]=0;}
	inline void add(int p,int x){for(;p<=n;p+=lb(p))c[p]=max(c[p],x);}
	inline int ask(int p){int res=0;for(;p;p-=lb(p))res=max(res,c[p]);return res;}
}B;
struct Segment_Tree{
	int t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p){t[p]=min(t[ls],t[rs]);}
	void build(int p,int l,int r){
		if(l==r){t[p]=a[l];return;}
		int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),upd(p);
	}
	void modify(int p,int l,int r,int x,int y,int w){
		if(l==r){t[p]=1e9,B.add(a[l],f[l]+1);return;}
		int mid=(l+r)>>1;
		if(x<=mid && t[ls]<w)modify(ls,l,mid,x,y,w);
		if(y>mid && t[rs]<w)modify(rs,mid+1,r,x,y,w);
		upd(p);
	}
}T;
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	B.clear(),T.build(1,1,n);int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=max(i==1?1:2,B.ask(a[i])+1);
		B.add(a[i],f[i]),T.modify(1,1,n,1,i,a[i]);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
}
int main(){
	int TAT=read();
	while(TAT--)work();
	return 0;
}