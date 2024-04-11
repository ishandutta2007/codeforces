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
#define outtime() cerr<<"User Time = "<<(double)clock()/CLOCKS_PER_SEC<<endl
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
/*
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
*/
const int N=(1e6+6)*4;
const LL INF=1e18;
int n,m,p;
LL a[N],b[N];
LL mx[N],add[N];
struct G{
	int a,b,c;
}g[N];
bool cmp(G x,G y){
	if (x.a!=y.a)
		return x.a<y.a;
	return x.b<y.b;
}
void pushup(int rt){
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
void build(int rt,int L,int R){
	add[rt]=0;
	if (L==R){
		mx[rt]=-b[L];
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
		LL v=add[rt];
		mx[ls]+=v,mx[rs]+=v;
		add[ls]+=v,add[rs]+=v;
		add[rt]=0;
	}
}
void update(int rt,int L,int R,int xL,int xR,int v){
	if (R<xL||L>xR)
		return;
	if (xL<=L&&R<=xR){
		add[rt]+=v;
		mx[rt]+=v;
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	update(ls,L,mid,xL,xR,v);
	update(rs,mid+1,R,xL,xR,v);
	pushup(rt);
}
LL Query(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return -INF;
	if (xL<=L&&R<=xR)
		return mx[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return max(Query(ls,L,mid,xL,xR),Query(rs,mid+1,R,xL,xR));
}
int L=1,R=1e6+1;
int main(){
	n=read(),m=read(),p=read();
	For(i,1,R)
		a[i]=b[i]=INF;
	For(i,1,n){
		int x=read(),y=read();
		a[x]=min(a[x],(LL)y);
	}
	For(i,1,m){
		int x=read(),y=read();
		b[x]=min(b[x],(LL)y);
	}
	Fod(i,R-1,1){
		a[i]=min(a[i],a[i+1]);
		b[i]=min(b[i],b[i+1]);
	}
	For(i,1,p){
		g[i].a=read()+1,g[i].b=read()+1,g[i].c=read();
	}
	sort(g+1,g+p+1,cmp);
	build(1,L,R);
	LL ans=-a[1]-b[1];
	For(i,1,p){
		update(1,L,R,g[i].b,R,g[i].c);
		ans=max(ans,mx[1]-a[g[i].a]);
	}
	cout<<ans<<endl;
	return 0;
}