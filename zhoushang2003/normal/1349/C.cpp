#include<bits/stdc++.h>
using namespace std;
const long long N=1e3+1,I=1e18,X[4]={-1,0,0,1},Y[4]={0,-1,1,0};
long long n,m,T,a[N][N],U,V,f[N][N],p[N*N],q[N*N],s,t,P,Q,x,y,z;
string S[N]; 
int main()
{
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++)
		cin>>S[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=S[i][j-1]-'0',f[i][j]=I;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++)
			{
				U=i+X[k],V=j+Y[k];
				if(1<=U&&U<=n&&1<=V&&V<=m&&a[U][V]==a[i][j])
					f[i][j]=0,p[++t]=i,q[t]=j,k=4;
			}
	while(s<t)
	{
		P=p[++s],Q=q[s];
		for(int i=0;i<4;i++)
		{
			U=P+X[i],V=Q+Y[i];
			if(1<=U&&U<=n&&1<=V&&V<=m&&f[U][V]==I)
				f[U][V]=f[P][Q]+1,p[++t]=U,q[t]=V;
		}
	}
	while(T--&&cin>>x>>y>>z)
		if(z<=f[x][y]||(z-f[x][y])%2==0)
			cout<<a[x][y]<<'\n';
		else
			cout<<1-a[x][y]<<'\n';
	return 0;
}