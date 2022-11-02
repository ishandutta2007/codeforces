#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define int long long
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
const int N=1000005,mod=998244353;
int fac[N],ni[N],f[N],n;
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
inline int c(int a,int b){
	return (ll)fac[a]*ni[b]%mod*ni[a-b]%mod;
}
signed main(){
	cin>>n;
	fac[0]=ni[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(ll)fac[i-1]*i%mod; ni[i]=ksm(fac[i],mod-2);
	}
	int t=ksm(3,n)-3,ans2=0; 
	int ans1=(ksm(3,n*n)-ksm(t,n)+mod)%mod; 
	for(int i=1;i<=n;i++){
		int t=ksm(3,n-i)-1;
		f[i]=3*c(n,i)*(ksm(3,n*(n-i))-ksm(t,n))%mod;
	}
	for(int i=n;i;i--){
		ans2=(ans2+f[i]*(i%2==1?1:-1))%mod; 
	}
	//cout<<ans1<<" "<<ans2<<" "<<f[1]<<" "<<f[2]<<endl;
	cout<<((ans1*2-ans2)%mod+mod)%mod<<endl;
}
/*
2*3*9
*2-

 
*/