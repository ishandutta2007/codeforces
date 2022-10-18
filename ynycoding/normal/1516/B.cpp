#include <cstdio>
#include <map>
#include <algorithm>
using std::map;
const int N=2005;
int T, n, a[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), a[i]^=a[i-1];
		int l=1;
		while(a[l]!=a[n]) ++l;
		int r=n;
		while(r&&a[r]) --r;
		puts((!a[n]||l<r)?"YES":"NO");
	}
	return 0;
}