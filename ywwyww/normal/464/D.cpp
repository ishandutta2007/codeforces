#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
double f[2][610];
int main()
{
	memset(f,0,sizeof f);
	int n,k,t;
	scanf("%d%d",&n,&k);
	t=1;
	int i,j;
	for(i=n;i>=1;i--)
	{
		t^=1;
		for(j=1;j<=600;j++)
			f[t][j]=(1.*j/k/(j+1)+(k-1.)/k)*f[t^1][j]+j/2./k+1.*j/k/(j+1)+1./k/(j+1)*f[t^1][j+1];
	}
	printf("%.9lf\n",k*f[t][1]);
	return 0;
}