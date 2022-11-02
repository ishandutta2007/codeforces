#include<bits/stdc++.h>
using namespace std;
const int N=84,Inf=0x7fffffff;
int n,m,a[N]={},pos[N]={},f[N][N][N*N/4]={};
// first i with j shields, i with a shield, moved at most k steps
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i])
			pos[++m]=i;
	}
	/* test
	cout<<clock()<<endl;
	n=80,m=40;
	for(int i=1;i<=n;++i)
	{
		a[i]=(i<=m);
		pos[i]=i;
	}
	*/
	pos[++m]=++n;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			for(int k=0;k<=m*(n-m);++k)
				f[i][j][k]=-Inf;
	f[0][0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=min(i,m);++j)
			for(int k=0;k<=j*(n-j);++k)
			{
				if(j==0)
					continue;
				int d=abs(i-pos[j]);
				if(k<d)
					continue;
				//j-th shield corresponds to j-th position
				//last person with a shield is l (l=0 means none)
				for(int l=0;l<i;++l)
				{
					if(f[l][j-1][k-d]==-Inf)
						continue;
					//if(k==0)
					//	cout<<"i="<<i<<" j="<<j<<" k="<<k<<" l="<<l<<endl;
					f[i][j][k]=max(f[i][j][k],f[l][j-1][k-d]+(i-l-1)*((n-m)-(i-j)));
				}
			}
	
	for(int i=0;i<=(n-1)*(n-2)/2;++i)
	{
		f[n][m][i]=max(f[n][m][i],f[n][m][i-1]);
		cout<<f[n][m][i]<<' ';
	}
	cout<<endl;
	// cout<<clock()<<endl; test
}