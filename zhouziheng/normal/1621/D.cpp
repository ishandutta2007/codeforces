#include<cstdio>
#include<algorithm>

using namespace std;

int c[600][600];

const int INF=1e9;

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		long long ans=0;int minn=INF;
		for(int i=1;i<=2*n;i++)
		{
			for(int j=1;j<=2*n;j++)
			{
				scanf("%lld",&c[i][j]);if(i>n&&j>n)ans+=c[i][j];
			}
		}
		minn=min(minn,c[1][n+1]);minn=min(minn,c[1][2*n]);
		minn=min(minn,c[n][n+1]);minn=min(minn,c[n][2*n]);
		minn=min(minn,c[n+1][1]);minn=min(minn,c[2*n][1]);
		minn=min(minn,c[n+1][n]);minn=min(minn,c[2*n][n]);
		printf("%lld\n",ans+minn);
	}
}