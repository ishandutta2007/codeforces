#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll l,r;
	if(k%2LL==0)
	{
		l=k/2LL-1LL;
		r=k/2LL+1LL;
	}
	else
	{
		l=(k-1LL)/2LL;
		r=(k+1LL)/2LL;
	}
	ll ret=max(0LL,min(l,n-r+1LL));
	printf("%lld\n",ret);
	return 0;
}