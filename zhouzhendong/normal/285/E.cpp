#include <bits/stdc++.h>
using namespace std;
const int N=1005,mod=1e9+7;
int n,k;
int C[N][N],Fac[N];
int F[N][N][2][2],f[N];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=1LL*Fac[i-1]*i%mod;
	for (int i=0;i<=n;i++)
		C[i][i]=C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	memset(F,0,sizeof F);
	F[1][0][1][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int a=0;a<2;a++)
				for (int b=0;b<2;b++){
					int &now=F[i][j][a][b];
					if (now==0)
						continue;
					F[i+1][j][b][0]=(F[i+1][j][b][0]+now)%mod;
					F[i+1][j+1][b][1]=(F[i+1][j+1][b][1]+now)%mod;
					if (a==0)
						F[i+1][j+1][b][0]=(F[i+1][j+1][b][0]+now)%mod;
				}
	for (int i=0;i<=n;i++)
		for (int j=0;j<2;j++)
			f[i]=(f[i]+F[n+1][i][j][0])%mod;
	int ans=0;
	for (int i=k;i<=n;i++)
		ans=(1LL*f[i]*C[i][k]%mod*Fac[n-i]*((i-k+1)%2*2-1)+ans)%mod;
	ans=(ans+mod)%mod;
	printf("%d",ans);
	return 0;
}