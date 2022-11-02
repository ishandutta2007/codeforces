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
////	y=(y%(mod-1)+(mod-1))%(mod-1);
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
const int N=55;
const LL INF=3e15;
int n,k;
LL lb[N],rb[N];
int hb[N];
LL c[N];
LL dp[N][N][N][2][2][2][2];
LL calc(int d,int l,int r,int x,int y,int xx,int yy){
	if (l==0||r==n+1)
		return 0;
	LL lv=x==0?lb[l]:rb[l];
	LL rv=y==0?lb[r]:rb[r];
	return c[d]*(((lv^rv)>>d&1)^xx^yy);
}
int main(){
	n=read(),k=read();
	For(i,1,n){
		lb[i]=read(),rb[i]=read();
		hb[i]=63-__builtin_clzll(lb[i]^rb[i]);
	}
	For(i,0,k-1)
		c[i]=read();
	memset(dp,63,sizeof dp);
	For(i,0,n)
		For(x,0,1)
			For(y,0,1)
				dp[k][i][i+1][x][y][0][0]=0;
	Fod(d,k-1,0){
		Fod(l,n,0) For(r,l+1,n+1)
			For(x,0,1) For(y,0,1) For(xx,0,1) For(yy,0,1){
				ckmin(dp[d][l][r][x][y][xx][yy],dp[d+1][l][r][x][y][0][0]+calc(d,l,r,x,y,xx,yy));
				For(mid,l+1,r-1){
					if (hb[mid]>d){
						if (~lb[mid]>>d&1)
							ckmin(dp[d][l][r][x][y][xx][yy],dp[d][l][mid][x][0][xx][1]+dp[d][mid][r][0][y][1][yy]);
						if (rb[mid]>>d&1)
							ckmin(dp[d][l][r][x][y][xx][yy],dp[d][l][mid][x][1][xx][1]+dp[d][mid][r][1][y][1][yy]);
					}
					if (!d){
						ckmin(dp[d][l][r][x][y][xx][yy],dp[d][l][mid][x][0][xx][0]+dp[d][mid][r][0][y][0][yy]);
						ckmin(dp[d][l][r][x][y][xx][yy],dp[d][l][mid][x][1][xx][0]+dp[d][mid][r][1][y][0][yy]);
					}
				}
//				if (dp[d][l][r][x][y][xx][yy]<INF)printf("dp[%d][%d][%d][%d][%d][%d][%d] = %lld\n",d,l,r,x,y,xx,yy,dp[d][l][r][x][y][xx][yy]);
			}
	}
	cout<<dp[0][0][n+1][0][0][0][0]<<endl;
	return 0;
}