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
const int N=100010,M=100010;
struct edge
{
	int u,v,l;
}e[M]={};
bool edge_cmp(const edge &e1,const edge &e2)
{
	return e1.l>e2.l;
}
int n,m,a[N]={},root[N]={},size[N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		e[i].l=min(a[e[i].u],a[e[i].v]);
	}
	sort(e+1,e+m+1,edge_cmp);
}
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
void work()
{
	for(int i=1;i<=n;++i)
		root[i]=i,size[i]=1;
	long long sum=0;
	for(int i=1,p=1;i<=m && p!=n;++i)
	{
		int u_root=get_root(e[i].u);
		int v_root=get_root(e[i].v);
		if(u_root!=v_root)
		{
			++p;
			sum+=(long long)e[i].l*(long long)(size[u_root])*(size[v_root]);
			//cout<<"sum="<<sum<<endl;
			size[u_root]+=size[v_root];
			size[v_root]=0;
			root[v_root]=u_root;
		}
	}
	double ans=sum*1.0/((long long)n*(n-1)/2);
	printf("%.12f\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}