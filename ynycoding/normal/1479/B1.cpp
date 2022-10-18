#include <cstdio>
#include <cstring>
#include <tuple>
#include <algorithm>
#define mp std::make_tuple
using std::tuple;
const int N=100005;
int n, a[N], cnt, tp;
tuple<int, int, int> t[3], g[6];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i)
	{
		tp=0;
		for(int j:{0, 1, 2})
		{
			auto [z, x, y]=t[j];
			g[tp++]=mp(z-(x!=a[i]), a[i], y);
			g[tp++]=mp(z-(y!=a[i]), x, a[i]);
		}
		std::sort(g, g+6);
		tp=std::unique(g, g+6)-g;
		std::copy(g, g+3, t);
		for(int i=tp; i<3; ++i) t[i]=mp(0x3f3f3f3f, 0, 0);
	}	
	printf("%d\n", -std::get<0>(t[0]));
	return 0;
}