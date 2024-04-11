#include<bits/stdc++.h>
using namespace std;
const int N=1010;
double f[N][N]={},g[N][N]={};
int n,m,x,y,a[N]={};
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			f[i][j]=a[i]>a[j];
	while(m--)
	{
		cin>>x>>y;
		if(x>y) swap(x,y);
		for(int i=1;i<x;++i)
			g[i][x]=f[i][x];
		for(int i=x+1;i<=n;++i)
			g[x][i]=f[x][i];
		for(int i=1;i<y;++i)
			g[i][y]=f[i][y];
		for(int i=y+1;i<=n;++i)
			g[y][i]=f[y][i];
		for(int i=1;i<x;++i)
			f[i][x]=f[i][y]=(g[i][x]+g[i][y])*0.5;
		for(int i=y+1;i<=n;++i)
			f[x][i]=f[y][i]=(g[y][i]+g[x][i])*0.5;
		for(int i=x+1;i<=y-1;++i)
		{
			f[x][i]=(g[x][i]+1.0-g[i][y])*0.5;
			f[i][y]=(g[i][y]+1.0-g[x][i])*0.5;
		}
		f[x][y]=0.5;
	}
	double ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ans+=f[i][j];
	printf("%.12f\n",ans);
	return 0;
}