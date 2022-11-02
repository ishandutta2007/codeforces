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
const int N=3605;
int Fac[N],Inv[N];
void prework(int n){
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
int n,m,q;
int dp[N][N];
int vr[N],vc[N];
vi solve(int *a,int n){
	vi now(1,0);
	For(i,1,n)
		if (a[i]==0)
			now.back()++;
		else
			now.pb(0);
	sort(now.begin(),now.end());
	reverse(now.begin(),now.end());
	while (!now.empty()&&now.back()==0)
		now.pop_back();
	dp[0][0]=dp[1][0]=1;
	For(i,2,n){
		dp[i][0]=1;
		For(j,1,n){
			dp[i][j]=Add(dp[i-1][j]+dp[i-2][j-1]);
		}
	}
	vi res(n+1,0);
	res[0]=1;
	for (auto i : now){
		vi now(n+1,0);
		For(j,0,n){
			int v=res[j];
			if (!v)
				continue;
			For(k,0,i){
				int u=dp[i][k];
				if (!u)
					continue;
				Add(now[j+k],(LL)v*u%mod);
			}
		}
		swap(res,now);
	}
	return res;
}
int main(){
	n=read(),m=read(),q=read()*2;
	prework(max(n,m));
	int rr=n,cc=m;
	while (q--){
		int x=read(),y=read();
		if (!vr[x])
			rr--;
		if (!vc[y])
			cc--;
		vr[x]=1,vc[y]=1;
	}
	vi a=solve(vr,n);
	vi b=solve(vc,m);
//	outarr(a,0,n);
//	outarr(b,0,m);
//	outval(rr),outval(cc);
	int ans=0;
	For(i,0,n)
		For(j,0,m){
			int t=(LL)a[i]*b[j]%mod;
			if (!t)
				continue;
			Add(ans,(LL)t*Fac[i]%mod*Fac[j]%mod*C(rr-2*i,j)%mod*C(cc-2*j,i)%mod);
//			outval(i),outval(j),outval(ans);
		}
	cout<<ans<<endl;
	return 0;
}