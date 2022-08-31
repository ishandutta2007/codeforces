#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	ll a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	ll ret=2LL*c+min(a,b)*2LL;
	if(a!=b) ret++;
	printf("%lld\n",ret);
	return 0;
}