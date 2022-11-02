#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
#include<cassert>
using namespace std;
const int N=2020;
int n,m,px=0,py=0;
double f[N][N]={};
void init()
{
	scanf("%d%d",&n,&m);
	bool l[N]={},r[N]={};
	for(int i=1,x=0,y=0;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		l[x]=true;
		r[y]=true;
	}
	for(int i=1;i<=n;++i)
		px+=l[i];
	for(int j=1;j<=n;++j)
		py+=r[j];
}
inline double incr(int i,int j) { return (double)i*(n-j)/(n*n); }
inline double incl(int i,int j) { return (double)j*(n-i)/(n*n); }
inline double inclr(int i,int j) { return (double)(n-i)*(n-j)/(n*n); }
inline double turn(int i,int j) { return incl(i,j)+incr(i,j)+inclr(i,j); }
void work()
{
	f[px][py]=1;
	for(int i=px;i<=n;++i)
		for(int j=py;j<=n;++j)
		{
			if(i>0)
				f[i][j]+=incl(i-1,j)*f[i-1][j];
			if(j>0)
				f[i][j]+=incr(i,j-1)*f[i][j-1];
			if(i>0 && j>0)
				f[i][j]+=inclr(i-1,j-1)*f[i-1][j-1];
			if(i<n || j<n)
				f[i][j]/=turn(i,j);
		}
	double ans=0;
	for(int i=px;i<=n;++i)
		for(int j=py;j<=n;++j)
			ans+=f[i][j];
	ans-=f[n][n];
	printf("%.10f\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}