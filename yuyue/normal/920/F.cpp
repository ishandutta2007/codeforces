#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int cnt[M*4],n,m,w[M],maxn;
struct Segment_Tree{
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid (l+r>>1)
	LL a[M<<2];
	LL mx[M<<2];
	void pushup(int x){
		mx[x]=max(mx[lc],mx[rc]);
		a[x]=a[lc]+a[rc];
	}
	void build(int x,int l,int r){
		if (l==r){
			a[x]=mx[x]=w[l];
			return ;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int ll,int rr){
		if (l==r){
			a[x]=mx[x]=cnt[a[x]];
			return ;
		}
		if (ll<=mid && mx[lc]>2) update(lc,l,mid,ll,rr);
		if (rr>mid && mx[rc]>2) update(rc,mid+1,r,ll,rr);
		pushup(x);
	}
	LL query(int x,int l,int r,int ll,int rr){
		if (l==ll && r==rr) return a[x];
		if (rr<=mid) return query(lc,l,mid,ll,rr);
		if (ll>mid) return query(rc,mid+1,r,ll,rr);
		return query(lc,l,mid,ll,mid)+query(rc,mid+1,r,mid+1,rr);
	}
}sgt;
int main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++){
		w[i]=read();
		maxn=max(maxn,w[i]);
	}
	sgt.build(1,1,n);
	for (int i=1;i<=maxn;i++){
		int k=1; 
		while (k*i<=maxn) cnt[k*i]++,k++;
	}
	for (int i=1;i<=m;i++){
		int opt=read(),x=read(),y=read();
		if (opt==1){
			sgt.update(1,1,n,x,y);
		}
		else {
			cout<<sgt.query(1,1,n,x,y)<<'\n';
		}
	}
	return 0;
}