#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		int x;scanf("%d",&x);
		if(n==1&&x%2==1)printf("-1\n");
		else
		{
			if(x%2==0)printf("1\n1\n");
			else
			{
				scanf("%d",&x);n--;
				if(x%2==0)printf("1\n2\n");
				else printf("2\n1 2\n");
			}
		}
		for(int i=1;i<n;i++)scanf("%*d");
	}
	return 0;
}