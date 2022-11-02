#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define y0 _z_y0
#define y1 _z_y1
#define x0 _z_x0
#define x1 _z_x1
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
void enable_comma(){}
string tostring(char c);
string tostring(LL x);
template <class A,class B> string tostring(pair <A,B> p);
template <class A> string tostring(vector <A> v);
string tostring(char c){
	string s="";
	s+=c;
	return s;
}
string tostring(string s){
	return "\""+s+"\"";
}
string tostring(char *c){
	return tostring((string)c);
}
string tostring(LL x){
	if (x<0)
		return "-"+tostring(-x);
	if (x>9)
		return tostring(x/10)+tostring(char('0'+x%10));
	else
		return tostring(char('0'+x));
}
string tostring(int x){
	return tostring((LL)x);
}
string tostring(ull x){
	if (x>9)
		return tostring((LL)(x/10))+tostring(char('0'+x%10));
	else
		return tostring(char('0'+x));
}
string tostring(uint x){
	return tostring((LL)x);
}
string tostring(double x){
	static char res[114];
	sprintf(res,"%lf",x);
	return tostring(res);
}
string tostring(LD x){
	return tostring((double)x);
}
template <class A,class B> string tostring(pair <A,B> p){
	return "("+tostring(p.fi)+","+tostring(p.se)+")";
}

template <class A> string tostring(vector <A> v){
	string res="{";
	For(i,0,(int)v.size()-1){
		res+=tostring(v[i]);
		res+=i==(int)v.size()-1?"}":",";
	}
	if (res=="{")
		res+="}";
	return res;
}
template <class A> string tostring(A a,int L,int R){
	string res="{";
	For(i,L,R){
		res+=tostring(a[i]);
		res+=i==R?"}":",";
	}
	if (res=="{")
		res+="}";
	return res;
}
string tostrings(){
	return "";
}
template <typename Head,typename... Tail>
string tostrings(Head H,Tail... T){
	return tostring(H)+" "+tostrings(T...);
}
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
#ifdef zzd
	#define outval(x) cerr<<#x" = "<<tostring(x)<<endl
	#define outvals(...) cerr<<"["<<#__VA_ARGS__<<"]: "<<tostrings(__VA_ARGS__)<<endl
	#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
	#define outsign(x) cerr<<"<"#x">"<<endl
	#define outarr(a,L,R) cerr<<#a"["<<(L)<<".."<<(R)<<"] = "<<tostring(a,L,R)<<endl
#else
	#define outval(x) enable_comma()
	#define outvals(...) enable_comma()
	#define outtag(x) enable_comma()
	#define outsign(x) enable_comma()
	#define outarr(a,L,R) enable_comma()
#endif
#ifdef ONLINE_JUDGE
	#ifdef assert
		#undef assert
	#endif
	#define assert(x) (!(x)?\
			cout<<"Assertion failed!"<<endl<<\
			"function: "<<__FUNCTION__<<endl<<\
			"line: "<<__LINE__<<endl<<\
			"expression: "<<#x<<endl,exit(3),0:1)
#endif
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
const int N=500005*2;
int n,m,q;
int p[N];
pii e[N],t[N];
int ti[N];
namespace S{
	int fa[N];
	void init(){
		iota(fa,fa+N,0);
	}
	int getf(int x){
		return fa[x]==x?x:fa[x]=getf(fa[x]);
	}
}
int cnt;
int fa[N],val[N];
vi son[N];
int vis[N];
int I[N],O[N],ii[N];
int anc[N][20],dep[N];
int Time=0;
void dfs(int x,int d=1){
	vis[x]=1;
	anc[x][0]=fa[x];
	For(i,1,19)
		anc[x][i]=anc[anc[x][i-1]][i-1];
	dep[x]=d;
	I[x]=++Time;
	ii[Time]=x;
	for (auto y : son[x])
		dfs(y,d+1);
	O[x]=Time;
}
int pmax(int x,int y){
	return p[x]>p[y]?x:y;
}
namespace seg{
	const int S=N*4;
	int mx[S];
	void pushup(int rt){
		int ls=rt<<1,rs=ls|1;
		mx[rt]=pmax(mx[ls],mx[rs]);
	}
	void build(int rt,int L,int R){
		if (L==R){
			mx[rt]=ii[L];
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		pushup(rt);
	}
	int query(int rt,int L,int R,int xL,int xR){
		if (R<xL||L>xR)
			return 0;
		if (xL<=L&&R<=xR)
			return mx[rt];
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		return pmax(query(ls,L,mid,xL,xR),query(rs,mid+1,R,xL,xR));
	}
	void update(int rt,int L,int R,int x){
		if (L==R){
			mx[rt]=0;
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		if (x<=mid)
			update(ls,L,mid,x);
		else
			update(rs,mid+1,R,x);
		pushup(rt);
	}
}
void solve(){
	n=read(),m=read(),q=read();
	For(i,1,n)
		p[i]=read();
	For(i,1,m){
		int x=read(),y=read();
		e[i]=mp(x,y);
		ti[i]=q+1;
	}
	For(i,1,q){
		int tp=read(),x=read();
		t[i]=mp(tp,x);
		if (tp==2)
			ti[x]=i;
	}
	vi id(m);
	iota(id.begin(),id.end(),1);
	sort(id.begin(),id.end(),[&](int x,int y){
		return ti[x]>ti[y];
	});
	cnt=n;
	S::init();
	for (auto i : id){
		int x=e[i].fi,y=e[i].se;
		int fx=S::getf(x),fy=S::getf(y);
		if (fx!=fy){
			int f=++cnt;
			fa[fx]=fa[fy]=S::fa[fx]=S::fa[fy]=f;
			val[f]=ti[i];
			son[f]={fx,fy};
			outvals(f,val[f],son[f]);
		}
	}
	Fod(i,cnt,1)
		if (!vis[i])
			dfs(i);
	seg::build(1,1,cnt);
	For(i,1,q){
		int tp=t[i].fi,x=t[i].se;
		if (tp==1){
			Fod(j,19,0)
				if (val[anc[x][j]]>i)
					x=anc[x][j];
			int res=seg::query(1,1,cnt,I[x],O[x]);
			printf("%d\n",p[res]);
			p[res]=0;
			seg::update(1,1,cnt,I[res]);
		}
		else {
			
		}
	}
}
int main(){
	int T=1;
	while (T--)
		solve();
	return 0;
}