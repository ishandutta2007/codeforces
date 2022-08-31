#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	double len=0,ret=0;
	for(int i=0;i<n;i++)
	{
		double p;
		scanf("%lf",&p);
		ret+=p*(len*2+1);
		len=p*(len+1);
	}
	printf("%.8f\n",ret);
	return 0;
}