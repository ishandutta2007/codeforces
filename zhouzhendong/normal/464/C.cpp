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
const int mod=1e9+7;
int Pow(int x,LL y){
	y=(y%(mod-1)+(mod-1))%(mod-1);
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
int md(LL x){
	return (x%mod+mod)%mod;
}
const int N=1000005;
int n,m;
char s[N];
int a[N];
int id[10],cnt=0;
vi e[N];
int v10[N],l10[N],f[N];
vi r[N];
int dd[N];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	m=read();
	For(i,0,9)
		id[i]=++cnt;
	For(i,1,n)
		a[i]=id[s[i]-'0'];
	while (m--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int v=s[1]-'0';
		int i=id[v];
		id[v]=++cnt;
		For(j,4,len){
			e[i].pb(id[s[j]-'0']);
			r[id[s[j]-'0']].pb(i);
			dd[i]++;
		}
	}
	queue <int> Q;
	For(i,1,cnt)
		if (!dd[i])
			Q.push(i);
	For(i,0,9){
		f[id[i]]=1;
		v10[id[i]]=i;
		l10[id[i]]=10;
	}
	while (!Q.empty()){
		int i=Q.front();
		Q.pop();
		for (auto j : r[i])
			if (!--dd[j])
				Q.push(j);
		if (f[i])
			continue;
		l10[i]=1;
		v10[i]=0;
		for (auto j : e[i]){
			v10[i]=((LL)v10[i]*l10[j]+v10[j])%mod;
			l10[i]=(LL)l10[i]*l10[j]%mod;
		}
	}
	outarr(e,1,cnt);
	outarr(f,1,cnt);
	outarr(v10,1,cnt);
	outarr(l10,1,cnt);
	outarr(id,0,9);
	int ans=0;
	For(i,1,n){
		ans=((LL)ans*l10[a[i]]+v10[a[i]])%mod;
	}
	cout<<ans<<endl;
}
int main(){
	int T=1;
	while (T--)
		solve();
	return 0;
}