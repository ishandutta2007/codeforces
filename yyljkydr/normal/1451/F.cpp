#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n,m;

int a[N][N],s[N*2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=2;i<=n+m;i++)
			s[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]),s[i+j]^=a[i][j];
		int ans=0;
		for(int i=2;i<=n+m;i++)
			ans|=s[i];
		puts(ans?"Ashish":"Jeel");
	}
}