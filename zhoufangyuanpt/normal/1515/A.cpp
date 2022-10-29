#include<cstdio>
#include<cstring>
using namespace std;
int a[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,x;scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int s=0;
		bool bk=true;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(s==x)
			{
				if(i==n)
				{
					bk=false;
					puts("NO");
					break;
				}
				else
				{
					a[i]^=a[i+1]^=a[i]^=a[i+1];
					break;
				}
			}
		}
		if(bk==false)continue;
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}