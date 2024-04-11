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
//const int mod=1e9+7;
//int Pow(int x,LL y){
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
const int N=505,INF=1e9;
int n,k;
int r[N][N],c[N][N];
int dis[N][N],vis[N][N];
void solve(){
	k=read(),n=read();
	clr(r),clr(c);
	For(i,1,k){
		int x0=read(),y0=read(),x1=read(),y1=read();
		if (x0>x1)
			swap(x0,x1);
		if (y0>y1)
			swap(y0,y1);
		if (x0==x1){
			r[x0][y0]++;
			r[n-x1+1][n-y1+1]++;
		} else {
			c[x0][y0]++;
			c[n-x1+1][n-y1+1]++;
		}
	}
	For(i,0,n)
		For(j,0,n)
			dis[i][j]=INF;
	clr(vis);
	dis[0][0]=0;
	priority_queue <pair <int,pii> > q;
	q.push(mp(0,mp(0,0)));
	while (!q.empty()){
		auto _=q.top();
		q.pop();
		int x=_.se.fi,y=_.se.se;
		if (vis[x][y])
			continue;
		vis[x][y]=1;
		auto gao=[&](int x,int y,int v){
			if (v<dis[x][y]){
				dis[x][y]=v;
				q.push(mp(-dis[x][y],mp(x,y)));
			}
		};
		if (x>0){
			gao(x-1,y,dis[x][y]+r[x][y]);
		}
		if (x<n){
			gao(x+1,y,dis[x][y]+r[x+1][y]);
		}
		if (y>0){
			gao(x,y-1,dis[x][y]+c[x][y]);
		}
		if (y<n){
			gao(x,y+1,dis[x][y]+c[x][y+1]);
		}
	}
//	For(i,0,n){outarr(dis[i],0,n);}
//	For(i,0,n){outarr(r[i],0,n);}
//	For(i,0,n){outarr(c[i],0,n);}
	cout<<k-dis[n/2][n/2]<<endl;
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}