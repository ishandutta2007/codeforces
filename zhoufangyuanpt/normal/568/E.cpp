#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[110000],g[110000],h[110000],a[110000],b[110000],cv[110000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	int mm=m,y=0;m=0;
	memset(cv,0,sizeof(cv));
	for(int i=1;i<=mm;i++)
	{
		if(b[i]!=y)b[++m]=y=b[i];
		cv[m]++;
	}
	int len=0;f[0]=0;g[0]=0;h[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			int k=len;
			for(int j=m;j>=1;j--)
			{
				while(f[k]>=b[j])k--;
				if(k==len)len++;
				f[k+1]=b[j];
				g[k+1]=g[k];
			}
		}
		else
		{
			int l=0,r=len;
			while(l<r)
			{
				int mid=(l+r+1)/2;
				if(f[mid]<a[i])l=mid;
				else r=mid-1;
			}
			if(l==len)len++;
			f[l+1]=a[i];
			g[l+1]=i;
			h[i]=g[l];
		}
	}
	int i=g[len],j=m;
	for(int k=n;k>i;k--)
	{
		if(a[k]==-1)
		{
			if(b[j]<=a[i])break;
			if(j>0)a[k]=b[j],cv[j]--,j--;
		}
	}
	while(i>0)
	{
		int hi=h[i];
		while(j>0&&b[j]>=a[i])j--;
		for(int k=i;k>hi;k--)
		{
			if(a[k]==-1)
			{
				if(b[j]<=a[hi])break;
				if(j>0)a[k]=b[j],cv[j]--,j--;
			}
		}
		i=hi;
	}
	j=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==-1)
		{
			while(cv[j]==0)j++;
			printf("%d ",b[j]);
			cv[j]--;
		}
		else printf("%d ",a[i]);
	}
	if(a[n]==-1)
	{
		while(cv[j]==0)j++;
		printf("%d\n",b[j]);
		cv[j]--;
	}
	else printf("%d\n",a[n]);
	return 0;
}