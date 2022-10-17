#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,m;

char s[11][11];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int x=1,y=1;
	int ans=0;
	if(s[1][1]=='*')
		ans++;
	while(x!=n||y!=m)
	{
		int dis=1e9;
		int tx,ty;
		for(int i=x;i<=n;i++)
			for(int j=y;j<=m;j++)
				if(i!=x||j!=y)
					if(s[i][j]=='*')
					{
						if(i-x+j-y<dis)
							dis=i-x+j-y,tx=i,ty=j;
					}
		if(dis==1e9)
		{
			if(x+1>n)
				y++;
			else
				x++;
		}
		else
			x=tx,y=ty,ans++;
	}
	printf("%d\n",ans);
}