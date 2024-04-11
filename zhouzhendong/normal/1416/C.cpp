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
const int N=300005;
int n;
int a[N];
LL All[30],Now[30];
int t0[N],t1[N];
void solve(int *a,int n,int d){
	if (d<0||n==0)
		return;
	//can't use a[0]
	LL now=0,c1=0,all=0;
	For(i,1,n){
		int v=a[i]>>d&1;
		if (v==0)
			now+=c1;
		else
			c1++;
	}
	all=(LL)c1*(n-c1);
	All[d]+=all;
	Now[d]+=now;
	int tc0=0,tc1=0;
	For(i,1,n){
		if (a[i]>>d&1)
			t1[++tc1]=a[i];
		else
			t0[++tc0]=a[i];
	}
	int c=0;
	For(i,1,tc0)
		a[++c]=t0[i];
	For(i,1,tc1)
		a[++c]=t1[i];
	solve(a,tc0,d-1);
	solve(a+tc0,tc1,d-1);
}
void solve(){
	n=read();
	For(i,1,n)
		a[i]=read();
	solve(a,n,29);
	LL x=0,b=0;
	outarr(Now,0,3),outarr(All,0,3);
	For(i,0,29){
		b+=min(Now[i],All[i]-Now[i]);
		if (Now[i]>All[i]-Now[i])
			x|=1<<i;
	}
	cout<<b<<" "<<x<<endl;
}
int main(){
	int T=1;
	while (T--)
		solve();
	return 0;
}