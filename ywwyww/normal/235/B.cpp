#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
double f1[100010],f2[100010];
double a[100010];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		f1[i]=(f1[i-1]+1)*a[i];
		f2[i]=f2[i-1]+(2*f1[i-1]+1)*a[i];
	}
	printf("%.9lf\n",f2[n]);
	return 0;
}