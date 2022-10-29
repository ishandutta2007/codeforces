#include<cstdio>
#include<cstring>
using namespace std;
char a[1010000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		long long n,k;
		scanf("%I64d%I64d",&n,&k);
		scanf("%s",a+1);
		int l=-1,r=-1,pj=-1;
		for(int i=1;i<=n;i++)
		{
			pj=i;
			if(a[i]=='0')
			{
				if(l!=-1)
				{
					if(i-l<=k)k-=i-l,l++;
					else
					{
						r=i-k;
						break;
					}
				}
			}
			else if(l==-1)l=i;
		}
		if(l==-1)puts(a+1);
		else if(r==-1)
		{
			for(int i=1;i<l;i++)putchar('0');
			for(int i=l;i<=pj;i++)putchar('1');
			for(int i=pj+1;i<=n;i++)putchar(a[i]);
			putchar('\n');
		}
		else
		{
			for(int i=1;i<l;i++)putchar('0');
			for(int i=l;i<r;i++)putchar('1');
			putchar('0');
			for(int i=r+1;i<=pj;i++)putchar('1');
			for(int i=pj+1;i<=n;i++)putchar(a[i]);
			putchar('\n');
		}
	}
	return 0;
}