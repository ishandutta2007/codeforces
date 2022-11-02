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
const int N=100005;
struct op{
	int tp;
	LL a,b;
};
vector <op> res;
int a[60];
set <LL> S;
LL gao(int tp,LL a,LL b){
//	outvals(tp,a,b);
	assert(S.count(a)&&S.count(b));
	res.push_back({tp,a,b});
	LL res=tp?a^b:a+b;
	S.insert(res);
	assert(0<=res&&res<=5000000000000000000LL);
	return res;
}
int Log(LL x){
	int ans=0;
	while (x>1){
		ans++;
		x>>=1;
	}
	return ans;
}
int main(){
	LL x=read();
	srand(time(NULL));
//	for (LL _x=999999;_x>=3;_x-=2){
//	LL x=_x;
//	if (rand()%2333==0)
//		outval(x);
	S.clear();
	res.clear();
	S.insert(x);
	while (x>1){
		vector <LL> v={x};
		while (1){
			int p=(int)v.size()-1;
			while (p>0&&rand()%5!=0)
				p--;
			LL a=v.back(),b=gao(0,a,a),c=gao(0,v[p],b);
			if (Log(b)!=Log(c)){
				v.pb(c);
				continue;
			}
			else {
				LL t=b^c;
				Fod(i,(int)v.size()-1,0){
					if (Log(t)==Log(v[i]*2))
						t^=v[i]*2;
					if (Log(t)==Log(v[i]))
						t^=v[i];
				}
				if (~t&1){
					v.pb(c);
					continue;
				}
				t=gao(1,b,c);
				Fod(i,(int)v.size()-1,0){
					if (Log(t)==Log(v[i]*2))
						t=gao(1,t,v[i]*2);
					if (Log(t)==Log(v[i]))
						t=gao(1,t,v[i]);
				}
				assert(Log(t)<Log(x));
				x=t;
				break;
			}
		}
	}
//	}
	printf("%d\n",(int)res.size());
	for (auto v : res)
		printf("%I64d %c %I64d\n",v.a,"+^"[v.tp],v.b);
//	LL t=gao(0,x,x);
//	a[Log(t)]=t;
//	while (Log(t)>1){
//		if (a[Log(t)]){
//			t^=a[Log(t)];
//			continue;
//		}
//		LL t2=gao(0,t,t),t3=gao(0,t2,t);
//		a[Log(t)]=t;
//		a[Log(t2)]=t2;
//		a[Log(t3)]=t3;
//		if (Log(t2)==Log(t3)){
//			t=gao(1,t2,t3);
//			continue;
//		}
//		else {
//			assert(Log(t3)==Log(t2)+1);
//			t=t3;
//		}
//	}
	return 0;
}