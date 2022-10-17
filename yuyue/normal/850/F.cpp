#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=1e9+7,M=2e5+10;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int n,f[M],a[M];
int main(){
	n=read();
	int m=0; 
	F(i,1,n){
		a[i]=read();
		m+=a[i];
	}
	f[0]=0; LL sum=0;
	F(i,1,100000){
		sum=(sum+fast(m-i+1,mod-2))%mod;
		f[i]=1ll*(m-1)*(m-i)%mod*sum%mod;
	}
	LL ans=0;
	F(i,1,n) ans=(ans+f[a[i]])%mod;
	cout<<ans<<"\n";
    return 0;
}