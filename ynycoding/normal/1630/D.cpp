#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
const int N=1000005;
using std::vector;
int T, n, m, a[N], d;
vector<int> e[N];
ll sum;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		d=0;
		sum=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i), sum+=a[i];
		for(int i=1, x; i<=m; ++i) scanf("%d", &x), d=std::__gcd(d, x);
		for(int i=0; i<d; ++i) e[i].clear();
		for(int i=1; i<=n; ++i) e[i%d].pb(a[i]);
		ll a0=0, a1=0;
		for(int i=0; i<d; ++i)
		{
			std::sort(e[i].begin(), e[i].end());
			ll cur=0, m0=0, m1=-0x3f3f3f3f3f3f3f;
			int c=0;
			for(int x:e[i])
			{
				c^=1;
				cur-=x;
				if(c) m1=std::max(m1, cur);
				else m0=std::max(m0, cur);
			}
			a0+=m0, a1+=m1;
		}
		printf("%lld\n", sum+std::max(a0, a1)*2);
	}
	return 0;
}