#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=23;
int n, x, y, f[2][1<<N], U, cur, ans;
inline void upt(int &x, int a) { (x<a)&&(x=a); }
int main()
{
	scanf("%d%d%d", &n, &x, &y);
	if(x>y) std::swap(x, y);
	U=(1<<(y+1))-1;
	--n;
	for(int i=0; i<x+y; ++i)
	{
		int v=(n-i+x+y)/(x+y);
		for(int s=0; s<=U; ++s)
		{
			upt(f[cur^1][(s<<1)&U], f[cur][s]);
			if(!(s&(1<<(x-1)))&&!(s&(1<<(y-1) ))) upt(f[cur^1][((s<<1)&U)|1], f[cur][s]+v);
		}
		cur^=1;
	}
	for(int s=0; s<=U; ++s) upt(ans, f[cur][s]);
	printf("%d\n", ans);
	return 0;
}