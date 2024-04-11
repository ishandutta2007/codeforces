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
struct group
{
	int c,p,num;
}g[1010]={};
struct table
{
	int s,num;
}t[1010]={};
struct group_cmp
{
	bool operator()(const group &g1,const group &g2)
	{
		return g1.p<g2.p;
	}
};
bool group_cmp2(const group &g1,const group &g2)
{
	return g1.c<g2.c;
}
bool table_cmp(const table &t1,const table &t2)
{
	return t1.s<t2.s;
}
int n,k,ans=0,tot=0,w1[1010]={},w2[1010]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&g[i].c,&g[i].p),g[i].num=i;
	sort(g+1,g+n+1,group_cmp2);
	g[n+1].c=0x7fffffff;
	scanf("%d",&k);
	for(int i=1;i<=k;++i)
		scanf("%d",&t[i].s),t[i].num=i;
	sort(t+1,t+k+1,table_cmp);
}
void work()
{
	priority_queue<group,vector<group>,group_cmp>q;
	int pos=1;
	for(int i=1;i<=k;++i)
	{
		while(g[pos].c<=t[i].s)
		{
			q.push(g[pos]);
			++pos;
		}
		if(q.empty())
			continue;
		group h=q.top();
		q.pop();
		ans+=h.p;
		++tot;
		w1[tot]=h.num;
		w2[tot]=t[i].num;
	}
	printf("%d %d\n",tot,ans);
	for(int i=1;i<=tot;++i)
		printf("%d %d\n",w1[i],w2[i]);
}
int main()
{	
	init();
	work();
	return 0;
}