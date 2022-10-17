#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

int p[N][2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			p[a[i]][i&1]++;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			p[a[i]][i&1]--;
		int ans=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<2;j++)
				ans&=p[a[i]][j]==0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<2;j++)
				p[a[i]][j]=0;
		puts(ans?"YES":"NO");
	}
}