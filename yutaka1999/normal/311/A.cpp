#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(n*(n-1)/2<=k) puts("no solution");
	else for(int i=0;i<n;i++) printf("%d %d\n",0,i);
	return 0;
}