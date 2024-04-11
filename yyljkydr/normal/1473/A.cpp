#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],d;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ok=1;
		for(int i=1;i<=n;i++)
			ok&=(a[i]<=d);
		if(ok)
		{
			puts("YES");
			continue;
		}
		if(a[1]+a[2]<=d)
			puts("YES");
		else
			puts("NO");
	}
}