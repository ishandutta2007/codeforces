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
#define pb push_back
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
void enable_comma(){}
string tostring(char c){
	string s="";
	s+=c;
	return s;
}
string tostring(string s){
	return "\""+s+"\"";
}
string tostring(const char *c){
	return tostring((string)c);
}
string tostring(long long x){
	if (x<0)
		return "-"+tostring(-x);
	if (x>9)
		return tostring(x/10)+tostring(char('0'+x%10));
	else
		return tostring(char('0'+x));
}
string tostring(int x){
	return tostring((long long)x);
}
string tostring(unsigned long long x){
	if (x>9)
		return tostring((long long)(x/10))+tostring(char('0'+x%10));
	else
		return tostring(char('0'+x));
}
string tostring(unsigned x){
	return tostring((long long)x);
}
string tostring(double x){
	static char res[114];
	sprintf(res,"%lf",x);
	string s=tostring(res);
	return s.substr(1,(int)s.size()-2);
}
string tostring(long double x){
	return tostring((double)x);
}
template <class A,class B> string tostring(pair <A,B> p){
	return "("+tostring(p.fi)+","+tostring(p.se)+")";
}
template <class T> string tostring(T v){
	string res="";
	for (auto p : v)
		res+=(res.size()?",":"{")+tostring(p);
	return res.size()?res+"}":"{}";
}
template <class A> string tostring(A* a,int L,int R){
	return tostring(vector <A>(a+L,a+R+1));
};
template <class A> string tostring(A a,int L,int R){
	return tostring(a.data(),L,R);
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
	#define outvals(...) cerr<<"["<<#__VA_ARGS__<<"]: "<<\
								tostrings(__VA_ARGS__)<<endl
	#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
	#define outsign(x) cerr<<"<"#x">"<<endl
	#define outarr(a,L,R) cerr<<#a"["<<(L)<<".."<<(R)<<"] = "<<\
								tostring(a,L,R)<<endl
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
//	y=(y%(mod-1)+(mod-1))%(mod-1);
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
const int N=200005,INF=1e9;
int n,m;
vi e[N],r[N];
namespace so1{
	int dis[N][20];
	int main(){
		For(i,1,n)
			For(j,0,19)
				dis[i][j]=INF;
		dis[1][0]=0;
		priority_queue <pair <int,pii>,vector <pair <int,pii> >,greater <pair <int,pii> > > q;
		q.push(mp(0,mp(1,0)));
		while (!q.empty()){
			int x=q.top().se.fi,t=q.top().se.se;
			q.pop();
			for (auto y : (t%2==0?e:r)[x])
				if (dis[x][t]+1<dis[y][t]){
					dis[y][t]=dis[x][t]+1;
					q.push(mp(dis[y][t],mp(y,t)));
				}
			if (t<19){
				if (dis[x][t]+(1<<t)<dis[x][t+1]){
					dis[x][t+1]=dis[x][t]+(1<<t);
					q.push(mp(dis[x][t+1],mp(x,t+1)));
				}
			}
		}
		int ans=INF;
		For(i,0,19)
			ckmin(ans,dis[n][i]);
		return ans;
	}
}
pii dis[N][2];
void solve(){
	n=read(),m=read();
	For(i,1,n)
		e[i].clear(),r[i].clear();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y);
		r[y].pb(x);
	}
	int hhz=so1::main();
	if (hhz<INF){
		return printf("%d\n",hhz),void();
	}
	For(i,1,n)
		For(j,0,1)
			dis[i][j]=mp(INF,INF);
	priority_queue <pair <pii,pii>,vector <pair <pii,pii> >,greater <pair <pii,pii> > > q;
	dis[1][0]=mp(0,0);
	q.push(mp(dis[1][0],mp(1,0)));
	while (!q.empty()){
		int x=q.top().se.fi,t=q.top().se.se;
		q.pop();
		for (auto y : (!t?e:r)[x])
			if (mp(dis[x][t].fi,dis[x][t].se+1)<dis[y][t]){
				dis[y][t]=mp(dis[x][t].fi,dis[x][t].se+1);
				q.push(mp(dis[y][t],mp(y,t)));
			}
		if (mp(dis[x][t].fi+1,dis[x][t].se)<dis[x][t^1]){
			dis[x][t^1]=mp(dis[x][t].fi+1,dis[x][t].se);
			q.push(mp(dis[x][t^1],mp(x,t^1)));
		}
	}
	int mod=998244353;
	int ans=1;
	pii res=min(dis[n][0],dis[n][1]);
	For(i,1,res.fi)
		ans=ans*2%mod;
	ans--;
	ans=(ans+res.se)%mod;
	printf("%d\n",ans);
}
int main(){
	solve();
	return 0;
}