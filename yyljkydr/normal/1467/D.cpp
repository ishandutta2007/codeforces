#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e3+1e2+7,P=1e9+7;

int n,k,q,a[N];

ll f[N][N];

int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]); 
	for(int i=1;i<=n;i++)
		f[0][i]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i-1][j-1]+f[i-1][j+1])%P;
	ll ans=0;
	for(int j=0;j<k;j++)
		for(int i=1;i<=n;i++)
			f[k][i]=(f[k][i]+f[j][i]*f[k-j][i]%P)%P;
	for(int i=1;i<=n;i++)
			ans=(ans+f[k][i]*a[i]%P)%P;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans=(ans+(y-a[x])*f[k][x]%P+P)%P;
		a[x]=y;
		printf("%lld\n",ans);
	}
}