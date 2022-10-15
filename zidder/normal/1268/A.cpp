#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_set>
#include <map>

#define ll long long
#define dbl long double

using namespace std;
int t;


const long long MOD = 998244353;
const int N = 200000 + 5;
unordered_set<int> T[5 * N];
vector<int> p;
int n;
void build(int l = 0, int r = -1, int v = 1) {
	if (r == -1)
		r = n;
	for (size_t i = l; i < r; i++)
	{
		T[v].insert(p[i]);
	}
	if (r - l == 1)
		return;
	int m = (r + l) / 2;
	build(l, m, 2 * v);
	build(m, r, 2 * v + 1);
}

int find_ind(int x, int v = 1) {
	if (T[v].size() == 1)
		return 0;
	if (T[2 * v].count(x))
		return find_ind(x, 2 * v);
	return T[2 * v].size() + find_ind(x, 2 * v + 1);
}

void remove_int(int x, int v = 1) {
	T[v].erase(x);
	if (T[2 * v].count(x))
		remove_int(x, 2 * v);
	if (T[2 * v + 1].count(x))
		remove_int(x, 2 * v + 1);
}

int ST[N * 4];

int find_left(int x, int l = 0, int r = -1, int v = 1) {
	if (r == -1)
		r = n;
	int m = (r + l) >> 1;
	if (l == m)
		return 0;
	if (m > x)
		return find_left(x, l, m, v * 2);
	else
		return ST[2 * v] + find_left(x, m, r, 2 * v + 1);
}

int find_right(int x, int l = 0, int r = -1, int v = 1) {
	if (r == -1)
		r = n;
	int m = (r + l) >> 1;
	if (m == l)
		return 0;
	if (m > x)
		return ST[2 * v + 1] + find_right(x, l, m, v * 2);
	else
		return find_right(x, m, r, 2 * v + 1);
}

void insret_int(int x, int l=0, int r=-1, int v = 1) { // not a typo
	ST[v]++;
	if (r == -1)
		r = n;
	int m = (r + l) >> 1;
	if (m == l)
		return;
	if (x < m)
		insret_int(x, l, m, 2 * v);
	else
		insret_int(x, m, r, 2 * v + 1);
}

void solve(int testid) {
	string s;
	int n, k;
	cin >> n >> k;
	cin >> s;
	int ind = 0;
	for (; ind + k < s.size(); ind++)
	{
		if (s[ind] != s[ind + k])
			break;
	}
	if (ind + k < s.size()) {
		if (s[ind] < s[ind + k]) {
			for (ind = k - 1; ind >= 0; ind--) {
				if (s[ind] < '9') {
					s[ind]++;
					break;
				}
			}
			for (ind++; ind < k; ++ind)
				s[ind] = '0';
		}
		ind = 0;
		for (; ind + k < s.size(); ++ind) {
			s[ind + k] = s[ind];
		}
	}
	cout << s.size() << endl;
	cout << s << endl;
	return;
	cin >> n;
	p = vector<int>(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		mp[p[i]] = i;
	}
	build();
	vector<ll> ans(n + 1);
	for (int i = 2; i <= n; i++)
	{
		ans[i] = ans[i - 1];
		int ind1 = find_ind(1), indi = find_ind(i);
		if (ind1 < indi) {
			ans[i] += indi - ind1 - 1;
			ans[i] -= find_right(mp[i]) * 2;
		}
		else {
			ans[i] += ind1 - indi + i - 2;
			ans[i] -= find_left(mp[i]) * 2;
		}
		remove_int(i);
		insret_int(mp[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", ans[i]);
	}
	cout << endl;
}

int main() {
	t = 1;
	// cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*

*/