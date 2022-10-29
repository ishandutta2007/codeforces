#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,x;scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&x);
			printf("%d ",x>0&&i%2==1||x<0&&i%2==0?x:-x);
		}
		scanf("%d",&x);
		printf("%d\n",x>0?x:-x);
	}
	return 0;
}