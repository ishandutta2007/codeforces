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
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=200005;
int n,m;
char _g[N];
#define g(i,j) _g[(i-1)*m+j]
#define h(i,j) ((i-1)*m+j)
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dirid[300];
int check(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
void IN(){
	static char s[N];
	n=read(),m=read();
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m)
			g(i,j)=s[j];
	}
}
vi e[N],rts;
int t0=0,t1=0;
int I[N],O[N],tp[N],id[N];
void dfs(int x,int &Time){
	I[x]=++Time;
	if (tp[x]==0)
		id[Time]=x;
	for (auto y : e[x])
		dfs(y,Time);
	O[x]=Time;
}
namespace seg{
	const int S=N*4;
	int mi[S],cnt[S],add[S];
	void build(int rt,int L,int R){
		mi[rt]=0,cnt[rt]=R-L+1,add[rt]=0;
		if (L==R)
			return;
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	void pushup(int rt){
		int ls=rt<<1,rs=ls|1;
		mi[rt]=min(mi[ls],mi[rs]);
		cnt[rt]=(mi[rt]==mi[ls]?cnt[ls]:0)+(mi[rt]==mi[rs]?cnt[rs]:0);
	}
	void pushdown(int rt){
		if (!add[rt])
			return;
		int ls=rt<<1,rs=ls|1;
		add[ls]+=add[rt],add[rs]+=add[rt];
		mi[ls]+=add[rt],mi[rs]+=add[rt];
		add[rt]=0;
	}
	void update(int rt,int L,int R,int xL,int xR,int v){
		if (R<xL||L>xR)
			return;
		if (xL<=L&&R<=xR){
			add[rt]+=v,mi[rt]+=v;
			return;
		}
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		update(ls,L,mid,xL,xR,v);
		update(rs,mid+1,R,xL,xR,v);
		pushup(rt);
	}
}
vector <pii> add[N],rem[N];
int main(){
	IN();
	dirid['D']=0;
	dirid['U']=1;
	dirid['R']=2;
	dirid['L']=3;
	For(i,1,n)
		For(j,1,m){
			int d=dirid[(int)g(i,j)];
			tp[h(i,j)]=(i+j)&1;
			int x=i+dx[d]*2;
			int y=j+dy[d]*2;
			if (check(x,y))
				e[h(x,y)].pb(h(i,j));
			else
				rts.pb(h(i,j));
		}
	for (auto i : rts)
		dfs(i,tp[i]?t1:t0);
	For(i,1,n)
		For(j,1,m){
			if (tp[h(i,j)]==1)
				continue;
			int d=dirid[(int)g(i,j)];
			int x=i+dx[d],y=j+dy[d];
			int a=h(i,j),b=h(x,y);
			add[I[a]].pb(mp(I[b],O[b]));
			rem[O[a]].pb(mp(I[b],O[b]));
		}
	seg::build(1,1,t1);
	LL ans=0;
	For(i,1,t0){
		for (auto v : add[i])
			seg::update(1,1,t1,v.fi,v.se,1);
		ans+=seg::mi[1]?t1:t1-seg::cnt[1];
		for (auto v : rem[i])
			seg::update(1,1,t1,v.fi,v.se,-1);
	}
	cout<<ans<<endl;
	return 0;
}