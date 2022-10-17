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
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=0;
		sort(a+1,a+n+1);
		int x=1;
		while(a[x]==a[1])
			x++;
		printf("%d\n",n-x+1);
	}
}