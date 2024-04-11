#include<cstdio>
using namespace std;
int main()
{
	int n;scanf("%d",&n);
	double ss=0;
	for(int i=1;i<=n;i++)ss+=1.0/i;
	printf("%lf\n",ss);
	return 0;
}