#include<stdio.h>
#include<cstring>
using namespace std;
int da[100005],q[100005];
int i,j,k,l,s,m,n,tot,gt;
int visit[100005];
inline void mk(int o)
{
	for (int i=2;i<=n;i++)
	{
		if (!visit[i])
		{
			q[++tot]=i;
			visit[i]=1;
		}
		for (int j=2;j*i<=n;j++)
		visit[i*j]=1;
	}
}
int main()
{
	scanf("%d",&n);
	mk(n);
	memset(visit,0,sizeof(visit));
	for (k=2;k<=tot;k++)
	{
		int s=0;
		i=q[k];
		for (j=1;j*i<=n;j++)
		if (!visit[j*i])
		{
			visit[j*i]=k;
			s++;
		}
		if (!(s%2))
		{
			for (j=1;j*i<=n;j++)
			if (visit[j*i]==k)
			da[++gt]=i*j;
		}
		else
		{
			if (s>1)
			{
				visit[i*2]=0;
				for (j=1;j*i<=n;j++)
				if (visit[j*i]==k)
				da[++gt]=j*i;
			}
		}
	}
	for (i=1;i*2<=n;i++)
	if (!visit[i*2])
	{
		visit[i*2]=-1;
		s++;
	}
	if (!(s%2))
	{
		for (i=1;i*2<=n;i++)
		if (visit[i*2]==-1)
		da[++gt]=i*2;
	}
	else
	if (s>1)
	for (i=2;i*2<=n;i++)
	if (visit[i*2]==-1)
	da[++gt]=i*2;
	printf("%d\n",gt/2);
	for (i=1;i<=gt;i+=2)
	printf("%d %d\n",da[i],da[i+1]);
}