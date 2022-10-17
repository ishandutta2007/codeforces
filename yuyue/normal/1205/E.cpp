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
const int M=2e5+10,mod=1e9+7;
int phi[M];
bool p[M];
int P[M],cnt;
void sieve(int n){
	F(i,2,n){
		if (!p[i]){
			P[++cnt]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=cnt&&P[j]*i<=n;j++){
			p[i*P[j]]=1;
			if (i%P[j]==0){
				phi[i*P[j]]=phi[i]*P[j];
				break;
			}
			phi[i*P[j]]=phi[i]*phi[P[j]];
		}
	}
}
int n,m;
LL pw[M],sp[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int main(){
	sieve(111111);
	n=read(); m=read();
	pw[0]=1; n--;
	LL sm=0;
	F(i,1,111111) pw[i]=pw[i-1]*m%mod,sp[i]=(sp[i-1]+phi[i])%mod;
	F(i,1,n) sm=(sm+pw[i])%mod;
	LL ipn=fast(pw[n+1],mod-2);
	LL ans=sm*sm%mod*ipn%mod;
	F(i,1,n){
		ans=(ans+pw[i]*sp[n/i+1])%mod;
	}
	LL del=0;
	F(i,1,n){
		LL tmp=pw[i];
		F(j,2,n/i+1){
			tmp=tmp*pw[i]%mod;
			del=(del+1ll*(mod-tmp)*phi[j])%mod;
		}
	}
	del=del*ipn%mod;
	ans=(ans+del)%mod;
	ans=ans*ipn%mod;
	cout<<ans<<"\n";
	return 0; 
}