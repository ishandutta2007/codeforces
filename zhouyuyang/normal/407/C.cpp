#include<bits/stdc++.h>
#define mo 1000000007
#define N 100105
using namespace std;
int a[N],c[N][105],f[105][N];
int n,Q;
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=n+100;i++){
		c[i][0]=1;
		for (int j=1;j<=i&&j<=100;j++)	
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	for (int i=1;i<=Q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		f[k][l]=(f[k][l]+1)%mo;
		for (int j=0;j<=k;j++)
			f[j][r+1]=(f[j][r+1]+mo-c[r-l+k-j][k-j])%mo;
	}
	for (int i=100;i>=0;i--)
		for (int j=1;j<=n;j++)
			f[i][j]=(1ll*f[i][j]+f[i][j-1]+f[i+1][j])%mo;
	for (int i=1;i<=n;i++)
		printf("%d ",(f[0][i]+a[i])%mo);
}