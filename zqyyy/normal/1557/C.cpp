#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;	
}
int n,K,pw[N];
inline void work(){
	n=read(),K=read();
	int ans=0,sum=1;
	for(int i=K;i;i--){
		if(n%2==0)ans=(ans+1ll*sum*qpow(pw[i-1],n))%mod;
		sum=1ll*sum*(pw[n-1]+(n%2==1)-(n%2==0))%mod;
	}
	printf("%d\n",(ans+sum)%mod);
}
int main(){
	for(int i=pw[0]=1;i<=2e5;i++)pw[i]=(pw[i-1]<<1)%mod;
	int T=read();
	while(T--)work();
	return 0;	
}