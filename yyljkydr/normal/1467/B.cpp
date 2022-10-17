#include<bits/stdc++.h>
using namespace std;

const int N=6e5+1e3+7;

int T,n,a[N],f[N],g[N];

int chk(int i)
{
	if(a[i]>a[i-1]&&a[i]>a[i+1])
		return 1;
	if(a[i]<a[i-1]&&a[i]<a[i+1])
		return 1;
	return 0;
} 

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n<=2)
		{
			puts("0");
			continue;
		}
		fill(f+1,f+n*2+1,0);
		fill(g+1,g+n*2+1,0);
		f[1]=0;
		for(int i=2;i<n;i++)
			f[i]=f[i-1]+chk(i);
		f[n]=f[n-1];
		g[n]=0;
		for(int i=n-1;i>=2;i--)
			g[i]=g[i+1]+chk(i);
		g[1]=g[2];
		int ans=f[n];
		for(int i=1;i<=n;i++)
		{
			int x=a[i];
			if(i-1!=0)
			{
				a[i]=a[i-1];
				int now=f[i-2]+g[i+2];
				if(i-1!=1)
					now+=chk(i-1);
				now+=chk(i);
				if(i+1!=n)
					now+=chk(i+1);
				ans=min(ans,now);
			}
			if(i+1!=n+1)
			{
				a[i]=a[i+1];
				int now=f[i-2]+g[i+2];
				if(i-1!=1)
					now+=chk(i-1);
				now+=chk(i);
				if(i+1!=n)
					now+=chk(i+1);
				ans=min(ans,now);
			}
			a[i]=x;
		}
		printf("%d\n",ans);
	}
}