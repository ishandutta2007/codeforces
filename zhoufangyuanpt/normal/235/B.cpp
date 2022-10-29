#include<cstdio>
#include<cstring>
using namespace std;
double f[110000][3],p[110000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	f[0][0]=1;f[0][1]=0;f[0][2]=0;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=1;
		f[i][1]=(f[i-1][1]+1)*p[i];
		f[i][2]=(f[i-1][2]+2*f[i-1][1]+1)*p[i];
	}
	double ss=0;p[n+1]=0;
	for(int i=1;i<=n;i++)ss=ss+(1-p[i+1])*f[i][2];
	printf("%lf\n",ss);
	return 0;
}