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
const int N=200020;
struct bear
{
	int a,pos;
}t[N]={};
bool bear_cmp(const bear &b1,const bear &b2)
{
	return b1.a>b2.a;
}
int n,ans[N]={};
struct DSU
{
	int root[N];
	void init()
	{
		for(int i=0;i<=n+1;++i)
			root[i]=i;
	}
	int get_root(int r)
	{
		if(r!=root[r])
			root[r]=get_root(root[r]);
		return root[r];
	}
	void mergeto(int u,int v)
	{
		u=get_root(u);
		v=get_root(v);
		root[u]=v;
	}
}T1,T2;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&t[i].a);
		t[i].pos=i;
	}
	T1.init(),T2.init();
	sort(t+1,t+n+1,bear_cmp);
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		T1.mergeto(t[i].pos,t[i].pos-1);
		T2.mergeto(t[i].pos,t[i].pos+1);
		int l=T2.get_root(t[i].pos)-T1.get_root(t[i].pos)-1;
		ans[l]=max(ans[l],t[i].a);
	}
	for(int i=n;i>=1;--i)
		ans[i]=max(ans[i],ans[i+1]);
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i]," \n"[i==n]);
}
int main()
{
	init();
	work();
	return 0;
}