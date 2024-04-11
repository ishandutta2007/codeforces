#import<bits/stdc++.h>
using namespace std;
const int N=6e5,M=30;
int n,k,x,f[N][M],u[N][M],v[N][M];
main()
{
	cin>>n>>k;
	for(int i=0;i<(1<<k);i++)
		f[i][0]=u[i][0]=1e9,v[i][0]=-1e9;
	while(n--&&cin>>x)
		u[x][0]=v[x][0]=0;
	for(int i=1;i<=k;i++)
		for(int j=0;j<(1<<k);j++)
			x=j^(1<<(i-1)),u[j][i]=min(u[j][i-1],u[x][i-1]+(1<<(i-1))),v[j][i]=max(v[j][i-1],v[x][i-1]+(1<<(i-1))),f[j][i]=min({f[j][i-1],f[x][i-1],u[x][i-1]-v[j][i-1]+(1<<(i-1))});
	for(int i=0;i<(1<<k);i++)
		cout<<f[i][k]<<' ';
}