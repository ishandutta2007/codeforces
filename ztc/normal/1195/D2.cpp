#include<stdio.h>
#include<algorithm>
#define mod 998244353ll
long long a[100002],b[100002],cnt[11],n,p[20]={0,1},ans=0,dig[12],g[12];
int main(){
	scanf("%lld",&n);for(int i=2;i<=19;i++)p[i]=p[i-1]*10ll;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	long long k=10,top=1;
	for(int i=1;i<=n;i++){
		while(a[i]>=k)k*=10,top++;
		cnt[top]++;
	}
	for(int i=1;i<=n;i++){
		long long t=0,q=a[i];
		while(q){dig[++t]=q%10;q/=10;}g[0]=a[i];
		for(int j=1;j<=t;j++){g[j]=0;
			for(int k=1;k<=t;k++){
				g[j]+=dig[k]*p[k<=j?k*2-1:j+k];
			}g[j]%=mod;
		}
		for(int j=1;j<=10;j++){
			if(j<=t)ans=(ans+(g[j]+g[j-1]*10ll)*cnt[j])%mod;
			else ans=(ans+g[t]*11ll*cnt[j])%mod;
		}
	}printf("%lld ",ans);
}