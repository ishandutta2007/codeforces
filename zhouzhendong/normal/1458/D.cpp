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
const int N=500005;
int n;
char a[N];
int pre[N];
int vis[1<<18];
int ans;
void dfs(int x){
	if (vis[x])
		return;
	vis[x]=1;
	ckmin(ans,x);
//	outval(x);
	For(i,0,n-1){
		int c0=0,c1=0;
		For(j,i,n-1){
			if (x>>j&1)
				c1++;
			else
				c0++;
			if (c0==c1){
				int y=x;
				For(k,i,j)
					y^=1<<k;
				for (int l=i,r=j;l<r;l++,r--){
					int v0=y>>l&1,v1=y>>r&1;
					y^=v0<<l;
					y^=v1<<r;
					y^=v0<<r;
					y^=v1<<l;
				}
				dfs(y);
			}
		}
	}
}
void bf(){
	clr(vis);
	int v=0;
	For(i,1,n)
		v|=(a[i]-'0')<<(i-1);
	ans=v;
	dfs(v);
	For(i,0,n-1)
		putchar(ans>>i&1?'1':'0');
	puts("");
}
void solve(){
	scanf("%s",a+1);
	n=strlen(a+1);
#ifdef zzd
	bf();
#endif
	unordered_map <int,int> cnt;
	int s=0,mx=-1;
	For(i,1,n){
		ckmax(mx,s);
		s+=a[i]=='1'?1:-1;
		pre[i]=s;
		cnt[min(pre[i],pre[i-1])]++;
	}
	int now=0;
//	outval(cnt);
	For(i,1,n){
		if (i==n){
			if (cnt[now])
				a[i]='1';
			else
				assert(cnt[now-1]),a[i]='0';
			break;
		}
		if (cnt[now-1]>0&&(now-1!=s||cnt[now-1]+cnt[now-2]>2)&&(cnt[now-1]>1||!cnt[now])){
			a[i]='0';
			now--;
			assert(cnt[now]>0);
			cnt[now]--;
		}
		else {
			a[i]='1';
			assert(cnt[now]>0);
			cnt[now]--;
			now++;
		}
//		outval(now);
	}
	For(i,1,n)
		putchar(a[i]);
	puts("");
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}