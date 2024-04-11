#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int bit[1000100]={1},pw[10]={1},f[1000100],s[1000100][3],n;
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),s[x][0]++;
	for(int i=0;i<=999999;++i)s[i][1]=1ll*s[i][0]*i%mod,s[i][2]=1ll*s[i][0]*i*i%mod;
	for(int i=1;i<=6;++i)pw[i]=pw[i-1]*10;
	for(int i=1;i<=n;++i)bit[i]=(bit[i-1]<<1)%mod;
	for(int j=0;j<6;++j)for(int i=999999;i>=0;--i)
		if(i/pw[j]%10!=9&&i+pw[j]<1000000)for(int k=0;k<3;++k)
			s[i][k]=(s[i][k]+s[i+pw[j]][k])%mod;
	for(int i=0;i<=999999;++i)if(s[i][0]){
		f[i]=1ll*s[i][2]*bit[s[i][0]-1]%mod;
		if(s[i][0]>1)f[i]=(f[i]+1ll*(1ll*s[i][1]*s[i][1]%mod-s[i][2]+mod)*bit[s[i][0]-2]%mod)%mod;
	}
	for(int j=0;j<6;++j)for(int i=0;i<=999999;++i)
		if(i/pw[j]%10!=9&&i+pw[j]<1000000)f[i]=(f[i]-f[i+pw[j]]+mod)%mod;
	for(int i=0;i<=999999;++i)ans^=1ll*i*((f[i]+mod)%mod);//,f[i]?printf("[%d,%d]",i,f[i]):0;
	cout<<ans;
}