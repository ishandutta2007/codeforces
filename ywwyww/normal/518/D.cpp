#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
double f[2010][2010];
int main()
{
	int n,t;
	double p;
	scanf("%d%lf%d",&n,&p,&t);
	int i,j;
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(i=1;i<=t;i++)
		for(j=0;j<=n;j++)
			if(j==n)
				f[i][j]=f[i-1][j]+p*f[i-1][j-1];
			else if(j)
				f[i][j]=(1-p)*f[i-1][j]+p*f[i-1][j-1];
			else
				f[i][j]=(1-p)*f[i-1][j];
	double ans=0;
	for(i=0;i<=n;i++)
		ans+=f[t][i]*i;
	printf("%.10lf\n",ans);
	return 0;
}