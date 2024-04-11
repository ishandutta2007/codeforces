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
int n,m,a[N]={},b[M]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int j=1;j<=m;++j)
		scanf("%d",&b[j]);
}
long long calc(long long bar)
{
	long long sum=0;
	for(int i=1;i<=n;++i)
		sum+=max(0ll,bar-a[i]);
	for(int j=1;j<=m;++j)
		sum+=max(0ll,b[j]-bar);
	return sum;
}
void work()
{
	long long l=1,r=1000000000;
	while(r-l>2)
	{
		long long mid1=(l+l+r)/3,mid2=(l+r+r)/3;
		if(calc(mid1)<calc(mid2))
			r=mid2;
		else
			l=mid1;
	}
	long long ans=0x7fffffffffffffffll;
	for(int i=l;i<=r;++i)
		ans=min(calc(i),ans);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}