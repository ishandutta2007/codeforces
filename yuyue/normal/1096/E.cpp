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
}
const int mod=998244353;//?????????

LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
const int M=1e4+10;
LL fac[M],inv[M];
void init(int n){
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
}
LL C(int x,int y){
	if (x==y) return 1;
	if (y<0 || x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,m,k;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read(); k=read();
	if (k==0){
		cout<<fast(n,mod-2)<<"\n";
		return 0;
	}	
	init(10000);

	LL iv=fast(C(m+n-1,n-1),mod-2)%mod;
	LL PB=C(m-k+n-1,n-1)*iv%mod;
	LL PAB=0;
	for (int t=1;t*k<=m;t++){
		PAB=(PAB+(t&1 ? 1 : mod-1)*C(n,t)%mod*C(m-t*k+n-1,n-1))%mod;
	}
//	cerr<<PAB<<" hh \n";
	PAB=PAB*iv%mod; PAB=PAB*fast(n,mod-2)%mod; 
	cout<<PAB*fast(PB,mod-2)%mod<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
5000 5000 0
10 30 0

3 6 0
*/