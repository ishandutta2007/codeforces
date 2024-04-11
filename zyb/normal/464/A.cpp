#include<stdio.h>
using namespace std;
char c[100005];
int i,j,k,l,s,m,n,a[100005],b[100005],bb;
inline void print()
{
	for(int i=1;i<=n;i++)
	printf("%c",char(a[i]+96));
	bb=1;
}
inline void dfs(int o,int p,int last,int lastt)
{
	if (bb)
	return ;
	if (o>n)
	{
		if (p)
		print();
		return ;
	}
	if (!p)
	{
		a[o]=b[o];
		dfs(o+1,0,b[o],last);
		for (int i=b[o]+1;i<=m;i++)
		{
			if (i!=last&&i!=lastt)
			{
				a[o]=i;
				dfs(o+1,1,i,last);
				return ;
			}
		}
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			if (i!=last&&i!=lastt)
			{
				a[o]=i;
				dfs(o+1,1,i,last);
				return ;
			}
		}
	}
}
		
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for (i=1;i<=n;i++)
	b[i]=int(c[i])-96;
	a[1]=b[1];
	dfs(2,0,b[1],0);
	if (bb)
	return 0;
	if (b[1]!=m)
	{
		a[1]=b[1]+1;
		dfs(2,1,a[1],0);
	}
	if (!bb)
	printf("NO");
}