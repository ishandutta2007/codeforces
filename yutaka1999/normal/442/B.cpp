#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 105
#define eps 1e-11

using namespace std;

double per[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lf",&per[i]);
	sort(per,per+n);
	double ret=0.0,pr=1.0,sum=0.0;
	for(int i=n-1;i>=0;i--)
	{
		sum=sum*(1.0-per[i])+pr*per[i];
		pr*=1.0-per[i];
		ret=max(ret,sum);
	}
	printf("%.10f\n",ret);
	return 0;
}