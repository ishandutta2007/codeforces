#import<bits/stdc++.h>
using namespace std;
const int N=5001;
int n,a[N],f[N][N],g[N][N];
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n+1;j++)
				f[i][j]=g[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				f[i][j]=f[i][j-1]+(a[i]>a[j]);
		for(int i=1;i<=n;i++)
			for(int j=n;j>i;j--)
				g[i][j]=g[i][j+1]+(a[i]>a[j]);
		long long A=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				A+=g[i][j+1]*f[j][i-1];
		cout<<A<<'\n';
	}
}