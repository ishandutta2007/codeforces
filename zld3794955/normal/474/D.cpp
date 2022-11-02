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
const int V=100100,mod=1000000007;
int t,k,a[V]={},maxv=100000;
void init()
{
	scanf("%d%d",&t,&k);
	for(int i=0;i<k;++i)
		a[i]=1;
	for(int i=k;i<=maxv;++i)
		a[i]=(a[i-k]+a[i-1])%mod;
	for(int i=1;i<=maxv;++i)
		a[i]=(a[i]+a[i-1])%mod;
}
void work()
{
	for(int i=1,x=0,y=0;i<=t;++i)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",(a[y]-a[x-1]+mod)%mod);
	}
}
int main()
{	
	init();
	work();
	return 0;
}