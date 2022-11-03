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
const int N=1000100;
map<int,int>m;
int n,a[N]={},l[N]={},r[N]={};
long long t[N]={};
inline void add(int pos)
{
	for(int i=pos;i<=n;i+=i&(-i))
		++t[i];
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
		scanf("%d",&a[i]);
}
void work()
{
	for(int i=1;i<=n;++i)
		l[i]=++m[a[i]];
	m.clear();
	for(int i=n;i>=1;--i)
		r[i]=++m[a[i]];
	long long ans=0;
	for(int i=n;i>=1;--i)
	{
		ans+=sum(l[i]-1);
		add(r[i]);
	}
	cout<<ans<<endl;
}
int main()
{	
	//freopen("261D.in","w",stdout);
	//cout<<1000000<<endl;
	//for(int i=1;i<=1000000;++i)
	//	cout<<1<<' ';
	//cout<<endl;
	init();
	work();
	//cout<<clock()<<endl;
	return 0;
}