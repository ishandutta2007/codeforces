#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3030,mod=998244353;
LL f[M][M],g[M][M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
const int N=3e5+10;
int n,m,a[N],b[N],s[2];
int main(){
	n=read(); m=read();
	LL sm=0;
	F(i,1,n){
		a[i]=read();
	} 
	F(i,1,n){
		b[i]=read();
		s[a[i]]+=b[i];
		sm+=b[i];	
	}
	F(i,0,m) f[i][m-i]=g[i][m-i]=1;
	DF(i,m,0){
		DF(j,m-i-1,0){
			LL wei=sm+i-j;
			LL iv=fast(wei,mod-2);
			f[i][j]=((s[1]+i+1)*f[i+1][j]+(s[0]-j)*f[i][j+1])%mod*iv%mod;
			g[i][j]=((s[0]-j-1)*g[i][j+1]+(s[1]+i)*g[i+1][j])%mod*iv%mod;
		}
	}
	F(i,1,n){
		cout<<(a[i] ? f[0][0] : g[0][0])*b[i]%mod<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/