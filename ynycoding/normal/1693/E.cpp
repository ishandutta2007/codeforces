#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
using std::vector;
const int N=200005;

int n, a[N], sum[N], l, r;
ll ans;
vector<int> pos[N];
inline void add(int p, int x) { while(p<=n) sum[p]+=x, p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), pos[a[i]].pb(i);
	l=0, r=n+1;
	for(int i=n; i; --i) if(pos[i].size())
	{
		int cl=pos[i].front(), cr=pos[i].back();
		int nr=std::max(cr, l)+1, nl=std::min(r-1, cl-1);
		ans+=ask(nr-1)-ask(nl);
		for(int x:pos[i]) add(x, 1);
		l=nl, r=nr;
	}
	printf("%lld\n", ans+ask(n));
	return 0;
}