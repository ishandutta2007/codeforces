#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <functional>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll solve(ll n,ll x)//x=1,2,...,n
{
	if(n==1) return 1;
	if(n%2==0)
	{
		if(x%2==1) return (x+1LL)/2LL;
		return solve(n/2,x/2)+n/2;
	}
	else
	{
		if(x%2==1) return (x+1LL)/2LL;
		return solve((n+1)/2,x/2+1)+(n-1)/2;
	}
}
int main()
{
	ll n;
	int q;
	scanf("%lld %d",&n,&q);
	for(int i=0;i<q;i++)
	{
		ll x;
		scanf("%lld",&x);
		printf("%lld\n",solve(n,x));
	}
	return 0;
}