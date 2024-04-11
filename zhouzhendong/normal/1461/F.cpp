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
const int N=100005,INF=2e6;
int n;
int a[N];
int p[N],cnt=0;
int dp[100],pre[100];
int vv[N];
void solve(int L,int R){
	assert(L<=R);
	if (L==R)
		return printf("%d",a[L]),void();
	if (L<R&&a[L]==1){
		printf("1+");
		solve(L+1,R);
		return;
	}
	if (L<R&&a[R]==1){
		solve(L,R-1);
		printf("+1");
		return;
	}
	int v=1;
	For(i,L,R)
		v=min(v*a[i],INF);
	if (v>=INF){
		For(i,L,R-1)
			printf("%d*",a[i]);
		printf("%d",a[R]);
		return;
	}
	cnt=0;
	For(i,L,R)
		if (a[i]>1)
			p[++cnt]=i;
	p[cnt+1]=R+1;
	clr(dp);
	dp[0]=0;
	For(i,0,cnt-1){
		int v=1;
		For(j,i+1,cnt){
			v*=a[p[j]];
			int val=dp[i]+v+p[j+1]-p[j]-1;
			if (val>dp[j]){
				dp[j]=val;
				pre[j]=i;
			}
		}
	}
	for (int i=cnt;i;i=pre[i]){
		For(j,p[pre[i]+1],p[i]-1)
			vv[j]=1;
	}
	For(i,L,R-1)
		printf("%d%c",a[i],vv[i]==0?'+':'*');
	printf("%d",a[R]);
}
void so1(int L,int R){
	if (L==R)
		return printf("%d",a[L]),void();
	if (L<R&&a[L]==0){
		printf("0+");
		so1(L+1,R);
		return;
	}
	if (L<R&&a[R]==0){
		so1(L,R-1);
		printf("+0");
		return;
	}
	vi p;
	For(i,L,R)
		if (!a[i])
			p.pb(i);
	if (p.empty())
		solve(L,R);
	else {
		solve(L,p[0]-1);
		printf("+0+");
		For(i,0,(int)p.size()-2){
			if (p[i]+1<=p[i+1]-1){
				solve(p[i]+1,p[i+1]-1);
				printf("+0+");
			}
			else {
				printf("0+");
			}
		}
		solve(p.back()+1,R);
	}
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	string s,t;
	cin>>s;
	int flag=0;
	for (auto i : s)
		if (i!='-')
			t+=i;
		else
			flag=1;
	if (s.size()==1){
		For(i,1,n)
			printf("%d%c",a[i],i==n?'\n':s[0]);
		return 0;
	}
	if (t.size()==1&&(t=="+"||!flag||(t=="*"&&flag&&a[1]==0))){
		For(i,1,n)
			printf("%d%c",a[i],i==n?'\n':t[0]);
		return 0;
	}
	if (t.size()==1&&flag){
		assert(t=="*");
		int L=1;
		while (L<=n&&a[L]>0){
			if (L>1)
				putchar('*');
			printf("%d",a[L++]);
		}
		if (L>n)
			return 0;
		For(i,L,n)
			printf("%c%d",i==L?'-':'*',a[i]);
		return 0;
	}
	so1(1,n);
	puts("");
	return 0;
}