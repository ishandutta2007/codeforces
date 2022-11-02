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
const int N=100010,A=0,B=1,Unknown=-1;
int n,a,b,p[N]={},AB[N]={};
map<int,int>m;
bool fail=false;
void init()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		m[p[i]]=i;
	}
	fill(AB+1,AB+n+1,Unknown);
	AB[0]=Unknown;
}
bool dfs(int s,int f)
{
	if(!m.count(a-p[s]) && !m.count(b-p[s]))
		return false;
	if(!m.count(a-p[s]) && m.count(b-p[s]))
	{
		AB[s]=B;
		int pos=m[b-p[s]];
		if(AB[f]==A)
			return false;
		else
			return f || dfs(pos,s);
	}
	if(m.count(a-p[s]) && !m.count(b-p[s]))
	{
		AB[s]=A;
		int pos=m[a-p[s]];
		if(AB[f]==B)
			return false;
		else
			return f || dfs(pos,s);
	}
	if(m.count(a-p[s]) && m.count(b-p[s]))
	{
		int pos1=m[a-p[s]],pos2=m[b-p[s]];
		if(pos1==f)
		{
			AB[s]=AB[f];
			return dfs(pos2,s);
		}
		if(pos2==f)
		{
			AB[s]=AB[f];
			return dfs(pos1,s);
		}
		AB[s]=A;
		bool flag=dfs(pos1,s) && dfs(pos2,s);
		if(!flag)
		{
			AB[s]=B;
			flag=dfs(pos1,s) && dfs(pos2,s);
			if(!flag)
				return false;
		}
		return true;
	}
	return true;
}
void work()
{
	if(a!=b)
	{
		for(int i=1;i<=n && !fail;++i)
			if(AB[i]==Unknown)
				fail|=!dfs(i,0);
		if(fail)
			puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				printf("%d ",AB[i]);
			printf("\n");
		}
	}
	if(a==b)
	{
		for(int i=1;i<=n && !fail;++i)
			if(!m.count(a-p[i]))
				fail=true;
			else
				AB[i]=A;
		if(fail)
			puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				printf("%d ",AB[i]);
			printf("\n");
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}