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
const int N=300005;
int n,q,rt;
char s[N];
int id[N],mat[N];
LL c[N];
int fa[N],cs[N],in[N],out[N],sid[N];
vi son[N];
vi ss[N];
void add(int x,LL v){
	for (;x<N;x+=x&-x)
		c[x]+=v;
}
LL query(int x){
	LL ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
void add(vi &c,int x,int v){
	for (;x<c.size();x+=x&-x)
		c[x]+=v;
}
int query(vi &c,int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int Time=0;
void dfs(int x){
	Time++;
	in[x]=Time;
	ss[x].resize(son[x].size()+1);
	for (auto y : son[x]){
		cs[x]++;
		sid[y]=cs[x];
		add(ss[x],cs[x],1);
		dfs(y);
	}
	add(in[x],(LL)cs[x]*(cs[x]+1)/2);
	out[x]=Time;
}
int main(){
	n=read(),q=read();
	rt=n+1;
	scanf("%s",s+1);
	vi st;
	For(i,1,n){
		if (s[i]=='('){
			st.pb(i);
		} else {
			if (st.empty())
				continue;
			int j=st.back();
			mat[i]=j;
			st.pop_back();
			fa[j]=st.empty()?rt:st.back();
			son[fa[j]].pb(j);
		}
	}
	for (auto i : st){
		fa[i]=rt;
		son[rt].pb(i);
	}
	dfs(rt);
	while (q--){
		int type=read(),L=read(),R=read();
		int x=fa[L];
		if (type==1){
			add(in[x],-cs[x]);
			cs[x]--;
			add(ss[x],sid[L],-1);
		} else {
			LL ans=0;
			ans+=query(out[mat[R]])-query(in[L]-1);
			int tmp=query(ss[x],sid[mat[R]])-query(ss[x],sid[L]-1);
			ans+=(LL)tmp*(tmp+1)/2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}