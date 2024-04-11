#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
const int SEED = 13331;
const int MAX_LOG = 20;

int h[MAX_N], n;
int nQ;
int delta[MAX_N]; //h_i-h_{i-1}
int ndelta[MAX_N]; //-delta[i]
struct Hash {
	int a[MAX_N], n;
	int h[MAX_N][MAX_LOG];
	void init(int _a[], int _n) {
		n = _n;
		for (int i = 0; i < n; ++i) {
			a[i] = _a[i];
		}
	}
};

struct Suffix {
	Hash*h;
	int l;
	bool minE;
	int n;

	Suffix(Hash*_h, int _l) :
			h(_h), l(_l) {
		n = h->n - l;
		minE = true;
	}

	Suffix() {
	}
	int len() const {
		return n;
	}
	int get(int a) const {
		if (a == n)
			return minE ? -INT_MAX : INT_MAX;
		return h->a[l + a];
	}
};

bool operator<(const Suffix&a, const Suffix&b) {
	int n = min(a.len(), b.len());
	int ka = a.l, kb = b.l;
	Hash&ha = *a.h, &hb = *b.h;
	for (int i = 20 - 1; i >= 0; --i) {
		if ((1 << i) <= n) {
			if (ha.h[ka][i] == hb.h[kb][i]) {
				ka += 1 << i;
				kb += 1 << i;
				n -= 1 << i;
			}
		}
	}
	return a.get(ka - a.l) < b.get(kb - b.l);
}

Suffix nsfxs[MAX_N];
Hash hsh, nhsh;
pair<int, int> ps[MAX_N * 2];
int perm[MAX_N * 2];
int rank[MAX_N * 2];

bool cmp(int a, int b) {
	return ps[a] < ps[b];
}

void doit() { //doit for hsh and nhsh
	for (int lg = 0; (1 << lg) <= hsh.n; ++lg) {
		int len = 1 << lg;
		int cnt = 0;
		for (int i = 0; i + len <= hsh.n; ++i) {
			if (!lg) {
				ps[cnt++] = make_pair(hsh.a[i], hsh.a[i]);
			} else {
				ps[cnt++] = make_pair(hsh.h[i][lg - 1], hsh.h[i + (1 << (lg - 1))][lg - 1]);
			}
		}
		for (int i = 0; i + len <= nhsh.n; ++i) {
			if (!lg) {
				ps[cnt++] = make_pair(nhsh.a[i], nhsh.a[i]);
			} else {
				ps[cnt++] = make_pair(nhsh.h[i][lg - 1], nhsh.h[i + (1 << (lg - 1))][lg - 1]);
			}
		}
		for (int i = 0; i < cnt; ++i) {
			perm[i] = i;
		}
		sort(perm, perm + cnt, cmp);
		int nId = 0;
		for (int i = 0; i < cnt; ++i) {
			if (!i || ps[perm[i]] != ps[perm[i - 1]])
				rank[perm[i]] = nId++;
			else
				rank[perm[i]] = nId - 1;
		}

		cnt = 0;
		for (int i = 0; i + len <= hsh.n; ++i) {
			hsh.h[i][lg] = rank[cnt++];
		}
		for (int i = 0; i + len <= nhsh.n; ++i) {
			nhsh.h[i][lg] = rank[cnt++];
		}
	}
}

struct TA {
	int a[MAX_N], n;
	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof a);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	int get(int p) {
		int r = 0;
		for (p++; p; p -= p & -p)
			r += a[p - 1];
		return r;
	}
} ta;

void getInterval(Suffix a, int lcp, int&l, int&r) {
	//the interval in nhsh that has lcp-length lcp with a
	a.n = lcp;
	a.minE = true;
	//first >=a
	l = lower_bound(nsfxs, nsfxs + n - 1, a) - nsfxs;
	a.minE = false;
	r = upper_bound(nsfxs, nsfxs + n - 1, a) - nsfxs;
}

int ans[MAX_N];

struct Query {
	int r;
	int*ret;
	int add;
	Query(int _r, int _add, int*_ret) :
			r(_r), add(_add), ret(_ret) {
	}
};

vector<Query> byhere[MAX_N];

void addQuery(int l, int r, int L, int R, int*ret) {
	if (L > R || l > r)
		return;
	//[l,r]
	byhere[r].push_back(Query(R, 1, ret));
	byhere[r].push_back(Query(L - 1, -1, ret));
	if (l > 0) {
		byhere[l - 1].push_back(Query(R, -1, ret));
		byhere[l - 1].push_back(Query(L - 1, 1, ret));
	}
}

void processQuery() {
	ta.init(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		ta.add(nsfxs[i].l, 1);
		for (vector<Query>::iterator it = byhere[i].begin(); it != byhere[i].end(); ++it) {
			*it->ret += it->add * ta.get(it->r);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", h + i);
	}
	for (int i = 0; i + 1 < n; ++i) {
		delta[i] = h[i + 1] - h[i];
		ndelta[i] = -delta[i];
	}
	hsh.init(delta, n - 1);
	nhsh.init(ndelta, n - 1);
	doit();
	for (int i = 0; i < n - 1; ++i) {
		nsfxs[i] = Suffix(&nhsh, i);
	}
	sort(nsfxs, nsfxs + n - 1);

	scanf("%d", &nQ);
	for (int i = 0; i < nQ; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		//h_l,..,h_{r-1}
		if (l == r) {
			ans[i] = n - 1;
			continue;
		}
		int w = r - l;
		int aL, aR;
		getInterval(Suffix(&hsh, l), w, aL, aR);
		if (aL < aR) { //[l,r)
			//[x,y+1] \ [l,r]
			//y+1<l || x>r
			//y+1=x+w
			//x<l-w ,x>r
			//[0,l-w-1],[r+1,n-2]
			addQuery(aL, aR - 1, 0, l - w - 1, ans + i);
			addQuery(aL, aR - 1, r + 1, n - 2, ans + i);
		} else {
			ans[i] = 0;
			continue;
		}
	}
	processQuery();
	for (int i = 0; i < nQ; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}