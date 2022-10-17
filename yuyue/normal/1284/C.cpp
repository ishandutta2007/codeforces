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
const int M=4e5+10;
int mod,n;
LL f[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int main(){
	n=read(); mod=read();
    
	f[0]=1; F(i,1,n) f[i]=f[i-1]*i%mod;
    LL ans=0;
	F(i,1,n){
    	ans=(ans+(n-i+1)%mod*f[i]%mod*f[n-i+1])%mod;
//    	cout<<
//    	cout<<(n-i)*(i-1)%mod*f[i]%mod*f[n-i+1]<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}