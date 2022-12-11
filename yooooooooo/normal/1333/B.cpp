#include<cstdio>
#include<algorithm>
using namespace std;
bool ok0,ok1;
int T,n,a[100005],b[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		ok0=ok1=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<b[i]&&!ok1)
			{
				printf("NO\n");
				goto tag;
			}
			if(a[i]>b[i]&&!ok0)
			{
				printf("NO\n");
				goto tag;
			}
			if(a[i]==-1)ok0=true;
			if(a[i]==1)ok1=true;
		}
		printf("YES\n");
		tag:;
	}
	return 0;
}