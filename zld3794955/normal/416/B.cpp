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
int n,m,t[50050][6]={},et[6]={};
void init()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&t[i][j]);
}
void work()
{
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			et[j]=max(et[j-1],et[j])+t[i][j];
		printf("%d ",et[n]);
	}
}
int main()
{	
	init();
	work();
	return 0;
}