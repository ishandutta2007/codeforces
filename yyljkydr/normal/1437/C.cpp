#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;

int q,n,t[N],f[N][N];

int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&t[i]);
		sort(t+1,t+n+1);
		f[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int t=0;t<=n*2;t++)
				f[i][t]=1e9;
			for(int j=i;j<=n*2;j++)
				for(int k=i-1;k<j;k++)
					f[i][j]=min(f[i][j],f[i-1][k]+abs(j-t[i]));
		}
		int ans=1e9;
		for(int i=n;i<=n*2;i++)
			ans=min(ans,f[n][i]);
		printf("%d\n",ans);
	}
}