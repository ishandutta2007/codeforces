#include<stdio.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if (!m&&n>1)
	{
		printf("No solution");
		return 0;
	}
	printf("%d",m);
	for (int i=1;i<n;i++)
	printf("0");
}