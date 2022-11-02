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
const int N=500005*2,INF=1e9;
int n;
int ans;
LL a[N];
LL k[N],b[N];
LL calc(int i,LL v){
	return k[i]*v+b[i];
}
set <LL> S;
int findlr(int i,LL L,LL R){
	L=calc(i,L),R=calc(i,R);
	if (L>R)
		swap(L,R);
	auto it=S.lower_bound(L);
	return it!=S.end()&&*it<=R;
}
void only_save(int i,LL L,LL R){
	L=calc(i,L),R=calc(i,R);
	if (L>R)
		swap(L,R);
	while (!S.empty()&&*S.begin()<L)
		S.erase(S.begin());
	while (!S.empty()&&*prev(S.end())>R)
		S.erase(prev(S.end()));
}
void reget(int i,LL &mi,LL &mx){
	mi=1,mx=a[i]-1;
	if (a[i]%2==0)
		mi=mx=a[i]/2,ans--;
}
void trans(int i,LL &mi,LL &mx){
	outvals("trans",i,mi,mx);
	if (a[i]>mi){
		LL tmi=max(1LL,a[i]-mx);
		LL tmx=a[i]-mi;
		mi=tmi,mx=tmx;
	}
	else 
		mi=INF;
}
void solve(){
	n=read();
	For(i,1,n)
		a[i]=read();
	k[n+1]=1,b[n+1]=0;
	Fod(i,n,1){
		//(k[i+1](a[i]-x) + b[i+1])
		k[i]=-k[i+1];
		b[i]=k[i+1]*a[i]+b[i+1];
	}
	ans=n*2;
	LL mi,mx;
	reget(1,mi,mx);
	S.clear();
	For(i,2,n){
//for (auto v : S) outval(v);
		if (a[i]%2==1){
			int nowv=0;
			ckmax(nowv,(int)(a[i]>mi));
			ckmax(nowv,findlr(i,1,a[i]-1));
			ans-=nowv;
			if (nowv==0){
				S.clear();
				reget(i,mi,mx);
			}
			else {
				trans(i,mi,mx);
				only_save(i,1,a[i]-1);
			}
		}
		else {
			int nowv=0;
			LL half=a[i]/2;
			ckmax(nowv,1+(mi<=half&&half<=mx));
			ckmax(nowv,1+(findlr(i,half,half)));
			outvals(mi,mx,half,nowv,calc(i,half));
			assert(nowv==1||nowv==2);
			ans-=nowv;
			if (nowv==1){
				trans(i,mi,mx);
				only_save(i,1,a[i]-1);
				S.insert(calc(i,half));
			}
			else {
				if (mi<=half&&half<=mx)
					mi=mx=half;
				else
					mi=INF;
				only_save(i,half,half);
			}
		}
//		outvals(i,ans);
	}
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}
/*
1
5
4 4 2 3 4
*/