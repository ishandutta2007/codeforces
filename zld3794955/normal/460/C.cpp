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
const int N=100010;
int n,m,w,a[N]={},u[N+N]={},*d=&u[N];
void init()
{
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
bool check(int h)
{
	int s=0,ns=0;
	for(int i=1;i<=n;++i)
	{
		d[i]=0;
		ns-=d[i-w];
		if(a[i]+ns<h)
		{
			int delta=h-a[i]-ns;
			s+=delta;
			ns+=delta;
			d[i]=delta;
		}
		if(s>m)
			return false;
	}
	return true;
}
void work()
{
	int l=1,r=1010000000;
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}