#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N];

int f[N][2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)
			f[i][0]=f[i][1]=1e9;
		f[0][1]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<2;j++)
			{
				f[i+1][j^1]=min(f[i+1][j^1],f[i][j]+j*a[i+1]);
				if(i+2<=n)
					f[i+2][j^1]=min(f[i+2][j^1],f[i][j]+j*(a[i+1]+a[i+2]));
			}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
}