#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=1000005,mod=1000000007;
inline int ksm(int a,int b){
	int t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
int n,fac[N],a[N],mx,ans,fff[N],ycl[N];
inline int p(int n,int m){
	return (ll)fac[n]*fff[n-m]%mod;
}
int main(){
	n=read(); fff[0]=fac[0]=1;
	for(int i=1;i<=n+1;i++){if(i<=n)mx=max(mx,a[i]=read()); fac[i]=(ll)fac[i-1]*i%mod; fff[i]=ksm(fac[i],mod-2); ycl[i]=((ll)ycl[i-1]*i+1)%mod;}
	
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++)if(a[i]!=mx){
		int t=lower_bound(&a[1],&a[n+1],a[i])-a-1;
		ans=(ans+(ll)a[i]*fac[n]%mod*ksm((ll)(n-t)*fac[t]%mod,mod-2)%mod*fac[t])%mod;
		//cout<<a[i]<<" "<<p(n,t+1)<<" "<<ksm(t+1,mod-2)<<" "<<fac[t]<<endl;
		/*for(int j=0;j<=t;j++){
			ans=(ans+(ll)a[i]*p(t,j)%mod*fac[n-j-1])%mod;
			//(n-j+1)!/(t-j)!
		}*/
	}
	cout<<ans<<endl;
}
//for(int i=1;i<=n;i++)ans+=p(i-1,x)*
//for(int i=1;i<=n;i++)ans+=p!
//(n-j)!/(t-j)!
//n!/t!+(n-1)!/(t-1)!