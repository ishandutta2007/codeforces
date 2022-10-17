#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],b[N],f[N],smx[N],v[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<=n&&b[i]<=n||a[i]>n&&b[i]>n)
		{
			puts("-1");
			return 0;
		}
		f[min(a[i],b[i])]=max(a[i],b[i]);
		v[min(a[i],b[i])]=a[i]<b[i];
	}
	for(int i=n;i>=1;i--)
		smx[i]=max(smx[i+1],f[i]);
	int ans=0;
	for(int i=1,j;i<=n;i=j+1)
	{
		j=i-1;
		int smn=0x7fffffff;
		while(j+1<=n&&min(smn,f[j+1])<smx[j+2])
			++j,smn=min(smn,f[j]);
		j++;
		//deal with [i,j]
		int q[2]={0x7fffffff,0x7fffffff};
		int w[2]={0,0};
		for(int k=i;k<=j;k++)
		{
			int p=q[0]<q[1]?0:1;
			if(f[k]<q[p])
			{
				q[p]=f[k];
				w[p]+=!v[k];
				w[p^1]+=v[k];
			}
			else
			{
				if(f[k]>q[p^1])
				{
					puts("-1");
					return 0;
				}
				q[p^1]=f[k];
				w[p^1]+=!v[k];
				w[p]+=v[k];
			}
		}
		ans+=min(w[0],w[1]);
	}
	printf("%d\n",ans);
}