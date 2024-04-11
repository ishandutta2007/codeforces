#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
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
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//int md(LL x){
//	return (x%mod+mod)%mod;
//}
const int N=300005;
int n,q;
int a[N];
struct qry{
	int x,y;
	int ans;
}b[N];
vi qs[N];
namespace seg{
	const int S=N*4;
	LL mi[S],add[S];
	void pushup(int rt){
		int ls=rt<<1,rs=ls|1;
		mi[rt]=min(mi[ls],mi[rs]);
	}
	void build(int rt,int L,int R){
		add[rt]=0;
		if (L==R){
			mi[rt]=a[L];
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		pushup(rt);
	}
	void pushdown(int rt){
		if (add[rt]){
			int ls=rt<<1,rs=ls|1;
			add[ls]+=add[rt];
			add[rs]+=add[rt];
			mi[ls]+=add[rt];
			mi[rs]+=add[rt];
			add[rt]=0;
		}
	}
	void update(int rt,int L,int R,int xL,int xR,int v){
		if (R<xL||L>xR)
			return;
		if (xL<=L&&R<=xR){
			add[rt]+=v;
			mi[rt]+=v;
			return;
		}
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		update(ls,L,mid,xL,xR,v);
		update(rs,mid+1,R,xL,xR,v);
		pushup(rt);
	}
	int find(int rt,int L,int R){
		if (L==R)
			return L;
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		if (mi[rs]==0)
			return find(rs,mid+1,R);
		else
			return find(ls,L,mid);
	}
}
int c[N];
void add(int x){
	for (;x<=n;x+=x&-x)
		c[x]++;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int main(){
	n=read(),q=read();
	For(i,1,n){
		a[i]=read();
		if (a[i]>i)
			a[i]=-1e9;
		a[i]=i-a[i];
	}
//	outarr(a,1,n);
	For(i,1,q){
		b[i].x=read(),b[i].y=read();
		qs[b[i].x].pb(i);
	}
	seg::build(1,1,n);
	Fod(i,n,1){
//		outtag();
//		outval(i);
		while (1){
//			outval(seg::mi[1]);
			if (seg::mi[1]>0)
				break;
			int j=seg::find(1,1,n);
//			outval(j);
			if (j<i)
				break;
//			outval(j);
			add(j);
			seg::update(1,1,n,j,j,1e9);
			seg::update(1,1,n,j+1,n,-1);
		}
		for (auto j : qs[i-1]){
			b[j].ans=ask(n-b[j].y);
		}
	}
	For(i,1,q)
		printf("%d\n",b[i].ans);
	return 0;
}