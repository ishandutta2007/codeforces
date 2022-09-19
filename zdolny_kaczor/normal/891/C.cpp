#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2 cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
#define debug(...)
#define debug2 if(0) cout
#endif
template <typename T, typename C>
ostream & operator<<(ostream &os, pair<T, C> x) {
	return os << "<" << x.f << ", " << x.s << ">";
}
template <typename T>
auto operator<<(ostream&os, T x) -> typename enable_if<is_same<decltype(x.begin()), decltype(x.end())>::value && !is_same<T, string>::value, ostream &>::type {
	os << "{";
	int cou = 0;
	for (auto c : x) {
		if (cou++)
			os << ", ";
		os << c;
	}
	return os << "}";
}
#define cr << "][" << 
#define rr << "] = " << 
#define cc << "[" <<
#define name(a) #a << " = " << (a)
#define arr(a, i) #a cc #i rr #a cc i rr a[i]
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j]
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k]
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q]
template <typename T>
string strmask(T r) {
	string ans;
	REP(i, 8 * (int)sizeof(T)) {
		ans += '0' + !!(((T)1 << i) & r);
		if (i % 5 == 4)
			ans += '.';
	}
	return ans;
}
#define nmask(a) #a << " = " << strmask(a)
const int MN = 5e5 + 44;
int u[MN];
int find(int x) {
	if (u[x] == x)
		return x;
	else return u[x] = find(u[x]);
}
void onion(int a, int b) {
	u[find(a)] = find(b);
}
void reset(int a) {
	u[a] = a;
}
#define nr f.s
#define cost f.f
#define x s.f
#define y s.s
#define left santohee
#define right sathaoe
pair <PII, PII> edges[MN];
int left[MN], right[MN], costs[MN];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges[i] = MP(MP(c, i), MP(a, b));
		costs[i] = c;
	}
	sort(edges + 1, edges + m + 1);
	for (int i = 0; i <= n; ++i)
		reset(i);
	int last = 1;
	for (int i = 1; i <= m; ++i) {
		debug2 << arr(edges, i) << endl;
		if (i == m || edges[i].cost != edges[i + 1].cost) {
			debug2 << "merge from " << name(last) << endl;
			for (int k = last; k <= i; ++k) {
				debug2 << arr(edges, k) << endl;
				left[edges[k].nr] = find(edges[k].x);
				right[edges[k].nr] = find(edges[k].y);
				debug2 << "set " << arr(left, edges[k].nr) << arr(right, edges[k].nr) << endl;
			}
			for (int k = last; k <= i; ++k)
				onion(edges[k].x, edges[k].y);
			last = i + 1;
		}
	}
	for (int i = 0; i <= n; ++i)
		reset(i);
	int q;
	scanf("%d", &q);
	while (q--) {
		int curr = 0;
		scanf("%d", &curr);
		VI qu;
		bool good = true;
		while (curr--) {
			int yy;
			scanf("%d", &yy);
			qu.PB(yy);
		}
		debug2 << qu << endl;
		for (int yy : qu) {
			int l = left[yy], r = right[yy];
			debug2 << "merge " << name(l) << name(r) << endl;;
			if (find(l) == find(r))
				good = false;
			onion(l, r);
		}
		for (int yy : qu) {
			reset(left[yy]);
			reset(right[yy]);
		}
		if (good)
			printf("YES\n");
		else
			printf("NO\n");
	}
}