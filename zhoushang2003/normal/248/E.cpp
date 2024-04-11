#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,M=102;
int n,a[N],c[N],q,u,v,k;
double A,f[N][M];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		c[i]=a[i],f[i][a[i]]=1,A+=f[i][0];
	cin>>q;
	while(q--&&cin>>u>>v>>k)
	{
		A-=f[u][0];
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<=c[u];j++)
				f[u][j]=f[u][j]*(a[u]-j)/a[u]+f[u][j+1]*(j+1)/a[u];
			a[u]--;
		}
		A+=f[u][0],a[v]+=k;
		printf("%.9lf\n",A);
	}
	return 0;
}