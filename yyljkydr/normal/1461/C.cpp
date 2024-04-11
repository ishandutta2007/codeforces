#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m;

int a[N];

int p[N];

double r[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int x=n;
		while(a[x]==x&&x)
			x--;
		for(int i=1;i<=m;i++)
			scanf("%d%lf",&p[i],&r[i]);
		if(!x)
		{
			puts("1.0");
			continue;
		}
		double ans=1;
		for(int i=1;i<=m;i++)
			if(p[i]>=x)
				ans=ans*(1-r[i]);
		printf("%.10lf\n",1-ans);
	}
}