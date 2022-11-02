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
const int N=200200;
int n,x[N]={},w[N]={},v[N+N]={},t[N+N]={};
pair<int,int> p[N];
inline void add(int pos,int c)
{
	for(;pos<=n+n;pos+=pos&(-pos))
		t[pos]=max(t[pos],c);
}
inline int premax(int pos)
{
	int s=0;
	for(int i=pos;i;i-=i&(-i))
		s=max(s,t[i]);
	return s;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i)
		x[i]=p[i].first,w[i]=p[i].second;
	int tot=0;
	for(int i=1;i<=n;++i)
		v[++tot]=x[i]+w[i],v[++tot]=x[i]-w[i];
	sort(v+1,v+n+n+1);
}
void work()
{
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int p1=lower_bound(v+1,v+n+n+1,x[i]-w[i])-v;
		int p2=lower_bound(v+1,v+n+n+1,x[i]+w[i])-v;
		int f=premax(p1)+1;
		add(p2,f);
		ans=max(ans,f);
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}