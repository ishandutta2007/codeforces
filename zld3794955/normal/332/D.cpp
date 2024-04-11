#include<bits/stdc++.h>
using namespace std;
const int N=2020;
int n,k,c[N][N]={},d[N]={};
int main()
{
	scanf("%d%d",&n,&k);
	long long sum=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			scanf("%d",&c[i][j]);
	if(k==1 || k==n-1)
	{
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(c[i][j]!=-1)
					sum+=c[i][j]+c[i][j];
		printf("%I64d\n",sum/n);
	}
	else
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
				c[i][j]=c[j][i];
		for(int i=1;i<=n;++i)
			c[i][i]=-1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i]+=c[i][j]!=-1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(c[i][j]!=-1)
					sum+=(long long)c[i][j]*(d[i]-1);
		printf("%I64d\n",sum/(n*(n-1)/2));
	}
	return 0;
}