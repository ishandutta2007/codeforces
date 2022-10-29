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
		int bk=0,bbk=0,ck=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)bbk++;
			if(a[i]>=k)
			{
				if(i>1&&a[i-1]>=k)bk++;
				if(i>2&&a[i-2]>=k)
				{
					if(a[i-1]!=k||a[i]==k||a[i-2]==k)bk++;
					else ck++,bbk--;
				}
			}
		}
		if(n==1)bk=true;
		if(bk>=1&&bbk+ck>=1||bbk+ck>=2&&ck>=1)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}