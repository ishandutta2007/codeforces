#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
//const int mod=;
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
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=1005;
int n;
int x[N],y[N];
vi a;
int main(){
	n=read();
	For(i,1,n)
		x[i]=read(),y[i]=read();
	Fod(i,n,1)
		x[i]-=x[1],y[i]-=y[1];
	For(d,0,29){
		int c0=0,c1=0;
		int md=1<<d;
		For(i,1,n)
			if ((x[i]+y[i])%md==0)
				c0++;
			else
				c1++;
		if (c0&&c1){
			For(i,1,n)
				if ((x[i]+y[i])%md==0)
					a.pb(i);
			printf("%d\n",(int)a.size());
			for (auto i : a)
				printf("%d ",i);
			puts("");
			return 0;
		}
		c0=0,c1=0;
		For(i,1,n)
			if (x[i]%md==0)
				c0++;
			else
				c1++;
		if (c0&&c1){
			For(i,1,n)
				if (x[i]%md==0)
					a.pb(i);
			printf("%d\n",(int)a.size());
			for (auto i : a)
				printf("%d ",i);
			puts("");
			return 0;
		}
	}
	return 0;
}