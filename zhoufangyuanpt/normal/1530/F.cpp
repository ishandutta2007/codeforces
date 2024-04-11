#include<cstdio>
#include<cstring>
using namespace std;
int ksm(int x,int k)
{
	int s=1;
	while(k>0)
	{
		if(k&1)s=s*x%31607;
		x=x*x%31607;
		k>>=1;
	}
	return s;
}
int f[8388608],g[8388608],pc[8388608],a[110][110];
int main()
{
	int n;scanf("%d",&n);
	int G=ksm(10000,31605);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]=a[i][j]*G%31607;
		}
	}
	pc[0]=f[0]=0;
	for(int i=1;i<1<<23;i++)
	{
		f[i]=1;
		pc[i]=pc[i>>1]+(i&1);
	}
	for(int i=1;i<=n;i++)
	{
		memset(g,0,sizeof(g));
		int S;
		if(i==1&&1==n-i+1)
		{
			S=1|1<<21|1<<22;
			g[S]=1;
			g[0]=g[1]=g[1<<21]=g[1<<22]=g[1|1<<21]=g[1|1<<22]=g[1<<21|1<<22]=a[i][1];
		}
		else if(i==1)
		{
			S=1|1<<21;
			g[S]=1;
			g[0]=g[1]=g[1<<21]=a[i][1];
		}
		else if(1==n-i+1)
		{
			S=1|1<<22;
			g[S]=1;
			g[0]=g[1]=g[1<<22]=a[i][1];
		}
		else
		{
			S=1;
			g[1]=1;g[0]=a[i][1];
		}
		for(int j=2;j<=n;j++)
		{
			int SS;
			if(i==j&&j==n-i+1)SS=1<<j-1|1<<21|1<<22;
			else if(i==j)SS=1<<j-1|1<<21;
			else if(j==n-i+1)SS=1<<j-1|1<<22;
			else SS=1<<j-1;
			for(int k=S;k>0;k=(k-1)&S)
			{
				g[k|SS]=g[k];
				for(int l=(SS-1)&SS;l>0;l=(l-1)&SS)g[k|l]=g[k]*a[i][j]%31607;
				g[k]=g[k]*a[i][j]%31607;
			}
			int k=0;
			g[k|SS]=g[k];
			for(int l=(SS-1)&SS;l>0;l=(l-1)&SS)g[k|l]=g[k]*a[i][j]%31607;
			g[k]=g[k]*a[i][j]%31607;
			S|=SS;
		}
		for(int j=S;j>0;j=(j-1)&S)g[j]=(g[j]-g[0]+31607)%31607;
		for(int j=S;j>0;j=(j-1)&S)f[j]=f[j]*g[j]%31607;
	}
	int S=(1<<n)-1|1<<21|1<<22;
	int ss=0;
	for(int i=S;i>0;i=(i-1)&S)
	{
		if(pc[S^i]&1)ss=(ss-f[i]+31607)%31607;
		else ss=(ss+f[i])%31607;
	}
	printf("%d\n",(31608-ss)%31607);
	return 0;
}