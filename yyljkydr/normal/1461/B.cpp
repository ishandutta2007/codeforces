#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,m;

char a[N][N];

int f[N][N]; 

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		for(int i=1;i<=m;i++)
			f[n+1][i]=0;
		for(int i=n;i>=1;i--)
			for(int j=1;j<=m;j++)
				if(a[i][j]=='*')
				{
					if(j>1&&j<m&&a[i+1][j-1]=='*'&&a[i+1][j+1]=='*'&&a[i+1][j]=='*')
						f[i][j]=min(f[i+1][j],min(f[i+1][j-1],f[i+1][j+1]))+1;
					else
						f[i][j]=1;
				}
				else
					f[i][j]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=f[i][j];
		printf("%lld\n",ans);
	}
}