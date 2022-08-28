#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int k,a,b,v;

int main()
{
	scanf("%d %d %d %d",&k,&a,&b,&v);
	for(int i=1;i<=1000;i++)
	{
		int can=min(i*k,i+b);
		if(can*v>=a)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}