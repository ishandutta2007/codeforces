#include<bits/stdc++.h>
#define maxn 251000
#define mod 1000000007
using namespace std;
int a[maxn],n,c,s[maxn],ans;
int qpow(int a,int b){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),c+=a[i];
	int mx=*max_element(a+1,a+n+1);
	s[0]=0,s[1]=1ll*(c-1)*(c-1)%mod*qpow(c,mod-2)%mod;
	for(int i=2;i<=mx;++i)
		s[i]=(2ll*s[i-1]-1ll*s[i-2]-1ll*(c-1)*qpow(c-i+1,mod-2))%mod;
	for(int i=1;i<=n;++i)ans=(ans+s[a[i]])%mod;
	printf("%d",(ans+mod)%mod);
}