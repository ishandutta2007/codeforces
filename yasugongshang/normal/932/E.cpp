#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=5005,mod=1000000007,C=3;
int n,k,c[N][N],ycl[N],ni[N],arr[N],jb[N],fac[N];
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int qiu(int n,int x){
	int ans=0; 
	static int f[N],g[N]; g[n+1]=1;
	for(int i=0;i<=n;i++)f[i]=i?(ll)f[i-1]*(x-i)%mod:x;
	for(int i=n;i>=0;i--)g[i]=(ll)g[i+1]*(x-i)%mod;
	for(int i=0;i<=n;i++){
		ll sum=(ll)(i?f[i-1]:1)*g[i+1]%mod*ksm((ll)fac[i]*fac[n-i]%mod,mod-2)%mod; if((n-i)&1)sum*=-1;
		ans=(ans+sum*arr[i])%mod;
		//cout<<i<<" "<<f[i-1]<<" "<<g[i+1]<<" "<<sum<<endl;
	}
	return (ans+mod)%mod;
}
int main(){
	n=read(); k=read();
	for(int i=0;i<=k+C;i++){
		c[i][0]=1; ycl[i]=ksm(i,k); ni[i]=ksm(i,mod-2); jb[i]=ksm((mod+1)/2,i); fac[i]=i?(ll)fac[i-1]*i%mod:1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=0;i<=k+C;i++){
		for(int j=0;j<=i;j++)arr[i]=(arr[i]+(ll)c[i][j]*ycl[j])%mod;
		arr[i]=(ll)arr[i]*jb[i]%mod;
		//cout<<arr[i]<<" ";
	}
	writeln((ll)qiu(k+C,n)*ksm(2,n)%mod);
}
/*
c(n,i)*i^k
*/