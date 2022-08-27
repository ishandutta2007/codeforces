#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef std::pair <int, int> pr;
const int N = 108;

int n, count[N];
pr a[N];

inline pr get() {int x, y; return cin >> x >> y, pr(x, y);}
inline void insert(int x) {cout << '+' << ' ' << x << endl;}

int R(int x) {return ((int)sqrt(x * 8 + 1) + 1) / 2;}

inline bool find(int *ret) {
	int i, D, p, q, r, s; bool flag; static int tmp[N];
	memcpy(tmp, ret, (n + 1) << 2);
	for (i = 1; i <= n; ++i)
		if (!~ret[i]) {
			D = a[i - 2].second - a[i - 1].second,
			D -= ret[i - 3] * (ret[i - 1] + 1 + (i > 4 ? count[i - 4] : 0));
			if (D % (ret[i - 1] + 1)) return memcpy(ret, tmp, (n + 1) << 2), false;
			ret[i] = D / (ret[i - 1] + 1) - (i != n);
			if (ret[i] < 0 || (i < n && ret[i] > 1)) return memcpy(ret, tmp, (n + 1) << 2), false;
		}
	for (D = 0, i = 2; i < n; ++i) D += ret[i - 1] * ret[i] * ret[i + 1];
	flag = D == a[n].second;
	for (i = n - 1; i && flag; --i)
		p = (i > 2 ? ret[i - 2] : 0), q = ret[i - 1], r = ret[i + 1] + (i < n - 1), s = ret[i + 2] + (i < n - 2),
		D += (p + r) * (q + s) - p * s, flag &= D == a[i].second;
	return flag || (memcpy(ret, tmp, (n + 1) << 2), false);
}

int main() {
	int i, start;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n, a[n] = get(), memset(count + 1, -1, n << 2);
	for (i = n - 1; i; --i)
		if (insert(i), a[i] = get(), a[i].first != a[i + 1].first)
			count[i] = R(a[i].first - a[i + 1].first);
	if (~(count[1] & count[2])) {
		for (start = 1; start < n && ~count[start]; ++start);
		if (start < n) insert(start), *a = get(), count[start] = R(a->first - a[1].first) - 1;
		assert(find(count));
	} else if (n == 4 && !a[2].second && !a[1].first && a[1].second == 2)
		insert(2), memset(count + 1, 0, n << 2), count[2 + (get().second == 4)] = 1;
	else {
		insert(1), *a = get(), count[1] = R(a->first - a[1].first) - 1, count[2] = 0;
		if (!find(count)) count[2] = 1, assert(find(count));
	}
	cout << '!';
	for (i = 1; i <= n; ++i) cout << ' ' << count[i];
	cout << endl;
	return 0;
}