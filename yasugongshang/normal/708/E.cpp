#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005,M=1505,mod=1e9+7;
ll f[N],fp[N],gp[N],fac[N],ni[N];
ll DP[M],dp[M][M],F[N];
ll c(int a,int b){
	return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	int n=read(),m=read();
	ll a=read(),b=read();
	ll p=a*ksm(b,mod-2)%mod;
	int k=read();
	For(i,fp[0]=gp[0]=fac[0]=ni[0]=1,k){
		fac[i]=fac[i-1]*i%mod;
		ni[i]=ksm(fac[i],mod-2);
		fp[i]=fp[i-1]*p%mod;
		gp[i]=gp[i-1]*(mod+1-p)%mod;
	}
	For(i,0,k)f[i]=c(k,i)*fp[i]%mod*gp[k-i]%mod;
	F[0]=f[0]; For(i,1,m)F[i]=(F[i-1]+f[i])%mod;
	//For(i,0,k)cout<<f[i]<<" fjzzq"<<endl;
	//cout<<F[1]<<" "<<F[2]<<" "<<endl;
	DP[0]=1;
	For(i,1,n){
		ll sum=DP[i-1],sss=0;
		Rep(j,m-1,1){
			sum=(sum+dp[i-1][j])%mod;
			sss=(sss-dp[i-1][j]*F[m-j-1])%mod;
			dp[i][j]=(sum*F[m-j-1]+sss)%mod;
		}
		DP[i]=(F[m-1]*sum+sss)%mod*f[0]%mod;
		//cout<<sum<<" "<<sss<<" "<<F[m-1]<<endl;
		sum=0;
		For(j,1,m-1){
			sum=(sum+dp[i-1][m-j])%mod;
			dp[i][j]=-(dp[i][j]+sum*F[m-j-1])%mod*f[j]%mod;
			DP[i]=(DP[i]-dp[i][j])%mod;
		}
		
		//<<i<<" "<<DP[i]<<endl;
		///For(j,1,m-1)wri(dp[i][j]); puts("");
	}
	cout<<(DP[n]+mod)%mod<<endl;
}