#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int f[2005][2005],d[2005];
double ans,C[2005][2005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	{
		scanf("%d",&f[i][j]);
		if(f[i][j]!=-1)++d[i],++d[j];
	}
	C[0][0]=1;
	for(i=0;i<=n;++i)
	for(j=0;j<=i;++j)
	C[i+1][j]+=C[i][j],C[i+1][j+1]+=C[i][j];
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	if(f[i][j]!=-1)
	ans+=f[i][j]*(C[d[i]-1][m-1]+C[d[j]-1][m-1]);
	ans/=C[n][m];
	printf("%I64d\n",(long long)(ans+1e-9));
}