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
const int N=500055;
const LL INF=1e18;
int n;
int a[N];
LL ans=0;
int lp[N],rp[N];
int l[N][20],r[N][20];
int Log[N];
int qtol(int L,int R){
	int d=Log[R-L+1];
	return max(l[L+(1<<d)-1][d],l[R][d]);
}
int qtor(int L,int R){
	int d=Log[R-L+1];
	return max(r[L+(1<<d)-1][d],r[R][d]);
}
int findl(int r,int mx){
	outval(mx);
	int L=1,R=r-1,res=r;
	while (L<=R){
		int mid=(L+R)>>1;
		if (qtor(mid,r-1)<=mx)
			R=mid-1,res=mid;
		else
			L=mid+1;
	}
	outvals("findl",r,mx,res);
	return res;
}
int findr(int l,int mx){
	int L=l+1,R=n,res=l;
	while (L<=R){
		int mid=(L+R)>>1;
		if (qtol(l+1,mid)<=mx)
			L=mid+1,res=mid;
		else
			R=mid-1;
	}
	outvals("findr",l,mx,res);
	return res;
}
void solve(){
	n=read();
	For(i,1,n)
		scanf("%1d",&a[i]);
	For(i,1,n)
		lp[i]=a[i]?lp[i-1]:i;
	rp[n+1]=n+1;
	Fod(i,n,1)
		rp[i]=a[i]?rp[i+1]:i;
	For(i,2,n)
		Log[i]=Log[i>>1]+1;
	For(i,1,n){
		l[i][0]=i-lp[i];
		r[i][0]=rp[i]-i;
		For(j,1,19){
			l[i][j]=l[i][j-1];
			r[i][j]=r[i][j-1];
			if (i-(1<<(j-1))>0){
				ckmax(l[i][j],l[i-(1<<(j-1))][j-1]);
				ckmax(r[i][j],r[i-(1<<(j-1))][j-1]);
			}
		}
	}
	outarr(lp,1,n);outarr(rp,1,n);
	For(i,1,n)
		if (a[i]==1&&lp[i]==i-1){
			int L=i,R=rp[i]-1,len=R-L+1;
			outvals(L,R);
			For(i,1,len)
				ans+=(LL)i*(i+1)/2;
			outval(ans);
			ans+=(LL)(L-findl(L,len-1))*(findr(R,len)-R)*len;
			outval(ans);
			For(i,1,len){
				ans+=(LL)i*(L-findl(L,i-1));
				ans+=(LL)i*(findr(R,i)-R);
			}
			outval(ans);
		}
	cout<<ans<<endl;
}
int main(){
	int T=1;
	while (T--){
		solve();
	}
	return 0;
}