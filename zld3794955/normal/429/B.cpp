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
const int N=1010,M=1010;
int n,m,a[N][M]={};
int flu[N][M]={},fld[N][M]={},fru[N][M]={},frd[N][M]={},ans=0;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
}
void dp()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			flu[i][j]=max(flu[i-1][j],flu[i][j-1])+a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)
			fru[i][j]=max(fru[i-1][j],fru[i][j+1])+a[i][j];
	for(int i=n;i>=1;--i)
		for(int j=1;j<=m;++j)
			fld[i][j]=max(fld[i+1][j],fld[i][j-1])+a[i][j];
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
			frd[i][j]=max(frd[i+1][j],frd[i][j+1])+a[i][j];
	for(int i=2;i<n;++i)
		for(int j=2;j<m;++j)
		{
			ans=max(ans,flu[i-1][j]+fld[i][j-1]+fru[i][j+1]+frd[i+1][j]);
			ans=max(ans,flu[i][j-1]+fld[i+1][j]+fru[i-1][j]+frd[i][j+1]);
		}
	printf("%d\n",ans);
}
int main()
{	
	init();
	dp();
	return 0;
}