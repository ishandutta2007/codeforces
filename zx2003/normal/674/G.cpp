#include<bits/stdc++.h>
const int N=150005;
int n,m,p,i,o,l,r,x,a[N];
struct atom{
	int a[8],s[8],l;
	inline void ins(int x,int y){
		int i=1;for(;i<=l && a[i]!=x;++i);
		if(i<=l){y+=s[i];x=a[i];for(;i>1 && y>s[i-1];--i)a[i]=a[i-1],s[i]=s[i-1];a[i]=x;s[i]=y;return;}
		for(i=l;i && y>s[i];--i)a[i+1]=a[i],s[i+1]=s[i];a[i+1]=x;s[i+1]=y;++l;
		if(l==p+1){for(i=1;i<=p;++i)s[i]-=s[l];for(l=p;l && !s[l];--l);}
	}
	inline void operator+=(const atom&rhs){for(int i=1;i<=rhs.l;++i)ins(rhs.a[i],rhs.s[i]);
for(int i=1;i<l;++i)assert(s[i]>=s[i+1]);
}
	inline void out(){printf("%d ",l);for(int i=1;i<=l;++i)printf("%d ",a[i]);puts("");}
}A;
struct node{
	int lb,rb,md,v;
	atom s;
	inline void set(int x){v=x;s.l=1;s.a[1]=x;s.s[1]=rb-lb+1;}
}T[N<<2];
inline void down(int i){if(T[i].v)T[i<<1].set(T[i].v),T[i<<1|1].set(T[i].v),T[i].v=0;}
inline void upd(int i){T[i].s=T[i<<1].s;T[i].s+=T[i<<1|1].s;}
void build(int i,int l,int r){
	T[i].lb=l;T[i].rb=r;T[i].md=l+r>>1;
	if(l==r)return T[i].set(a[l]);
	build(i<<1,l,T[i].md);build(i<<1|1,T[i].md+1,r);upd(i);
}
void mdy(int i,int l,int r,int x){
	if(l<=T[i].lb && T[i].rb<=r)return T[i].set(x);
	down(i);if(l<=T[i].md)mdy(i<<1,l,r,x);if(T[i].md<r)mdy(i<<1|1,l,r,x);upd(i);
}
void ask(int i,int l,int r){
	if(l<=T[i].lb && T[i].rb<=r)return A+=T[i].s;
	down(i);if(l<=T[i].md)ask(i<<1,l,r);if(T[i].md<r)ask(i<<1|1,l,r);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);p=100/p;
	for(i=1;i<=n;++i)scanf("%d",a+i);build(1,1,n);
	for(;m--;){
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)scanf("%d",&x),mdy(1,l,r,x);else A.l=0,ask(1,l,r),A.out();
	}
	return 0;
}