#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<fstream>
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
#include<stdexcept>
#include<iomanip>
#include<functional>
using namespace std;
const int N=2020,M=N*N,mod=1000000007;
int n,a[N][N]={},hl[N]={},hr[N]={},dfn[N]={},low[N]={},tot_dfn=0;
bool v[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
}
void work(int s)
{
	v[s]=true;
	dfn[s]=low[s]=++tot_dfn;
	for(int i=1;i<=n;++i)
		if(a[s][i])
		{
			if(!v[i])
			{
				work(i);
				low[s]=min(low[s],low[i]);
			}
			else
				low[s]=min(low[s],dfn[i]);
		}
	if(dfn[s]==low[s])
	{
		if(dfn[s]!=1)
		{
			puts("NO");
			exit(0);
		}
	}
}
int main()
{	
	init();
	work(1);
	for(int i=1;i<=n;++i)
		if(!v[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}