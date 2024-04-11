#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 800054;

int n;
pr a[N];
ll ans;

template <typename C>
struct heap_with_offset {
	std::priority_queue <ll, std::vector <ll>, C> pq;
	ll offset;

	heap_with_offset() : offset(0) {}
	inline void gadd(ll x) {offset += x;}
	inline void insert(ll x) {pq.emplace(x - offset);}
	inline ll top() const {return pq.top() + offset;}
	inline ll pop() {ll ret = top(); return pq.pop(), ret;}
	inline bool empty() const {return pq.empty();}
	inline int size() const {return pq.size();}
};

heap_with_offset <std::less <ll>> L;
heap_with_offset <std::greater <ll>> R;

inline void insert(int x) {R.empty() || x >= R.top() ? R.insert(x) : L.insert(x);}

inline void adjust() {
	for (; L.size() > R.size(); R.insert(L.pop()));
	for (; L.size() < R.size(); L.insert(R.pop()));
}

int main() {
	int i, j, x, y, la = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> x >> y, a[i] = pr(x + y, -x);
	std::sort(a, a + n);
	for (j = i = 0; i < n; ) {
		for (; j < n && a[i].first == a[j].first; ++j) ans -= a[j].second;
		L.gadd(la - a[i].first), la = a[i].first;
		for (; i < j; ++i) insert(a[i].second), insert(a[i].second), adjust();
	}
	for (; !R.empty(); ans += R.pop());
	cout << ans << '\n';
	return 0;
}