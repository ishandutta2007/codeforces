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
const int N=2020,H=2020,mod=1000000007;
int n,h,a[N]={};
void init()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void work()
{
	for(int i=1;i<=n;++i)
		if(a[i]>h)
		{
			cout<<0<<endl;
			return;
		}
	a[0]=a[n+1]=h;
	int now=0;
	long long ans=1;
	for(int i=1;i<=n+1;++i)
	{
		int delta=h-a[i];
		if(delta==now)
			ans=ans*(now+1)%mod;
		else
			if(delta-now==1)
				++now;
			else
				if(delta-now==-1)
				{
					ans=ans*now%mod;
					--now;
				}
				else
				{
					cout<<0<<endl;
					return;
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