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
const int N=505000;
int n,a[N]={};
long long s1[N]={},s2[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		s1[i]=s1[i-1]+a[i];
	for(int i=n;i>=1;--i)
		s2[i]=s2[i+1]+a[i];
}
void work()
{
	if(s1[n]%3)
	{
		cout<<0<<endl;
		return;
	}
	long long ans=0,sv=s1[n]/3,t=0;
	s1[0]=1ll<<60;
	for(int i=1;i<=n;++i)
	{
		if(s2[i]==sv)
			ans+=t;
		if(s1[i-1]==sv)
			++t;
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}