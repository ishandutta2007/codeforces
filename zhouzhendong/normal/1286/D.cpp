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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (x>y)
		x=y;
}
const int mod=998244353;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
const int N=100005;
int n,inv100=Pow(100,mod-2);
struct P{
	int x,v,pr,pl;
}a[N];
struct E{
	int x,t0,t1,ta,tb;
};
struct Mat{
	int v[2][2];
	Mat(){}
	Mat(int x){
		clr(v);
		v[0][0]=v[1][1]=x;
	}
};
Mat operator * (Mat a,Mat b){
	Mat c(0);
	For(i,0,1)
		For(k,0,1)
			For(j,0,1)
				Add(c.v[i][j],(LL)a.v[i][k]*b.v[k][j]%mod);
	return c;
}
namespace seg{
	Mat val[N<<2];
	void build(int rt,int L,int R){
		if (L==R){
			val[rt].v[0][0]=a[L].pl;
			val[rt].v[0][1]=a[L].pl;
			val[rt].v[1][0]=a[L].pr;
			val[rt].v[1][1]=a[L].pr;
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		val[rt]=val[ls]*val[rs];
	}
	void update(int rt,int L,int R,int x,int t0,int t1){
		if (L==R){
			val[rt].v[t0][t1]=0;
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		if (x<=mid)
			update(ls,L,mid,x,t0,t1);
		else
			update(rs,mid+1,R,x,t0,t1);
		val[rt]=val[ls]*val[rs];
	}
	int query(){
		Mat v=val[1];
		int res=0;
		Add(res,(LL)v.v[0][0]*a[n].pl%mod);
		Add(res,(LL)v.v[0][1]*a[n].pr%mod);
		Add(res,(LL)v.v[1][0]*a[n].pl%mod);
		Add(res,(LL)v.v[1][1]*a[n].pr%mod);
		return res;
	}
}
int main(){
	n=read();
	if (n==1)
		return puts("0"),0;
	For(i,1,n){
		a[i].x=read();
		a[i].v=read();
		a[i].pr=read()*inv100%mod;
		a[i].pl=Del(1-a[i].pr);
	}
	sort(a+1,a+n+1,[&](P a,P b){
		return a.x<b.x;
	});
	vector <E> e;
	For(i,1,n-1){
		int d=a[i+1].x-a[i].x;
		e.push_back((E){i,1,0,d,a[i].v+a[i+1].v});
		if (a[i].v>a[i+1].v)
			e.push_back((E){i,1,1,d,a[i].v-a[i+1].v});
		if (a[i+1].v>a[i].v)
			e.push_back((E){i,0,0,d,a[i+1].v-a[i].v});
	}
	sort(e.begin(),e.end(),[&](E a,E b){
		return (LL)a.ta*b.tb<(LL)b.ta*a.tb;
	});
	seg::build(1,1,n-1);
	int ans=0,las=0;
	for (auto event : e){
		int i=event.x,j=i+1;
		int ti=event.t0;
		int tj=event.t1;
		int t=(LL)event.ta*Pow(event.tb,mod-2)%mod;
		Add(ans,(LL)seg::query()*Del(t-las)%mod);
		las=t;
		seg::update(1,1,n-1,i,ti,tj);
	}
	Del(ans,(LL)seg::query()*las%mod);
	cout<<ans<<endl;
	return 0;
}