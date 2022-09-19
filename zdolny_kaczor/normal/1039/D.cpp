# include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define dor > debug &operator<<
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug&>::type operator<<(c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud (c *x) -> decltype(cerr << *x, 0);
sim> char dud(...);
struct debug {
	#ifdef DEB
	~debug() {cerr << endl;}
	eni(==) ris << range(begin(i), end(i));}
	eni(!=) cerr << boolalpha << i; ris;}
	sim, class b dor(pair <b,c> r) {ris << "<" << r.first << ", " << r.second << ">";}
	sim dor (rge<c> x) {cerr << "{";
		for (c it = x.b; it != x.e; ++it)
			*this << ", " + 2 * (it == x.b) << *it;
		ris << "}";
	}
	#else
	sim dor (const c&) {ris;}
	#endif
};
#define imie(a...) "[" #a ": " << (a) << "] "
#define imask(a...) "[" #a ": " << bitset<8 * sizeof(a)>(a) << "] "
#define arr(a, i) "[" #a imie(i) " : " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) " : " << a[i][j] << "] "
#define debug debug() << "[" << __FUNCTION__ << "#"	<< __LINE__ << "] "
const int MN = 1e5 + 44;
vector <int> graf[MN];
void clean(int x, int y = -1) {
	for (int i = 0; i < graf[x].size(); ++i) {
		if (graf[x][i] == y) {
			graf[x][i] = graf[x].back();
			graf[x].pop_back();
			i--;
		}
		else
			clean(graf[x][i], x);
	}
}
int ans[MN];
int root;
pair <int, int> dfs(int x, int k) {
	int total = 0;
	int best[2] = {0, 0};
	for (int v : graf[x]) {
		pair <int, int> x = dfs(v, k);
		total += x.first;
		for (int i = 0; i < 2; ++i)
			if (best[i] < x.second)
				swap(best[i], x.second);
	}
	if (best[0] + best[1] + 1 >= k)
		return make_pair(total + 1, 0);
	else
		return make_pair(total, best[0] + 1);
}
int solve(int m) {
	return dfs(root, m).first;
}
int n;
void run(int l, int r, int lower, int upper) {
	if (l > r) return;
	debug << imie(l) imie(r) imie(lower) imie(upper);
	if (lower == upper) {
		for (int i = l; i <= r; ++i)
			ans[i] = lower;
		return;
	}
	int m = (4 * l + r * 3) / 7;
	ans[m] = solve(m);
	run(l, m - 1, ans[m], upper);
	run(m + 1, r, lower, ans[m]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		if (graf[i].size() == 1u) {
			root = i;
			break;
		}
	clean(root);
	ans[1] = n;
	run(2, n, 0, n);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
}