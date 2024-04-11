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
typedef unsigned long long ull;
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
const int N=300005;
int n,k;
int a[N];
char s[N];
void solve(){
	n=read(),k=read();
	scanf("%s",s+1);
	For(i,0,n)
		a[i]=-1;
	For(i,1,k){
		int t0=0,t1=0;
		for (int j=i;j<=n;j+=k){
			if (s[j]=='0')
				t0=1;
			if (s[j]=='1')
				t1=1;
		}
		if (t0&&t1)
			return puts("NO"),void();
		for (int j=i;j<=n;j+=k)
			if (t0)
				a[j]=0;
			else if (t1)
				a[j]=1;
	}
	int c0=0,c1=0;
	For(i,1,k){
		if (a[i]==0)
			c0++;
		if (a[i]==1)
			c1++;
	}
//	outarr(a,1,n);
	if (c0<=k/2&&c1<=k/2)
		puts("YES");
	else
		puts("NO");
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}