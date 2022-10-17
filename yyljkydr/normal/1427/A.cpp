#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		if(s==0)
			puts("NO");
		else
		{
			if(s>0)
				sort(a+1,a+n+1,greater<int>());
			else
				sort(a+1,a+n+1);
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d%c",a[i]," \n"[i==n]);
		}
	}
}