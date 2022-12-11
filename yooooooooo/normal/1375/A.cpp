#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,x;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			x=abs(x);
			if(i%2)printf("%d ",-1*x);
			else printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}