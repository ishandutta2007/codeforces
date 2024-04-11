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
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif

#define count natoehu
const LL llinf = 1ll << 59;
map <int, vector <int> > count;

const int MN = 1e5 + 44;

map <int, int> cols;

struct block {
	static int all;
	int nr;
	int color;
	int size;
	void read() {
		nr = all;
		all++;
		scanf("%d%d", &color, &size);
		cols[color] = 0;
	}
};

int block::all = 1;

block in[MN];

vector <block *> add[MN];

vector <block *> colors[MN];

LL sum[MN];

pair <LL, int> opt[MN][2];

void inc(pair <LL, int> val, int x) {
	debug("inc (%lld, %d) in %d\n", val.f, val.s, x);
	for (int i = 0; i < 2; ++i) {
		debug("iter %d with %lld, %d\n", i, val.f, val.s);
		if (opt[x][i] < val) {
			debug("%d: (%lld, %d), (%lld, %d)\n", x, opt[x][0].f, opt[x][0].s, opt[x][1].f, opt[x][1].s);
			swap(val, opt[x][i]);
			debug("%d: (%lld, %d), (%lld, %d)\n", x, opt[x][0].f, opt[x][0].s, opt[x][1].f, opt[x][1].s);
		}
	}
}

LL max_but(int count, int forb) {
	debug("max but %d %d = ", count, forb);
	if (opt[count][0].s == forb) {
		debug("%lld\n", opt[count][1].f);
		return opt[count][1].f;
	}
	else {
		debug("%lld\n", opt[count][0].f);
		return opt[count][0].f;
	}
}

bool cmp(block * a, block * b) {
	return a -> size > b -> size;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		in[i].read();
	}
	int count = 0;
	for (auto & x : cols) {
		x.s = count++;
	}
	for (int i = 0; i < n; ++i) {
		in[i].color = cols[in[i].color];
		colors[in[i].color].PB(&in[i]);
	}
	for (int i = 0; i < n; ++i) {
		sort(ALL(colors[i]), cmp);
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < siz(colors[i]); ++k) {
			add[k].PB(colors[i][k]);
		}
	}
	opt[0][0] = opt[0][1] = MP(0, 0);
	for (int c = 1; c <= n; c++) {
		opt[c][0] = opt[c][1] = MP(-llinf, -1);
		for (auto x : add[c - 1]) {
			sum[x -> color] += x -> size;
			inc(MP(sum[x -> color], x -> color), c);
		}
	}
	for (int i = 0; i < 3; ++i) {
		debug("%d: (%lld, %d), (%lld, %d)\n", i, opt[i][0].f, opt[i][0].s, opt[i][1].f, opt[i][1].s);
	}
	auto res = MP(0LL, MP(-1, -1));
	for (int i = 0; i < count; ++i) {
		for (int ile = max(0, siz(colors[i]) - 1); ile <= min(n, siz(colors[i]) + 1); ++ile)
			maxi(res, MP(sum[i] + max_but(ile, i), MP(i, ile)));
	}
	printf("%lld\n", res.f);
	printf("%d\n", siz(colors[res.s.f]) + res.s.s);
	pair <vector <block *> *, int> use[2];
	use[0] = MP(&colors[res.s.f], siz(colors[res.s.f]));
	use[1].s = res.s.s;
	use[1].f = & colors[(opt[res.s.s][0].s == res.s.f) ? opt[res.s.s][1].s : opt[res.s.s][0].s];
	if (use[0].s < use[1].s)
		swap(use[0], use[1]);
	for (int k = 0; k < 2; ++k)
		debug("use: %d %d\n", use[k].first - colors, use[k].second);
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < 2; ++k) { 
			if (i < use[k].second) {
				printf("%d ", use[k].first -> at(i) -> nr);
			}
		}
	}
	printf("\n");
}