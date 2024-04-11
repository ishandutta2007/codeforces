#include<bits/stdc++.h>
using namespace std;

int T;

int n,d,a[101];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)
		{
			int dis=i-1;
			int x=d/dis;
			int y=min(x,a[i]);
			d-=y*dis;
			a[1]+=y;
		}
		printf("%d\n",a[1]);
	}
}