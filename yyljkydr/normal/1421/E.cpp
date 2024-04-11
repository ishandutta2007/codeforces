#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int n;

int a[N];

ll f[N][3][2][2];

void cmax(ll &a,ll b)
{
	a=a>b?a:b;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		printf("%d\n",a[1]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					f[i][j][k][l]=-1e18;
	f[1][2][0][0]=-a[1];
	f[1][1][1][0]=a[1];
	for(int i=1;i<n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
				{
					cmax(f[i+1][(j+2)%3][0][l|(k==0)],f[i][j][k][l]-a[i+1]);
					cmax(f[i+1][(j+1)%3][1][l|(k==1)],f[i][j][k][l]+a[i+1]);
				}
	printf("%lld\n",max(f[n][1][0][1],f[n][1][1][1]));
}