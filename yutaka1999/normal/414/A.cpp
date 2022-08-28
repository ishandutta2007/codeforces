#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MX 1000000000

using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(k<n/2)
	{
		puts("-1");
		return 0;
	}
	if(n==1)
	{
		if(k!=0)
		{
			puts("-1");
			return 0;
		}
		puts("1");
		return 0;
	}
	int p=k-(n/2-1);
	printf("%d %d",(MX/p)*p,(MX/p-1)*p);
	n-=2;
	for(int i=0;i<n;i++) printf(" %d",i+1);
	puts("");
	return 0;
}