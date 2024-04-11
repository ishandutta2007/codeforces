#import<bits/stdc++.h>
using namespace std;
const int N=300;
int t,n,m,x,y,z,g[N][N],a[3000][N],c,d,p[N],A[N],u,v; 
main()
{
	for(cin>>t;cin>>n>>m;)
	{
		memset(g,0,sizeof(g)),memset(a,0,sizeof(a)),c=d=0;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>z,g[x][y]=g[y][x]=i;
			if(~z)
				a[++c][i]=1,a[c][m+1]=z%3;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(g[i][j]&&g[j][k]&&g[k][i])
						c++,a[c][g[i][j]]=a[c][g[j][k]]=a[c][g[k][i]]=1;
		for(int i=1;i<=m;i++)
		{
			u=0;
			for(int j=d+1;j<=c;j++)
				if(a[j][i])
					u=j;
			if(!u)
			{
				A[i]=0;
				continue;
			}
			p[++d]=i,swap(a[u],a[d]);
			if(a[d][i]!=1)
				for(int j=i;j<=m+1;j++)
					a[d][j]=3-a[d][j];
			for(int j=1;j<=c;j++)
				if(j!=d&&a[j][i])
				{
					x=a[j][i];
					for(int k=i;k<=m+1;k++)
						(a[j][k]-=x*a[d][k]-9)%=3;
				}
		}
		v=0;
		for(int i=d+1;i<=c;i++)
			if(a[i][m+1])
				v=1;
		if(v==1)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=d;i++)
			A[p[i]]=a[i][m+1];
		for(int i=1;i<=m;i++)
			cout<<(A[i]?A[i]:3)<<' ';
		puts("");
	}
}