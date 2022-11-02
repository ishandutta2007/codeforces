#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
const LL INF=1LL<<56;
int n,m;
LL d[N],h[N];
struct Segment{
	LL val,v0,v1;
	Segment(){}
	Segment(LL a,LL b,LL c){
		val=a,v0=b,v1=c;
	}
}t[N<<2];
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
Segment merge(Segment ls,Segment rs){
	Segment rt;
	rt.val=max(max(ls.val,rs.val),ls.v0+rs.v1);
	rt.v0=max(ls.v0,rs.v0);
	rt.v1=max(ls.v1,rs.v1);
	return rt;
}
void build(int rt,int L,int R){
	if (L==R){
		t[rt].v0=h[L]-d[L-1],t[rt].v1=h[L]+d[L-1],t[rt].val=-INF;
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	t[rt]=merge(t[ls],t[rs]);
}
Segment query(int rt,int L,int R,int xL,int xR){
	if (L>xR||R<xL||xL>xR)
		return Segment(-INF,-INF,-INF);
	if (xL<=L&&R<=xR)
		return t[rt];
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return merge(query(ls,L,mid,xL,xR),query(rs,mid+1,R,xL,xR));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		d[i]=read()+d[i-1];
	for (int i=1;i<=n;i++)
		h[i]=read()*2;
	for (int i=1;i<=n;i++)
		d[i+n]=d[i]+d[n],h[i+n]=h[i];
	build(1,1,n*2);
	for (int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		if (b>=a)
			a+=n;
		printf("%I64d\n",query(1,1,n*2,b+1,a-1).val);
	}
	return 0;
}