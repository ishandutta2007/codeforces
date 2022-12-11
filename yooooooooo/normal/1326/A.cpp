 
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		else
		{
                        printf("2");
			for(int i=1;i<n;i++)printf("3");
			printf("\n"); 
		}
	}
	return 0;
 }