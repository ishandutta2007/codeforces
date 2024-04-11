#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int k[4],a[4][N],f[4][N],in[N];

int main()
{
	for(int i=1;i<=3;i++)
		scanf("%d",&k[i]);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=k[i];j++)
			scanf("%d",&a[i][j]),in[a[i][j]]=i;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=k[1]+k[2]+k[3];j++)
		{
			f[i][j]=max(f[i-1][j-1]+(in[j]==i),f[i][j-1]+(in[j]==i));
			if(i>=3)
				f[i][j]=max(f[i][j],f[i-2][j-1]+(in[j]==i));
		}
	int mx=0;
	for(int i=1;i<=3;i++)
		mx=max(mx,f[i][k[1]+k[2]+k[3]]);
	printf("%d",k[1]+k[2]+k[3]-mx);
}