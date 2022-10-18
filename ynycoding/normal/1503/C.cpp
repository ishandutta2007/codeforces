#include <cstdio>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f
const int N=100005;
using std::min;
using std::max;
using std::abs;
int n, a[N], c[N], id[N], ra[N], ans;
ll sum;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", a+i, c+i), sum+=c[i], id[i]=i;
	std::sort(id+1, id+n+1, [] (int x, int y) { return a[x]<a[y]; } );
	for(int i=1; i<=n; ++i) ra[i]=a[id[i]];
	for(int i=1, pr=a[id[1]]; i<=n; ++i)
	{
		int u=id[i];
		ans+=max(0, a[u]-pr);
		pr=std::max(pr, a[u]+c[u]);
	}
	printf("%lld\n", ans+sum);
	return 0;
}