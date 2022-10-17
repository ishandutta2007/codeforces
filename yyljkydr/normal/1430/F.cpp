#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e3+1e2+7;

int n,k;

int l[N],r[N],a[N];

int g[N][N],h[N][N],f[N],la[N][N];

signed main()
{
	scanf("%lld%lld",&n,&k);
	int sum=0;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&l[i],&r[i],&a[i]),sum+=a[i];
	for(int i=1;i<=n;i++)
	{
		int j=i;
		int rem=k;
		while(j<=n)
		{
			int tim=(a[j]-rem+k-1)/k;
			rem=rem+k*tim-a[j];
			if(tim>r[j]-l[j])
				break;
			g[i][j]=1;
			la[i][j]=(r[j]-l[j]-tim);
			h[i][j]=rem;
			j++;
		}
	}
	f[0]=0;
	int ans=g[1][n]?0:1e18;
	l[n+1]=1e18;
	for(int i=1;i<=n;i++)
	{
		f[i]=1e18;
		for(int j=0;j<i;j++)
			if(g[j+1][i]&&(la[j+1][i]||r[i]<l[i+1]))
				f[i]=min(f[i],f[j]+h[j+1][i]);
		if(g[i+1][n])
			ans=min(ans,f[i]);
	}
	if(ans>=1e18)
		puts("-1");
	else
		printf("%lld\n",ans+sum);
}