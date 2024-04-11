#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(k==0)printf("%d\n",n);
		else
		{
			sort(a+1,a+n+1);
			int i;
			for(i=0;i<n;i++)if(a[i+1]!=i)break;
			if(i==n)
			{
				printf("%d\n",n+k);
			}
			else
			{
				int mid=(i+a[n]+1)/2;
				bool bk=false;
				for(i=1;i<=n;i++)if(a[i]==mid)bk=true;
				if(bk)printf("%d\n",n);
				else printf("%d\n",n+1);
			}
		}
	}
	return 0;
}