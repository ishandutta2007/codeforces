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
const int N=3030;
struct edge
{
	int u,v,l;
}e[N]={};
bool edge_cmp(const edge &e1,const edge &e2)
{
	return e1.l<e2.l;
}
int n,root[N]={},s1[N]={},s2[N]={},sum1=0,sum2=0;
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
void print_root()
{
	for(int i=1;i<=n;++i)
		get_root(i);
	for(int i=1;i<=n;++i)
		cout<<root[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<s1[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<s2[i]<<' ';
	cout<<endl;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
	sort(e+1,e+n,edge_cmp);
	for(int i=1;i<=n;++i)
		root[i]=i,s1[i]=1,scanf("%d",&s2[i]);
	sum1=n;
	sum2=accumulate(s2+1,s2+n+1,0);
}
void work()
{
	int i=0;
	for(i=1;i<n;++i)
	{
		int u=get_root(e[i].u),v=get_root(e[i].v);
		root[v]=u;
		s1[u]+=s1[v];
		s2[u]+=s2[v];
		if(s1[u]>sum2-s2[u])
			break;
	}
	cout<<e[i].l<<endl;
}
int main()
{
	init();
	work();
	return 0;
}