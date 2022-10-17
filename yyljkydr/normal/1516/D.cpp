#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],to[N][21],nxt[N],q;

int main()
{
	scanf("%d%d",&n,&q);
	to[n+1][0]=n+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),to[i][0]=n+1;
	for(int i=1;i<=100000;i++)
		nxt[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0)
			{
				if(j!=1)
				{
					to[i][0]=min(to[i][0],nxt[j]);
					nxt[j]=i;
				}
				if(a[i]!=j*j)
				{
					to[i][0]=min(to[i][0],nxt[a[i]/j]);
					nxt[a[i]/j]=i;
				}
			}
		to[i][0]=min(to[i][0],to[i+1][0]);
	}
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n+1;i++)
			to[i][j]=to[to[i][j-1]][j-1];
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int x=l,ans=0;
		for(int i=20;i>=0;i--)
			if(to[x][i]<=r)
				ans+=1<<i,x=to[x][i];
		printf("%d\n",ans+1);
	}
}