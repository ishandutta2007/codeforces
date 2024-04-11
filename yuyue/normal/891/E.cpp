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
const int M=5050,mod=1e9+7;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int n,k;
LL f[M];
int a[M];
int main(){
	n=read(); k=read();
	f[0]=1;
	LL o=1;
	F(i,1,n){
		a[i]=read();
		o=o*a[i]%mod;
		DF(j,i-1,0){
			f[j+1]=(f[j+1]-f[j]+mod)%mod;
			f[j]=f[j]*a[i]%mod;
		}
	}
	LL t=fast(fast(n,k),mod-2),ans=0,b=1;
	F(i,0,min(k,n)){
//		cout<<f[i]<<"  nj\n";
		ans=(ans+f[i]*fast(n,k-i)%mod*b)%mod;
		b=b*(k-i)%mod;
	}
	cout<<(o-ans*t%mod+mod)%mod<<"\n";
    return 0;
}