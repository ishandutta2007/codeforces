#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int n,a,b,k;
char S[100100];
int cal(int x,int y){
	if(y<0)return 0;
	if(x==0)return 1;
	if(x==1)return y+1;
	return 1ll*(qpow(x,y+1)-1+mod)*qpow(x-1,mod-2)%mod;
}
int main(){
	scanf("%d%d%d%d%s",&n,&a,&b,&k,S);
	n++;
	int z=1ll*qpow(a,mod-2)*b%mod,ans=0,c=1;
//	int ans2=0;
//	for(int i=0;i<n;++i)ans2=(ans2+1ll*(S[i%k]=='+'?1:mod-1)*c)%mod,c=1ll*c*z%mod;
//	c=1,printf("[%d]",1ll*ans2*qpow(a,n-1)%mod);
	for(int i=0;i<k;++i)ans=(ans+1ll*(S[i]=='+'?1:mod-1)*c)%mod,c=1ll*c*z%mod;
	ans=1ll*cal(qpow(z,k),n/k-1)*ans%mod,c=qpow(z,n/k*k);
	for(int i=0;i<n%k;++i)ans=(ans+1ll*(S[i]=='+'?1:mod-1)*c)%mod,c=1ll*c*z%mod;
	printf("%d",1ll*ans*qpow(a,n-1)%mod);
}