#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#define mp std::make_pair
#define x first
#define y second
#define pb push_back
using std::set;
using std::vector;
using std::multiset;
using std::pair;

const int N=2005, MOD=1000000007;

inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }

int n, k, L, x[N], y[N], c[N];
int ans, cur;
pair<pair<int, int>, int> p[N];
set<pair<int, int> > st;
multiset<int> pos[N];
inline void ins(int x, int y)
{
	auto it=prev(st.lower_bound(mp(x, L+1)));
	auto t=*it;
	int nx=next(it)->x;
	if(it->y<=y) return;
	int pr=x+1;
	vector<pair<int, int> > tmp;
	while(it->y>=y)
	{
		tmp.pb(*it);
		dec(cur, 1ll*(it->y-y)*(pr-it->x)%MOD);
		pr=it->x;
		--it;
	}
	for(auto x:tmp) st.erase(x);
	st.insert(mp(pr, y));
	if(x+1<nx) st.insert(mp(x+1, t.y));
}
int main()
{
	scanf("%d%d%d", &n, &k, &L);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", &p[i].x.x, &p[i].x.y, &p[i].y);
	std::sort(p+1, p+n+1);
	for(int i=1; i<=n; ++i) x[i]=p[i].x.x+1, y[i]=p[i].x.y+1, c[i]=p[i].y;
	for(int i=1, r, pr=0; i<=n; i=r+1)
	{
		r=i;
		while(r<n&&x[r+1]==x[i]) ++r;
		for(int i=1; i<=k; ++i) pos[i].clear();
		int len=x[i]-pr;
		st.clear();
		st.insert(mp(0, -1));
		st.insert(mp(1, L));
		st.insert(mp(L+1, L+1));
		cur=1ll*L*L%MOD;
		for(int j=i; j<=n; ++j)
		{
			pos[c[j]].insert(y[j]);
		}
		for(int i=1; i<=k; ++i)
		{
			if(pos[i].empty()) goto out;
			int pr=0;
			for(int x:pos[i])
			{
				ins(x-1, pr);
				pr=x;
			}
			ins(L, pr);
		}
		for(int j=n, l, ls=L+1; j>=i; j=l-1)
		{
			l=j;
			while(l>1&&x[l-1]==x[j]) --l;
			inc(ans, 1ll*len*(ls-x[l])%MOD*cur%MOD);
			ls=x[l];
			for(int k=l; k<=j; ++k)
			{
				pos[c[k]].erase(pos[c[k]].find(y[k]));
				if(pos[c[k]].empty()) goto out;
				auto it=pos[c[k]].lower_bound(y[k]);
				ins((it==pos[c[k]].end()?L:*it-1), (it==pos[c[k]].begin()?0:*prev(it)));
			}
		}
		out:;
		pr=x[i];
	}
	printf("%d\n", ans);
	return 0;
}