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
int n,m,k,a[100100][12]={},t[12]={},s[100100]={};
void work()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	int u,v;
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",&u,&v);
		++t[v];
		--s[u];
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			s[j]+=t[i]*a[j][i];
	}
	for(int i=1;i<=n;++i)
		printf("%d%c",s[i]," \n"[i==n]);
}
int main()
{	
	work();
	return 0;
}