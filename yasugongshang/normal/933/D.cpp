#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
int n;
ll sum4[N],sum2[N],sum6[N],ans;
inline ll ksm(ll a,int b){
	a%=mod; ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
signed main(){
	cin>>n;
	for(ll i=1;i<N;i++){
  		sum2[i]=(sum2[i-1]+ksm(i,2))%mod;
  		sum4[i]=(sum4[i-1]+ksm(i,4))%mod;
		sum6[i]=(sum6[i-1]+ksm(i,6))%mod;
	}
	ll jb=n%mod,meiju=sqrt(n);
	/*for(int i=0;i<=meiju;i++){
		for(int j=1;j<=meiju;j++)if(i*i+j*j<=n){
			int x=i,y=j;
			ans+=n*(n+1)*(n+2)+2*ksm(x,6)+6*ksm(x,4)*ksm(y,2)+6*ksm(x,2)*ksm(y,4)+2*ksm(y,6)-
			3*(n+2)*(ksm(x,4)+2*ksm(x,2)*ksm(y,2)+ksm(y,4))+(3*n+4)*(x*x+y*y);
			ans%=mod;
		}
	}*/
	for(ll x=0;x*x<=n;x++){
		ll y=sqrt(n-x*x); ll zs=x%mod;
		ans+=y*jb%mod*(jb+1)%mod*(jb+2)%mod+2*y%mod*ksm(zs,6)%mod+6*ksm(zs,4)%mod*sum2[y]%mod+6*ksm(zs,2)%mod*sum4[y]%mod+2*sum6[y];
		ans+=-3*(ksm(zs,4)*y+2*zs*zs%mod*sum2[y]+sum4[y])%mod*(jb+2)%mod+(3*jb+4)*(zs*zs%mod*y%mod+sum2[y])%mod;
		ans%=mod;
		//cout<<ans<<" "<<y<<endl;
	}
	ans=ans*ksm(6,mod-2)%mod;
	ans=ans*4%mod;
	ans=(ans+jb*(jb+1)%mod*(jb+2)%mod*ksm(6,mod-2)+mod)%mod;
	cout<<(ans+mod)%mod<<endl;
}