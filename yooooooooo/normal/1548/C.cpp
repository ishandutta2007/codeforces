#include<bits/stdc++.h>
using namespace std;
int n,q,inv3,f[3000005],res[3000005],fac[3000005],invfac[3000005];
const int mod=1e9+7;
int mypow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int M(int x){return x>=mod?x-mod:x;}
int main()
{
	scanf("%d%d",&n,&q);
	fac[0]=1;inv3=mypow(3,mod-2);
	//printf("#%d\n",inv3);
	for(int i=1;i<=3*n+3;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[3*n+3]=mypow(fac[3*n+3],mod-2);
	for(int i=3*n+2;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	for(int i=0;i<3*n+3;i++)f[i]=C(3*n+3,i+1);
	//printf("@%d\n",f[0]);
	res[0]=1ll*f[0]*inv3%mod;
	
	for(int i=1;i<3*n+3;i++)
	{
		res[i]=M(1ll*f[i]-3ll*res[i-1]%mod+mod);
		if(i>1)res[i]=M(res[i]-res[i-2]+mod);
		res[i]=1ll*res[i]*inv3%mod;
	}
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",res[x]);
	}
	return 0;
}