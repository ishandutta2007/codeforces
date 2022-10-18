#include <cstdio>
#include <map>
#define x first
#define y second
using std::map;
int n, m;
map<int, int> a, b;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), ++a[x];
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), ++b[x];
	for(auto it=b.begin(); it!=b.end(); ++it)
	{
		bool ok=1;
		ok=1;
		for(auto it1=a.begin(); it1!=a.end(); ++it1)
		{
			int t=((m+(*it).x%m-(*(a.begin())).x%m)%m+(*it1).x)%m;
			if(!b.count(t)||b[t]!=(*it1).y) { ok=0; break; }
		}
		if(ok) { printf("%d\n", (m+(*it).x%m-(*(a.begin())).x%m)%m); return 0; }
	}
	return 0;
}