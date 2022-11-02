#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=150005*4,INF=1e9;
int n;
int a[N],p[N];
LL ans[N];
LL c[N],mi[N],semi[N],mic[N],add[N],sum[N],addmi[N];
template <typename T> void ckmin(T &a,T b){
	if (a>b)
		a=b;
}
void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	mi[rt]=min(mi[ls],mi[rs]);
	semi[rt]=min(semi[ls],semi[rs]);
	if (mi[ls]!=mi[rt])
		ckmin(semi[rt],mi[ls]);
	if (mi[rs]!=mi[rt])
		ckmin(semi[rt],mi[rs]);
	mic[rt]=(mi[ls]==mi[rt]?mic[ls]:0)+(mi[rs]==mi[rt]?mic[rs]:0);
	c[rt]=c[ls]+c[rs];
	sum[rt]=sum[ls]+sum[rs];
}
void build(int rt,int L,int R){
	mi[rt]=INF,semi[rt]=INF*2,mic[rt]=c[rt]=sum[rt]=add[rt]=addmi[rt]=0;
	if (L==R)
		return;
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
}
void pushson(int rt,LL v,LL vmi){
	mi[rt]+=v;
	semi[rt]+=v;
	sum[rt]+=v*c[rt];
	add[rt]+=v;
	sum[rt]+=vmi*mic[rt];
	mi[rt]+=vmi;
	addmi[rt]+=vmi;
}
void pushdown(int rt){
	if (add[rt]||addmi[rt]){
		int ls=rt<<1,rs=ls|1;
		pushson(ls,add[rt],mi[rt]-add[rt]-addmi[rt]==mi[ls]?addmi[rt]:0);
		pushson(rs,add[rt],mi[rt]-add[rt]-addmi[rt]==mi[rs]?addmi[rt]:0);
		add[rt]=addmi[rt]=0;
	}
}
void segadd(int rt,int L,int R,int xL,int xR,int v){
	if (R<xL||L>xR)
		return;
	if (xL<=L&&R<=xR)
		return (void)pushson(rt,v,0);
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	segadd(ls,L,mid,xL,xR,v);
	segadd(rs,mid+1,R,xL,xR,v);
	pushup(rt);
}
void segmax(int rt,int L,int R,int xL,int xR,int v){
	if (R<xL||L>xR||v<=mi[rt])
		return;
	if (xL<=L&&R<=xR&&v<semi[rt])
		return (void)pushson(rt,0,v-mi[rt]);
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	segmax(ls,L,mid,xL,xR,v);
	segmax(rs,mid+1,R,xL,xR,v);
	pushup(rt);
}
void pointadd(int rt,int L,int R,int x){
	if (L==R)
		return (void)(c[rt]=mic[rt]=1,mi[rt]=sum[rt]=0,semi[rt]=INF);
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		pointadd(ls,L,mid,x);
	else
		pointadd(rs,mid+1,R,x);
	pushup(rt);
}
int query_cnt(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return c[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return query_cnt(ls,L,mid,xL,xR)+query_cnt(rs,mid+1,R,xL,xR);
}
void Work(){
	For(i,1,n)
		p[a[i]]=i;
	build(1,1,n);
	LL now=0;
	For(i,1,n){
		now+=i;
		int cnt=query_cnt(1,1,n,1,p[i]);
		segmax(1,1,n,p[i]+1,n,cnt);
		segadd(1,1,n,p[i]+1,n,1);
		pointadd(1,1,n,p[i]);
		ans[i]+=now-sum[1];
	}
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	For(_,0,1)
		Work(),reverse(a+1,a+n+1);
	For(i,1,n)
		printf("%lld\n",ans[i]-i);
	return 0;
}