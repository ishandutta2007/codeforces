#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int c=-1,m=-1;
		bool ok=1;
		for(int i=2;i<=n;i++)
			if(a[i]>=a[i-1])
			{
				if(c==-1)
					c=a[i]-a[i-1];
				else
					ok&=c==a[i]-a[i-1];
			}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1])
			{
				if(m==-1)
					m=a[i-1]+c-a[i];
				else
					ok&=m==a[i-1]+c-a[i];
			}
		if(m!=-1&&c!=-1)
			for(int i=1;i<=n;i++)
				if(a[i]>=m)
					ok=0;
		if(!ok)
			puts("-1");
		else if(m==-1||c==-1)
			puts("0");
		else
			printf("%d %d\n",m,c);
	}
}