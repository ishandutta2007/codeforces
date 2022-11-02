#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=505,Inf=1<<29;
int n,m,a[N][N]={},f[N][N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		fill(a[i]+1,a[i]+n+1,Inf);
		a[i][i]=0;
	}
	for(int i=1,u=0,v=0,l=0;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		a[u][v]=a[v][u]=l;
		// "Between any pair of cities, there is at most one road."
	}
	for(int i=1;i<=n;++i)
		copy(a[i]+1,a[i]+n+1,f[i]+1);
}
void Floyd()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j && i!=k && j!=k)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}
	*/
}
void work()
{
	for(int s=1;s<=n;++s)
	{
		int tmp[N]={};
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j && a[i][j]!=Inf)
				{
					if(f[s][i]+a[i][j]==f[s][j])
						++tmp[j];
					if(f[s][j]+a[j][i]==f[s][i])
						++tmp[i];
				}
		for(int v=s+1;v<=n;++v)
		{
			int ans=0;
			for(int k=1;k<=n;++k)
				if(f[s][k]+f[k][v]==f[s][v])
					ans+=tmp[k];
			printf("%d ",ans/2);
		}
	}
	printf("\n");
}
int main()
{
	init();
	Floyd();
	work();
	return 0;
}