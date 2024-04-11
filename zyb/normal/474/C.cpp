#include<stdio.h>
#include<cstring>
using namespace std;
int x[10005],y[10005],xx[10005],yy[10005];
int ans,i,j,k,l,s,m,n,f[10005];
inline bool check()
{
	if (x[1]==x[2]&&x[2]==x[3])
	return false;
	if (y[1]==y[2]&&y[2]==y[3])
	return false;
	for (i=1;i<=4;i++)
	for (j=i+1;j<=4;j++)
	if (x[i]==x[j]&&y[i]==y[j])
	return false;
	for (i=1;i<=4;i++)
	for (j=1;j<=4;j++)
	for (k=1;k<=4;k++)
	for (l=1;l<=4;l++)
	{
		if (i==j)
		continue;
		if (i==k)
		continue;
		if (i==l)
		continue;
		if (j==k)
		continue;
		if (j==l)
		continue;
		if (k==l)
		continue;
		int gt=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		int gtw=(x[k]-x[l])*(x[k]-x[l])+(y[k]-y[l])*(y[k]-y[l]);
		if (gt==gtw)
		{
			int ggt=(x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]);
			int gtt=(x[j]-x[l])*(x[j]-x[l])+(y[j]-y[l])*(y[j]-y[l]);
			if (ggt==gtt)
			{
				int gggt=(x[i]-x[l])*(x[i]-x[l])+(y[i]-y[l])*(y[i]-y[l]);
				int gttt=(x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]);
				if (ggt==gtt&&gggt==gttt&&ggt==gggt)
				return true;
			}
		}
	}
	return false;
}
inline void change(int o)
{
	if (x[o]<=xx[o]&&y[o]<=yy[o])
	{
		int gt=xx[o]-x[o],gtw=yy[o]-y[o];
		x[o]=xx[o]+gtw;
		y[o]=yy[o]-gt;
		return ;
	}
	if (x[o]>=xx[o]&&y[o]>=yy[o])
	{
		int gt=x[o]-xx[o],gtw=y[o]-yy[o];
		y[o]=yy[o]+gt;
		x[o]=xx[o]-gtw;
		return ;
	}
	if (x[o]<=xx[o]&&y[o]>=yy[o])
	{
		int gt=xx[o]-x[o],gtw=y[o]-yy[o];
		x[o]=xx[o]-gtw;
		y[o]=yy[o]-gt;
		return ;
	}
	if (x[o]>=xx[o]&&y[o]<=yy[o])
	{
		int gt=x[o]-xx[o],gtw=yy[o]-y[o];
		x[o]=xx[o]+gtw;
		y[o]=yy[o]+gt;
		return ;
	}
}
int main()
{
	scanf("%d",&n);
	while (n)
	{
		n--;
		if (!n)
		n=0;
		memset(f,0,sizeof(f));
		ans=100000;
		for (i=1;i<=4;i++)
		scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
		while (!f[0])
		{
			j=4;
			while (f[j]==3)
			j--;
			change(j);
			f[j]++;
			for (k=j+1;k<=4;k++)
			{
				change(k);
				f[k]=0;
			}
			s=0;
			for (j=1;j<=4;j++)
			s=s+f[j];
			if (s>ans)
			continue;
			if (check())
			ans=s;
		}
		if (ans==100000)
		ans=-1;
		printf("%d\n",ans);
	}
}