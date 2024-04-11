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
const int N=100010;
int n,a[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}
void work()
{
	long long ans=0,x=0;
	int i=n;
	while(i)
	{
		if(a[i]==a[i-1] || a[i]==a[i-1]+1)
		{
			if(x)
				ans+=x*a[i-1],x=0;
			else
				x=a[i-1];
			i-=2;
		}
		else
			--i;
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}