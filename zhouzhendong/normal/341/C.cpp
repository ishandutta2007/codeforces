#include <bits/stdc++.h>
using namespace std;
const int N=2005,mod=1e9+7;
int n,k,t[N];
int C[N][N],Fac[N];
int main(){
	scanf("%d",&n);
	int _n=0;
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if (x==-1)
			t[i]++,_n++;
		else
			t[x]--;
	}
	k=0;
	for (int i=1;i<=n;i++)
		if (t[i]>0)
			k++;
	n=_n;
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=1LL*Fac[i-1]*i%mod;
	for (int i=0;i<=n;i++)
		C[i][i]=C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	int ans=0;
	for (int i=0;i<=n;i++)
		ans=(1LL*C[k][i]%mod*Fac[n-i]*((i+1)%2*2-1)+ans)%mod;
	ans=(ans+mod)%mod;
	printf("%d",ans);
	return 0;
}