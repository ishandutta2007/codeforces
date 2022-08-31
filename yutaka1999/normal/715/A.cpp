#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <stack>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	ll now=2;
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++)
	{
		ll nxt=(ll) i*(ll) (i-1);
		printf("%lld\n",(nxt/(i-1))*nxt-now/(i-1));
		now=nxt;
	}
	return 0;
}