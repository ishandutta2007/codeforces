#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=300005,mod=1e9+7;
int n;
int a[N],dp[N];
int Min[N<<2],sum[N<<2],add[N<<2];
int mx[N],px[N],tx;
int mi[N],pi[N],ti;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	Min[rt]=min(Min[ls],Min[rs]);
	sum[rt]=0;
	if (Min[ls]==Min[rt])
		Add(sum[rt],sum[ls]);
	if (Min[rs]==Min[rt])
		Add(sum[rt],sum[rs]);
}
void pushdown(int rt){
	int ls=rt<<1,rs=ls|1,&x=add[rt];
	Add(Min[ls],x);
	Add(Min[rs],x);
	Add(add[ls],x);
	Add(add[rs],x);
	x=0;
}
void change(int rt,int L,int R,int x,int d){
	if (L==R){
		Min[rt]=d;
		sum[rt]=1;
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		change(ls,L,mid,x,d);
	else
		change(rs,mid+1,R,x,d);
	pushup(rt);
}
void update(int rt,int L,int R,int xL,int xR,int d){
	if (xR<L||xL>R)
		return;
	if (xL<=L&&R<=xR){
		Add(Min[rt],d);
		Add(add[rt],d);
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	update(ls,L,mid,xL,xR,d);
	update(rs,mid+1,R,xL,xR,d);
	pushup(rt);
}
int addv(int a,int b){
	return a+b>=mod?a+b-mod:a+b;
}
int query(int rt,int L,int R,int xL,int xR,int d){
	if (xR<L||xL>R||Min[rt]>d)
		return 0;
	if (xL<=L&&R<=xR)
		return sum[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return addv(query(ls,L,mid,xL,xR,d),query(rs,mid+1,R,xL,xR,d));
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		a[x]=y;
	}
	tx=ti=0,dp[0]=1;
	LL ans=0;
	for (int i=1;i<=n;i++){
		change(1,1,n,i,i);
		int p=i;
		while (tx>0&&mx[tx]<=a[i]){
			update(1,1,n,px[tx],i-1,a[i]-mx[tx]);
			p=px[tx--];
		}
		tx++,mx[tx]=a[i],px[tx]=p;
		p=i;
		while (ti>0&&mi[ti]>=a[i]){
			update(1,1,n,pi[ti],i-1,mi[ti]-a[i]);
			p=pi[ti--];
		}
		ti++,mi[ti]=a[i],pi[ti]=p;
		ans+=query(1,1,n,1,i,i);
	}
	cout<<ans<<endl;
	return 0;
}