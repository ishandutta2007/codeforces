#include<bits/stdc++.h>
using namespace std;
const int N=155,M=155,mod=1000000007;
int n,m,f[4][M][M]={},g[4][M][M]={},ans=0;
inline void add(int &x,int y)
{
	if((x+=y)>=mod)
		x-=mod;
}
inline void add(int k,int xl,int yl,int xr,int yr,int v)
{
	add(f[k][xr][yr],v),add(f[k][xl-1][yl-1],v);
	add(f[k][xr][yl-1],mod-v),add(f[k][xl-1][yr],mod-v);
}
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		memcpy(g,f,sizeof(f));
		memset(f,0,sizeof(f));
		for(int l=1;l<=m;++l)
			for(int r=l;r<=m;++r)
			{
				add(3,l,l,r,r,g[3][l][r]);
				add(3,l,l,r,r-1,g[1][l][r]);
				add(1,l,r,r,m,g[1][l][r]);
				add(1,l+1,r,r,m,g[0][l][r]);
				if(l<r)
					add(3,l+1,l+1,r-1,r-1,g[0][l][r]);
				add(2,1,l,l,r-1,g[0][l][r]);
				add(0,1,r,l,m,g[0][l][r]);
				add(2,1,l,l,r,g[2][l][r]);
				add(3,r,r,l-1,l-1,g[2][l][r]);
			}
		for(int k=0;k<4;++k)
			for(int l=m;l>=1;--l)
				for(int r=m;r>=1;--r)
				{
					add(f[k][l][r],f[k][l+1][r]);
					add(f[k][l][r],f[k][l][r+1]);
					add(f[k][l][r],mod-f[k][l+1][r+1]);
				}
		for(int l=1;l<=m;++l)
			for(int r=l;r<=m;++r)
			{
				++f[0][l][r];
				for(int k=0;k<4;++k)
					add(ans,f[k][l][r]);
			}
	}
	cout<<ans<<endl;
	return 0;
}