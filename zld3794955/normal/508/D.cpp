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
#include<numeric>
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
const int N=205000,M=400040;
int n,m,tot,last[N]={},next[M]={},end[M]={},total_edge=0;
int in[N]={},out[N]={},path[M]={},len=0;
char ch[N][5]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	++out[u];
	++in[v];
}
void init()
{
	cin>>n;
	tot=n;
	map<pair<char,char>,int> num;
	for(int i=1;i<=n;++i)
	{
		cin>>ch[i];
		pair<char,char> tmp(ch[i][0],ch[i][1]);
		if(!num.count(tmp))
			num[tmp]=++tot;
		add_edge(i,num[tmp]);
		tmp=make_pair(ch[i][1],ch[i][2]);
		if(!num.count(tmp))
			num[tmp]=++tot;
		add_edge(num[tmp],i);
	}
}
void dfs(int s)
{
	while(last[s])
	{
		int i=last[s];
		last[s]=next[i];
		dfs(end[i]);
	}
	path[++len]=s;
}
void work()
{
	int s=0;
	for(int i=n+1;i<=tot;++i)
		if(out[i]>in[i])
		{
			if(s || out[i]-in[i]>=2)
			{
				puts("NO");
				return;
			}
			s=i;
		}
	if(s==0)
		s=n+1;
	dfs(s);
	if(len<=total_edge)
	{
		puts("NO");
		return;
	}
	puts("YES");
	int last=0;
	for(int i=1;i<=len;++i)
		if(path[i]<=n)
		{
			putchar(ch[path[i]][0]);
			last=path[i];
		}
	putchar(ch[last][1]);
	putchar(ch[last][2]);
	putchar('\n');
}
int main()
{	
	init();
	work();
	return 0;
}