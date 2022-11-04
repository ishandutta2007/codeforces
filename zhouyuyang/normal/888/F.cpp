#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,a[505][505],f[505][505],g[505][505];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++) f[i][i]=g[i][i]=1;
	for (int l=2;l<=n;l++)
		for (int i=0;i<n;i++){
			int j=(i+l-1)%n;
			if (a[i][j])
				for (int k=i;k!=j;k=(k+1)%n)
					g[i][j]=(g[i][j]+1ll*f[i][k]*f[(k+1)%n][j])%mo;
			for (int k=i;k!=j;k=(k+1)%n)
				f[i][j]=(f[i][j]+1ll*f[i][k]*g[k][j])%mo;
		}
	printf("%d\n",f[0][n-1]);
}