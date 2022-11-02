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
const int N=200005;
int n;
int a[N];
namespace so1{
	int cnt[N];
	int buc[N];
	int mx;
	int main(){
		clr(buc);
		clr(cnt);
		buc[0]=N;
		mx=0;
		int res=0;
		For(i,1,n){
			buc[cnt[a[i]]]--;
			cnt[a[i]]++;
			buc[cnt[a[i]]]++;
			mx+=2;
			while (!buc[mx])
				mx--;
			if (buc[mx]>1){
				ckmax(res,i);
			}
		}
		return res;
	}
}
vi p[N];
namespace so2{
	map <int,int> v;
	map <int,int> lp;
	int main(vi &a,vi b){
//		outtag();
		v.clear(),lp.clear();
		int ans=0;
		int mx=0,s=0;
		int i=0,j=0;
		int sa=a.size(),sb=b.size();
		lp[0]=0;
		while (i<sa||j<sb){
			if (i==sa||(j<sb&&b[j]<a[i])){
				int now=b[j++];
				int rb=min(i<sa?a[i]:n+1,j<sb?b[j]:n+1);
				s--;
				if (lp.count(s))
					ckmax(ans,rb-lp[s]-1);
				else {
					auto it=v.upper_bound(s);
					if (it!=v.begin()){
						it=prev(it);
						ckmax(ans,rb-a[it->se+s-it->fi]-1);
					}
					if (s<0)
						lp[s]=now;
				}
			}
			else {
				if (s+1<=mx){
					int now=a[i++];
					int rb=min(i<sa?a[i]:n+1,j<sb?b[j]:n+1);
					s++;
					if (lp.count(s))
						ckmax(ans,rb-lp[s]-1);
					else {
						auto it=v.upper_bound(s);
						outvals(a,b);outvals(s);
						assert(it!=v.begin());
						it=prev(it);
						ckmax(ans,rb-a[it->se+s-it->fi]-1);
						if (s<0)
							lp[s]=now;
					}
				}
				else if (j==sb)
					break;
				else {
					int ii=lower_bound(a.begin(),a.end(),b[j])-a.begin();
					lp[s+1]=a[i];
					v[s+1]=i;
					s+=ii-i;
					mx=s;
					i=ii;
				}
			}
			outvals(s,ans);
			outval(v);outval(lp);
		}
		return ans;
	}
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	int flag=0;
	For(i,1,n-1)
		flag|=a[i]!=a[i+1];
	if (!flag)
		return puts("0"),0;
	int ans=0;
	For(i,0,1){
		ckmax(ans,so1::main());
		reverse(a+1,a+n+1);
	}
	For(i,1,n)
		p[a[i]].pb(i);
	int mx=-1;
	For(i,1,n)
		ckmax(mx,(int)p[i].size());
	int v=0;
	For(i,1,n)
		if ((int)p[i].size()==mx)
			v=i;
	For(i,1,n)
		if (i!=v){
			ckmax(ans,so2::main(p[v],p[i]));
		}
	cout<<ans<<endl;
	return 0;
}
/*
10
1 1 1 2 1 2 1 1 1 1
*/