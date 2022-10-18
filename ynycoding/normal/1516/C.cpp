#include <cstdio>
#include <map>
#include <bitset>
#include <algorithm>
using std::map;
using std::bitset;
const int N=2005;
int n, a[N], lb=30, cnt, off=N*100;
bitset<N*200> bs;
int main()
{
	scanf("%d", &n);
	bs[off]=1;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", a+i);
		bs=(bs<<a[i])|(bs>>a[i]);
	}
	for(int i=1; i<=n; ++i) lb=std::min(lb, __builtin_ctz(a[i]));
	for(int i=1; i<=n; ++i) if(__builtin_ctz(a[i])==lb) ++cnt;
	if(!bs[off]||(cnt&1)) puts("0");
	else
	{
		puts("1");
		for(int i=1; i<=n; ++i) if(__builtin_ctz(a[i])==lb)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}