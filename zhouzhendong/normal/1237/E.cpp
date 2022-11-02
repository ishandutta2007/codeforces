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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=1000005*2;
int n;
int Fac[N],Inv[N];
void prework(){
	Fac[0]=1;
	For(i,1,n)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	Fod(i,n,1)
		Inv[i-1]=(LL)Inv[i]*i%mod;
}
int C(int n,int m){
	if (m>n||m<0)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int A(int n,int m){
	if (m>n||m<0)
		return 0;
	return (LL)Fac[n]*Inv[n-m]%mod;
}
int d,leaf;
int cnt=0;
int vis[N][2];
int ndl[N],ndr[N],sz[N];
int ls(int x){
	return x*2>d?0:x*2;
}
int rs(int x){
	return x*2>d?0:x*2+1;
}
void gg(){
	puts("0");
	exit(0);
}
void dfs(int x){
	sz[x]=1;
	ndl[x]=ndr[x]=x;
	if (x*2>d)
		return;
	dfs(ls(x));
	dfs(rs(x));
	ndl[x]=ndl[ls(x)];
	ndr[x]=ndr[rs(x)];
	if (sz[rs(ls(x))]%2!=0){
		int k=ls(x);
		if (!rs(k)){
			if (vis[k][1])
				gg();
			vis[k][1]=1;
			sz[k]++;
		}
		else {
			k=ndr[rs(k)];
			if (vis[k][0])outtag(0),
				gg();
			vis[k][0]=1;
			sz[ls(x)]++;
		}
	}
	if (sz[ls(rs(x))]%2==0){
		int k=rs(x);
		if (!ls(k)){
			if (vis[k][0])outtag(1),
				gg();
			vis[k][0]=1;
			sz[k]++;
		}
		else {
			k=ndl[ls(k)];
			if (vis[k][1])outtag(2),
				gg();
			vis[k][1]=1;
			sz[rs(x)]++;
		}
	}
	sz[x]=sz[ls(x)]+sz[rs(x)]+1;
}
int main(){
	n=read();
//	if (n==1)
//		return puts("1"),0;
	prework();
	d=1;
	while (d*2+1<=n)
		d=d*2+1;
	leaf=(d+1)/2;
	dfs(1);
	outval(sz[1]);
	if (sz[1]>n)outtag(4),
		gg();
	int t=n-sz[1];
	assert(!vis[d][1]);
	if (t&1){
		t--;
		vis[d][1]=1;
	}
	cout<<(t>0?0:1)<<endl;
//	int p=0;
//	For(i,d/2+1,d)
//		if (!vis[i][0]&&!vis[i][1])
//			p++;
//	outval(p),outval(t);
//	cout<<C(p,t/2)<<endl;
	return 0;
}