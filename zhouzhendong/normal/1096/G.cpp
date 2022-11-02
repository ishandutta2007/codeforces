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
const int mod=998244353;
int Pow(int x,int y){
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
int md(int x){
	return (x%mod+mod)%mod;
}
const int N=1e6+5+20;
int n,k;
int inv[N];
int f[N],df[N],g[N],dg[N];
int main(){
	n=read()/2,k=read();
	while (k--)
		f[read()]=1;
	k=n,n=10;
	inv[1]=1;
	For(i,2,n*k)
		inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
	int p=0;
	while (!f[p])
		p++;
	For(i,0,n-1-p)
		swap(f[i],f[i+p]);
	For(i,1,n-1)
		df[i-1]=(LL)f[i]*i%mod;
	int invf0=Pow(f[0],mod-2);
	g[0]=Pow(f[0],mod-2);
	For(m,0,n*k-1){
		int tmp=0;
		For(i,0,n-1)
			if (m-i>=0)
				Add(tmp,(LL)df[i]*g[m-i]%mod);
		tmp=(LL)tmp*k%mod;
		For(i,0,n-1)
			if (i!=0&&m-i>=0)
				Del(tmp,(LL)f[i]*dg[m-i]%mod);
		tmp=(LL)tmp*invf0%mod;
		dg[m]=tmp;
		g[m+1]=(LL)dg[m]*inv[m+1]%mod;
	}
	//real g = g * (x ^ {pk})
	int ans=0;
//	outarr(f,0,n-1);
//	outarr(df,0,n-1);
//	outarr(g,0,n*k-1);
//	outarr(dg,0,n*k-1);
	For(i,0,n*k)
		Add(ans,(LL)g[i]*g[i]%mod);
	cout<<ans<<endl;
	return 0;
}