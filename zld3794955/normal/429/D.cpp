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
const int N=100100;
int n;
struct psum
{
	long long s;
	int pos;
}a[N]={};
bool cmp(const psum &ps1,const psum &ps2)
{
	return ps1.s<ps2.s;
}
inline long long sqr(long long x)
{
	return x*x;
}
long long ans=0x7fffffff;
map<long long,set<int> >m;
void init()
{
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		a[i].s=a[i-1].s+x;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
		m[a[i].s].insert(a[i].pos);
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		//cout<<"i="<<i<<endl;
		for(int j=i+1;j<=n && sqr(a[j].s-a[i].s)<ans;j=upper_bound(a+j+1,a+n+1,a[j],cmp)-a)
		{
			set<int>::iterator it=m[a[j].s].upper_bound(a[i].pos);
			if(it!=m[a[j].s].end())
				ans=min(ans,sqr(a[j].s-a[i].s)+sqr(*it-a[i].pos));
			if(it!=m[a[j].s].begin())
			{
				--it;
				if(*it==a[i].pos)
				{
					if(it!=m[a[j].s].begin())
						--it;
					else
						continue;
				}
				ans=min(ans,sqr(a[j].s-a[i].s)+sqr(*it-a[i].pos));
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}