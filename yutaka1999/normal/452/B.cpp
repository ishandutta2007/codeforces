#include <cstdio>
#include <cstdlib>
#include <cmath>
#define eps 1e-8

using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n>0&&m>0)
	{
		if(n<m)
		{
			double one=2*sqrt(n*n+m*m)+m;
			double sec=sqrt(n*n+m*m)+2*sqrt((n-1)*(n-1)+m*m);
			if(one+eps<sec)
			{
				printf("%d %d\n",n-1,0);
				printf("%d %d\n",0,m);
				printf("%d %d\n",n,0);
				printf("%d %d\n",1,m);
			}
			else
			{
				printf("%d %d\n",0,0);
				printf("%d %d\n",n,m);
				printf("%d %d\n",n,0);
				printf("%d %d\n",0,m);
			}
		}
		else
		{
			double one=2*sqrt(n*n+m*m)+n;
			double sec=sqrt(n*n+m*m)+2*sqrt((m-1)*(m-1)+n*n);
			if(one+eps<sec)
			{
				printf("%d %d\n",0,m-1);
				printf("%d %d\n",n,0);
				printf("%d %d\n",0,m);
				printf("%d %d\n",n,1);
			}
			else
			{
				printf("%d %d\n",0,0);
				printf("%d %d\n",n,m);
				printf("%d %d\n",0,m);
				printf("%d %d\n",n,0);
			}
		}
	}
	else if(n==0)
	{
		printf("%d %d\n",0,1);
		printf("%d %d\n",0,m);
		printf("%d %d\n",0,0);
		printf("%d %d\n",0,m-1);
	}
	else
	{
		printf("%d %d\n",1,0);
		printf("%d %d\n",n,0);
		printf("%d %d\n",0,0);
		printf("%d %d\n",n-1,0);
	}
	return 0;
}