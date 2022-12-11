#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
double f[1010][1010];
double a[1010];
double b[1010];
double c[1010];
int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	memset(f,0,sizeof f);
	int i,j;
	if(m==1)
	{
		f[n][1]=0;
		for(i=n-1;i>=1;i--)
			f[i][1]=2+f[i+1][1];
	}
	else
		for(i=n-1;i>=1;i--)
		{
			for(j=1;j<=m;j++)
				c[j]=f[i+1][j];
			a[1]=1./2;
			b[1]=3./2+c[1]/2;
			for(j=2;j<=m;j++)
			{
				a[j]=1/(3-a[j-1]);
				b[j]=(4+b[j-1]+c[j])/(3-a[j-1]);
			}
			f[i][m]=(3+b[m-1]+c[m])/(2-a[m-1]);
			for(j=m-1;j>=1;j--)
				f[i][j]=a[j]*f[i][j+1]+b[j];
		}
	printf("%.10lf\n",f[x][y]);
	return 0;
}