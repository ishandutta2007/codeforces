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
const int N=401000;
int n,a[N]={},b[N]={},c[N]={},d[N]={},tmp[N]={};
map<int,int> m;
long long t[N]={};
inline void add(int pos,int c)
{
	for(int i=pos;i<=n;i+=i&(-i))
		t[i]+=c;
}
inline long long sum(int pos)
{
	long long s=0;
	for(int i=pos;i;i-=i&(-i))
		s+=t[i];
	return s;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(!m.count(a[i]))
			m[a[i]]=a[i];
		if(!m.count(b[i]))
			m[b[i]]=b[i];
		swap(m[a[i]],m[b[i]]);
	}
	int tot=0;
	for(auto p:m)
	{
		++tot,c[tot]=p.first-c[tot-1]-1,d[tot]=c[tot-1]+1;
		++tot,c[tot]=p.first,d[tot]=p.second;
	}
	for(int i=2;i<=tot;i+=2)
		c[i]=1;
	n=tot;
}
void work()
{
	long long ans=0;
	copy(d+1,d+n+1,tmp+1);
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n;++i)
		d[i]=lower_bound(tmp+1,tmp+n+1,d[i])-tmp;
	fill(t+1,t+n+1,0ll);
	for(int i=n;i>=1;--i)
	{
		ans+=c[i]*sum(d[i]);
		add(d[i],c[i]);
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}