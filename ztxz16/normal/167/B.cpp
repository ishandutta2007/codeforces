#include <stdio.h>
#include <stdlib.h>

using namespace std;
double ans,p[10001],f[305][305][305];
int n,l,k,a[10001];
int i,j;

int main()
{
	scanf("%d %d %d",&n,&l,&k);
	for(i=1;i<=n;i++)
		scanf("%lf",&p[i]),p[i]/=100.0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]++;
	if (k<n) f[0][0][k]=1; else f[0][0][n]=1;

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			for(k=0;k<=n;k++)
			{
				if (n<k+a[i+1])
					f[i+1][j+1][n]+=(p[i+1])*f[i][j][k];
				else f[i+1][j+1][k+a[i+1]]+=(p[i+1])*f[i][j][k];
				f[i+1][j][k]+=((1-p[i+1])*f[i][j][k]);
			}
	for(i=l;i<=n;i++)
		for(j=i;j<=n;j++)
			ans+=f[n][i][j];
	printf("%.10lf\n", ans);
}