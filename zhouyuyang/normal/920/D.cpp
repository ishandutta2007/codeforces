#include <cstdio>
int g[12000],p[12000];
bool b[12000],c[12000],d[12000];
int i,j,k,m,n,q,t,v,w;
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for (i=1;i<=n;i++)
		scanf("%d",&g[i]),w=w+g[i];
	if (w<m)
		return puts("NO"),0;
	b[0]=true;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<k;j++)
			d[j]=b[j];
		for (j=0;j<k;j++)
			if ((d[j]) && (! d[(j+g[i])%k]))
				b[(j+g[i])%k]=true,p[(j+g[i])%k]=i;
	}
	if (! b[m%k])
		return puts("NO"),0;
	puts("YES");
	for (i=m%k,t=p[m%k];i;i=(i-g[p[i]]%k+k)%k)
		c[p[i]]=true,printf("%d %d %d\n",1000000000,p[i],t);
	for (i=1;i<=n;i++)
		if (! c[i])
		{
			if (! q)
				q=i;
			printf("%d %d %d\n",1000000000,i,q);
			v=v+g[i];
		}
	if (t)
	{
		if (q)
		{
			if (v/k)
				printf("%d %d %d\n",v/k,q,t);
		}
		else
		{
			for (i=1;i<=n;i++)
				if (i!=t)
					q=i;
		}
		if ((w-m%k)/k-m/k)
			printf("%d %d %d\n",(w-m%k)/k-m/k,t,q);
	}
	else
		if (m/k)
			printf("%d %d %d\n",m/k,q,2);
}