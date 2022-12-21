#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>q;
int i,j,k,l,s,m,n;
int a[100005];
int b[100005];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	if (n==1)
	{
		printf("-1");
		return 0;
	}
	sort(a+1,a+1+n);
	int now=a[2]-a[1];
		if (n==2&&now!=0)
	{
		if ((a[2]+a[1])%2==0)
		{
			printf("3\n");
			printf("%d %d %d",((a[1]-(a[2]-a[1]))),((a[1]+a[2])/2),((a[2]+(a[2]-a[1]))));
			return 0;
		}
		else
		{
		printf("2\n");
		printf("%d %d",((a[1]-(a[2]-a[1]))),((a[2]+(a[2]-a[1]))));
		return 0;
		}	
	}
	q[now]=1;
	s=1;
	b[s]=now;
	for (i=3;i<=n;i++)
	{
		if (q[a[i]-a[i-1]]==0)
		b[++s]=a[i]-a[i-1];
		q[a[i]-a[i-1]]++;
	}
	if (s>2)
	{
		printf("0");
		return 0;
	}
	if (s==2)
	{
		if (b[1]==0||b[2]==0)
		{
			printf("0");
			return 0;
		}
		if (q[b[1]]>1)
		{
			if (q[b[2]]>1)
			{
				printf("0\n");
				return 0;
			}
			else
			{
		if (b[2]!=b[1]*2)
		{
			printf("0");
			return 0;
		}
				if (b[2]%2==0)
				{
				printf("1\n");
				for (i=2;i<=n;i++)
				if (a[i]-a[i-1]==b[2])
				break;
				printf("%d",a[i-1]+b[2]/2);
				}	
				else
				printf("0");
				return 0;
			}
		}
		else
		{
			int bb=0,p[105];
			bool qq=false;
				if (b[1]%2==0)
				{
				if (b[1]!=b[2]*2)
				qq=true;
				if (!qq)
				{
				bb=1;
				for (i=2;i<=n;i++)
				if (a[i]-a[i-1]==b[1])
				break;
				p[1]=(a[i-1]+b[1]/2);
				}
				}
				qq=false;
				if (q[b[2]]==1)
		{	
		if (b[2]!=b[1]*2)
		{
			printf("%d\n",bb);
			for (i=1;i<=bb;i++)
			printf("%d ",p[i]);
			return 0;
		}
				if (b[2]%2==0)
				{
				bb++;
				for (i=2;i<=n;i++)
				if (a[i]-a[i-1]==b[2])
				break;
				p[bb]=(a[i-1]+b[2]/2);
				}	
			}
				printf("%d\n",bb);
				sort(p+1,p+1+bb);
				for (i=1;i<=bb;i++)
				printf("%d ",p[i]);
			return 0;
		}
	}
	
	if (now>0)
	{
		printf("2\n");
		printf("%d ",a[1]-now);
		printf("%d",a[n]+now);
	}
	else
	{
		printf("1\n");
		printf("%d ",a[1]-now);
	}
}