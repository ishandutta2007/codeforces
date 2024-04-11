#include<stdio.h>
#include<algorithm>
#include<map>
#define inf 100000000000000ll
#define inff 10000000
using namespace std;
map<int,int>::iterator rfy;
int gtw,t1,i,j,k,l,s;
long long n,m;
map<int,int>f[2][10];
bool ee[inff];
struct node
{
	int v;
	bool jsb,wy;
}q[830170];
inline bool cmp(node x,node y)
{
	return x.v<y.v;
}
inline void dfs(int o,int last,int gt)
{
	if (!ee[s])
	{
		ee[s]=1;
		q[++t1].v=s;
		if (!o)
		q[t1].wy=1;
		q[t1].jsb=gt;
	}
	if (!o)
	{
		if (!o)
		{
			int ooo=s/(inff/10);
			if (gt==0)
			for (i=ooo-1;i>=0;i--)
			f[1][i][s%n]++;
			else
			for (i=ooo+1;i<=9;i++)
			f[0][i][s%n]++;
		}
		if (!o)
		return ;
	}
	if (gt==1)
	{
		for (int i=last+1;i<=9;i++)
		{
			s=s*10+i;
			dfs(o-1,i,gt^1);
			s/=10;
		}
	}
	else
	{
		for (int i=last-1;i>=0;i--)
		{
			s=s*10+i;
			dfs(o-1,i,gt^1);
			s/=10;
		}
	}
}
inline void workk(int o,int yy)
{
	int ly=q[yy].jsb;
	if (q[yy].v<10)
	ly=3;yy=q[yy].v;
	for (int i=1;i<=t1;i++)
	{
		if (q[i].wy)
		{
			int pp=q[i].v/(inff/10);
			if (ly==3)
			{
				
				for (int jj=0;jj<=1;jj++)
				{
					
					if (q[i].jsb==jj)
					continue;
					if (jj==0)
					if (yy%10<=pp)
					continue;
					if (jj==1)
					if (yy%10>=pp)
					continue;
					if (q[i].v%n==o)
					m--;
					if (!m)
					{
						printf("%.7d\n",q[i].v);
						return ;
					}
				}
			}
			else
			{
				for (int jj=ly;jj<=ly;jj++)
				{
					if (q[i].jsb==jj)
					continue;
					if (jj==0)
					{
						if (yy%10<=pp)
						continue;
					}
					if (jj==1)
					{
						if (yy%10>=pp)
						continue;
					}
					if (q[i].v%n==o)
					m--;
					if (!m)
					{
						printf("%.7d\n",q[i].v);
						return ;
					}
				}
			}
		}
	}
}
inline void doit1()
{
	s=0;
	t1=9;ee[0]=1;
	for (int i=1;i<=9;i++)
	{
		q[i].v=i;
		q[i].jsb=1;
		ee[i]=1;
	}
	dfs(7,9,0);
	dfs(7,0,1);
	sort(q+1,q+1+t1,cmp);
	for (int i=1;i<=t1;i++)
	if (q[i].v%n==0&&q[i].v!=q[i-1].v)
	gtw++;
	if (gtw>=m)
	{
		for (int i=1;i<=t1;i++)
		{
			if (q[i].v%n==0&&q[i].v!=q[i-1].v)
			m--;
			if (!m)
			{
				printf("%d\n",q[i].v);
				return ;
			}
		}
	}
	m-=gtw;
	for (int i=1;i<=t1;i++)
	{
		int gt=q[i].v%10;
		int uu=(q[i].v%n*inff%n)%n;
		int oo=n-uu;
		if (oo==n)
		oo=0;
		int gtw=0;
		rfy=f[q[i].jsb][gt].find(oo);
		if (rfy!=f[q[i].jsb][gt].end())
		gtw+=(*rfy).second;
		if (q[i].v<10)
		{
			rfy=f[q[i].jsb^1][gt].find(oo);
			if (rfy!=f[q[i].jsb^1][gt].end())
			gtw+=(*rfy).second;
		}
		if (m<=gtw)
		{
			printf("%d",q[i].v);
			workk(oo,i);
			return ;
		}
		m-=gtw;
	}
	printf("-1");
	return ;
}
inline void doit()
{
	long long uu=n;
	while (n<=inf)
	{
		long long p=n;
		int tt=0,qq[20];
		while (p)
		{
			qq[++tt]=p%10;
			p/=10;
		}
		for (i=2;i<tt;i++)
		{
			if ((qq[i]>qq[i-1]&&qq[i]>qq[i+1])||(qq[i]<qq[i-1]&&qq[i]<qq[i+1]))
			continue;
			break;
		}
		if (i==tt) m--;
		if (!m)
		{
			printf("%I64d\n",n);
			return ;
		}
		n+=uu;
	}
	printf("-1");
}
			
int main()
{
	scanf("%I64d%I64d",&n,&m);
	if (n>inf/m)
	{
		printf("-1");
		return 0;
	}
	if (n>=10000000)
	doit();
	else
	doit1();
}