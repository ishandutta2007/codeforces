#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,u,v,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ok=1,alle=1;
		for(int i=1;i<n;i++)
			ok&=(abs(a[i]-a[i+1])<=1),alle&=a[i]==a[i+1];
		if(!ok)
		{
			puts("0");
		}
		else
		{
			if(alle)
			{
				printf("%d\n",min(2*v,u+v));
			}
			else
			{
				printf("%d\n",min(u,v));
			}
		}
	}
}