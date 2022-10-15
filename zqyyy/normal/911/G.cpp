#include <bits/stdc++.h>//
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m,a[N];
struct Segment_Tree{
	short t[N<<2][107];bool tg[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	void build(int p,int l,int r){
		for(int i=1;i<=100;i++)t[p][i]=i;
		if(l==r)return;int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void spread(int p){
		if(!tg[p])return;
		for(int i=1;i<=100;i++)t[ls][i]=t[p][t[ls][i]],t[rs][i]=t[p][t[rs][i]];
		for(int i=1;i<=100;i++)t[p][i]=i;tg[p]=0,tg[ls]=tg[rs]=1;
	}
	void modify(int p,int l,int r,int x,int y,int pr,int nw){
		if(x<=l && r<=y){
			for(int i=1;i<=100;i++)
				if(t[p][i]==pr)t[p][i]=nw;
			tg[p]=1;return;
		}
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,pr,nw);
		if(y>mid)modify(rs,mid+1,r,x,y,pr,nw);
	}
	void query(int p,int l,int r){
		if(l==r){
			printf("%d ",t[p][a[l]]);
			return;
		}
		spread(p);int mid=(l+r)>>1;
		query(ls,l,mid),query(rs,mid+1,r);
	}
}T;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read(),T.build(1,1,n);
	while(m--){
		int l=read(),r=read(),x=read(),y=read();
		T.modify(1,1,n,l,r,x,y);
	}
	T.query(1,1,n);
	return 0;	
}