#include<bits/stdc++.h>
using namespace std;

int T,n,k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k>(n-1)/2)
			puts("-1");
		else
		{
			int l=1,r=n;
			while(k)
			{
				printf("%d %d ",l,r);
				l++,r--;
				k--;
			}
			for(int i=l;i<=r;i++)
				printf("%d ",i);
			puts("");
		}
	}
}