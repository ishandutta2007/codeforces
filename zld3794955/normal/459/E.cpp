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
const int N=300030,M=300030;
struct edge
{
	int u,v,l;
}e[M]={};
bool edge_cmp(const edge &e1,const edge &e2)
{
	return e1.l<e2.l;
}
int n,m,ans[N]={},nans[N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
	sort(e+1,e+m+1,edge_cmp);
}
void work()
{
	queue<int>q;
	for(int i=1;i<=m;++i)
	{
		if(e[i].l!=e[i-1].l)
		{
			while(!q.empty())
			{
				int now=q.front();
				q.pop();
				ans[now]=max(ans[now],nans[now]);
				nans[now]=0;
			}
		}
		nans[e[i].v]=max(ans[e[i].u]+1,nans[e[i].v]);
		q.push(e[i].v);
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		ans[now]=max(ans[now],nans[now]);
		nans[now]=0;
	}
	cout<<*max_element(ans+1,ans+n+1)<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}