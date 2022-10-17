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
			scanf("%d",&a[i]),ok&=a[i]==i;
		if(ok)
			puts("0");
		else if(a[1]==1||a[n]==n)
			puts("1");
		else if(a[1]==n&&a[n]==1)
			puts("3");
		else
			puts("2");
	}
}