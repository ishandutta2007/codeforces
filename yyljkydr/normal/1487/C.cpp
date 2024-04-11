#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,k,g[101][101];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=(n-1)/2;j++)
				g[i][(i+j-1)%n+1]=1,g[(i+j-1)%n+1][i]=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				printf("%d ",g[i][j]);
		puts("");
	}
}