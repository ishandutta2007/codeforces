#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n,c[200002],f[200002],i,d[200002],x,ans,minn;
bool z[200002];
void s(int p)
{
	d[f[p]]-=1;
	z[p]=1;
	if(d[f[p]]==0)s(f[p]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&c[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		f[i]=x;
		d[x]+=1;
	}
	for(i=1;i<=n;i++)if(d[i]==0&&z[i]==0)s(i);
	for(i=1;i<=n;i++)
	{
		if(z[i]==0)
		{
			minn=2147483647;
			x=i;
			while(z[x]!=1)
			{
				z[x]=1;
				minn=min(minn,c[x]);
				x=f[x];
			}
			ans+=minn;
		}
	}
	printf("%d",ans);
}