#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
const int mod=1000000007;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	#ifdef LOCAL
		freopen("961G.txt","r",stdin);
	#endif
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if NEG
int readint(){
	bool isneg;
	int val=0;
	for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
	bufpos+=(isneg=buf[bufpos]=='-');
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return isneg?-val:val;
}
#else
int readint(){
	int val=0;
	for(;!isdigit(buf[bufpos]);bufpos++);
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return val;
}
#endif
char readchar(){
	for(;isspace(buf[bufpos]);bufpos++);
	return buf[bufpos++];
}
int readstr(char* s){
	int cur=0;
	for(;isspace(buf[bufpos]);bufpos++);
	for(;!isspace(buf[bufpos]);bufpos++)
		s[cur++]=buf[bufpos];
	s[cur]='\0';
	return cur;
}
ll power(ll x,ll y){
	x%=mod;
	ll ans=1;
	while(y){
		if (y&1)
			ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
ll fac[200002],invf[200002];
ll c(int n,int m){
	if (n<m)
		return 0;
	return fac[n]*invf[m]%mod*invf[n-m]%mod;
}
ll s(int n,int m){
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll now=power(i,n)*c(m,i)%mod;
		if ((m-i)%2)
			ans-=now;
		else ans+=now;
	}
	return ans%mod*invf[m]%mod;
}
int main(){
	init();
	int n=readint(),k=readint();
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=readint();
	sum%=mod;
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	invf[n]=power(fac[n],mod-2);
	for(int i=n;i;i--)
		invf[i-1]=invf[i]*i%mod;
	ll ans=(s(n,k)+(n-1)*s(n-1,k))%mod*sum%mod;
	printf("%lld",(ans+mod)%mod);
}