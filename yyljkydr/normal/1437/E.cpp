#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n,k;

int a[N],b[N],f[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]-=i;
	for(int i=1;i<=k;i++)
		scanf("%d",&b[i]);
	b[k+1]=n+1;
	int ans=0;
	a[0]=-1e9,a[n+1]=1e9;
	for(int i=0;i<=k;i++)
	{
		int l=b[i],r=b[i+1];
		if(a[r]<a[l])
		{
			puts("-1");
			return 0;
		}
		vector<int>g(r-l+1);
		for(int i=0;i<g.size();i++)
			g[i]=1e9+1;
		for(int j=l+1;j<=r;j++)
		{
			if(a[j]<a[l]||a[j]>a[r])
				continue;
			f[j]=upper_bound(g.begin()+1,g.end(),a[j])-g.begin();
			g[f[j]]=a[j];
		}
		ans+=(r-l-1)-f[r]+1;
	}
	printf("%d\n",ans);
}