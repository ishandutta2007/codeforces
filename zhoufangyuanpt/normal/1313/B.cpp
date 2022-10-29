#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,y;scanf("%d%d%d",&n,&x,&y);
		int s=x+y;
		printf("%d %d\n",s-n+1<1?1:s-n+1-(x==n&&y==n),s-1>n?n:s-1);
	}
	return 0;
}