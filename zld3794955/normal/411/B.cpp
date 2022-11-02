#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,x[110][110]={},t[110]={};
bool lc[110]={},lg[110]={};
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&x[i][j]);
	for(int j=1;j<=m;++j)
	{
		int a[110]={};
		for(int i=1;i<=n;++i)
		{
			if(lc[i] || !x[i][j])
				continue;
			if(lg[x[i][j]])
			{
				lc[i]=true;
				t[i]=j;
			}
			else
				if(a[x[i][j]])
				{
					lc[i]=true;
					lc[a[x[i][j]]]=true;
					t[i]=j;
					t[a[x[i][j]]]=j;
					lg[x[i][j]]=true;
				}
				else
					a[x[i][j]]=i;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",t[i]);
	return 0;
}