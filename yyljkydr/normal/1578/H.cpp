#include<bits/stdc++.h>
using namespace std;

const int N=4e2+1e1+7;

int T,n,m;

char a[N][N];

int s[N][N];

int get(int ax,int ay,int bx,int by,int c)
{
	int ret=s[bx][by]-s[ax-1][by]-s[bx][ay-1]+s[ax-1][ay-1];
	if(!c)
		ret=(bx-ax+1)*(by-ay+1)-ret;
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;j++)
				s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='1');
		}
		int ans=0x7fffffff;
		for(int i=1;i<=n;i++)
			for(int j=i+4;j<=n;j++)
			{
				int pre=-0x7fffffff;
				for(int k=4;k<=m;k++)
				{
					int l=k-3;
					int las=get(i,1,i,l,0)+get(j,1,j,l,0)+get(i+1,1,j-1,l,1)-get(i+1,l,j-1,l,0);
					pre=max(pre,las);
					ans=min(ans,get(i,1,i,k-1,0)+get(j,1,j,k-1,0)+get(i+1,1,j-1,k-1,1)+get(i+1,k,j-1,k,0)-pre);
				}
			}
		printf("%d\n",ans);
	}
}