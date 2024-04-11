#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100100
using namespace std;
int sz[maxn],n,ans=0;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		if(x!=-1)sz[x]++;
	}
	for(int i=1;i<=n;++i)
		ans=(ans+qpow(2,sz[i])-1)%mod;
	ans=(qpow(2,n-1)-1-ans)%mod;
	ans=(ans%mod+mod)%mod;
	printf("%d",ans);
}