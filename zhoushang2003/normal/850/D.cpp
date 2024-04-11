#import<bits/stdc++.h>
using namespace std;
const int N=70,M=3000;
int m,a[N],f[N][N][M],g[N][N][M],n,x,y,z,A[N][N];
pair<int,int>p[N];
main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+m+1),f[0][0][0]=1;
	for(int i=1;i<N;i++)
		for(int j=1;j<=m;j++)
			for(int k=max(a[j],i*(i-1)/2);k<M;k++)
			{
				if(f[i-1][j][k-a[j]])
					f[i][j][k]=1;
				if(f[i-1][j-1][k-a[j]])
					f[i][j][k]=1,g[i][j][k]=1;
			}
	for(int i=1;i<N;i++)
		if(f[i][m][i*(i-1)/2])
			n=i,i=N;
	x=m,y=n*(n-1)/2;
	for(int i=n;i>=1;i--)
		p[i]={a[x],i},z=g[i][x][y],y-=a[x],x-=z;
	for(int i=1;i<=n;i++)
	{
		sort(p+i,p+n+1);
		for(int j=i+1;j<=i+p[i].first;j++)
			A[p[i].second][p[j].second]=1;
		for(int j=i+p[i].first+1;j<=n;j++)
			A[p[j].second][p[i].second]=1,p[j].first--;
	}
	cout<<n<<'\n';
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			cout<<A[i][j]; 
}