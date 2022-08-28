#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define INF 1000000000

using namespace std;

int n,m;

bool check(int x)
{
	int a=x/2,b=x/3,c=x/6;
	a-=c;
	b-=c;
	return max(n-a,0)+max(m-b,0)<=c;
}
int main()
{
	scanf("%d %d",&n,&m);
	int l=-1,r=INF;
	while(l+1<r)
	{
		int m=(l+r)/2;
		if(check(m)) r=m;
		else l=m;
	}
	printf("%d\n",r);
	return 0;
}