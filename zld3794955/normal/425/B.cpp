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
const int N=110,M=110;
int n,m,k,ans=0x7fffffff;
int a[N][M]={},same[M]={},different[M]={};
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
}
void workn()
{
	for(int i=1;i<=n;++i)
	{
		int s=0;
		for(int k=1;k<=n;++k)
		{
			if(k==i)
				continue;
			int s1=0,s2=0;
			for(int j=1;j<=m;++j)
			{
				if(a[i][j]==a[k][j])
					++s1;
				else
					++s2;
			}
			s+=min(s1,s2);
		}
		ans=min(ans,s);
	}
}
void workm()
{
	for(int i=1;i<=m;++i)
	{
		int s=0;
		for(int k=1;k<=m;++k)
		{
			if(k==i)
				continue;
			int s1=0,s2=0;
			for(int j=1;j<=n;++j)
			{
				if(a[j][i]==a[j][k])
					++s1;
				else
					++s2;
			}
			s+=min(s1,s2);
		}
		ans=min(ans,s);
	}
}
void calc(int base)
{
	int s=base;
	for(int i=2;i<=n;++i)
	{
		int s1=0,s2=0;
		for(int j=1;j<=m;++j)
			if(a[1][j]==a[i][j])
				++s1;
			else
				++s2;
		s+=min(s1,s2);
	}
	ans=min(s,ans);
}
void tryy(int row,int t)
{
	if(row>m)
	{
		calc(t);
		return;
	}
	tryy(row+1,t);
	a[1][row]=!a[1][row];
	tryy(row+1,t+1);
	a[1][row]=!a[1][row];
}
int main()
{	
	init();
	if(n>k)
		workn();
	else
		if(m>k)
			workm();
		else
			tryy(1,0);
	if(ans>k)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}