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
const int N=303,M=303;
int n,m,k,x[N*M]={},y[N*M]={},tot=0;
int main()
{	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		if(i&1)
			for(int j=1;j<=m;++j)
			{
				++tot;
				x[tot]=i;
				y[tot]=j;
			}
		else
			for(int j=m;j>=1;--j)
			{
				++tot;
				x[tot]=i;
				y[tot]=j;
			}
	}
	for(int i=1;i<k;++i)
	{
		printf("2 ");
		printf("%d %d %d %d\n",x[i*2-1],y[i*2-1],x[i*2],y[i*2]);
	}
	int last=tot-2*(k-1);
	printf("%d",last);
	for(int i=2*k-1;i<=tot;++i)
		printf(" %d %d",x[i],y[i]);
	printf("\n");
	return 0;
}