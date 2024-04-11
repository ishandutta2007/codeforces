#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}const int M=1e6+10,mod=1e9+7;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}

LL fac[M],inv[M],iv[M];
void init(int n){
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
	iv[1]=1;
	F(i,2,n) iv[i]=(mod-mod/i)*iv[mod%i]%mod;
}
LL C(int x,int y){
	if (y<0 || x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,a[M];
void work(){
	n=read();
	LL ans=0;
	F(i,0,n){
		a[i]=read();
		if (a[i]) ans=(ans+C(i+a[i],i+1))%mod;
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=1; init(1000000);
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
1 2
8
1
4
*/