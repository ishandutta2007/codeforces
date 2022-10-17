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
		bool ok=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),ok&=a[i]>=0;
		if(!ok)
			puts("NO");
		else
		{
			puts("YES");
			printf("%d\n",101);
			for(int i=0;i<=100;i++)
				printf("%d%c",i," \n"[i==100]);
		}
	}
}