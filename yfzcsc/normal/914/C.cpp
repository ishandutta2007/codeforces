#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int C[1100][1100],f[1100];
int n,k,ans,cnt1=0;
char s[1100];
int main(){
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	if(k==0)return puts("1"),0;
	if(k==1)return printf("%d",n-1),0;
	for(int i=0;i<=n;++i)
		for(int j=*C[i]=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	f[0]=-100000,f[1]=0;
	for(int i=2;i<=n;++i)f[i]=f[__builtin_popcount(i)]+1;
	for(int i=1;i<=n;++i)if(s[i]=='1'){
		int REST=n-i;
		for(int j=0;j<=REST;++j)if(f[cnt1+j]+1==k)
			ans=(ans+C[REST][j])%mod;
		cnt1++;	
	}
	if(f[cnt1]+1==k)ans=(ans+1)%mod;
	printf("%d",ans);
}