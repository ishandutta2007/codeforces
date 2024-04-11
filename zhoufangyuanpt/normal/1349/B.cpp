#include<cstdio>
#include<cstring>
using namespace std;
int a[110000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		bool bk=false,bbk=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)bbk=true;
			if(a[i]>=k)
			{
				if(i>1&&a[i-1]>=k)bk=true;
				if(i>2&&a[i-2]>=k)bk=true;
			}
		}
		if((bk||n==1)&&bbk)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}