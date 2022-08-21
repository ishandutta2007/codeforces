#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	vector<int> ps;
	rep(i, N) if (s[i] == 'P') ps.pb(i);
	vector<int> a(N * 2 + 1, N);
	for (int i = N - 1; i >= 0; i--) {
		a[i] = a[i + 1];
		if (s[i] == '*') a[i] = i;
	}
	if (ps.size() == 1) {
		int m = ps[0];
		int x = 0, y = 0;
		int l = N, r = -1;
		rep(i, N) if (s[i] == '*') {
			if (i < m) x++, l = min(l, i);
			if (i > m) y++, r = max(r, i);
		}
		i_i ans = max(i_i(x, -(m - l)), i_i(y, -(r - m)));
		cout << ans.first << ' ' << -ans.second << endl;
		return 0;
	}
	int star = 0;
	rep(i, N) if (s[i] == '*') star++;
	int lb = 0, ub = N;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		int x = 0, y = -2, prev = -1;
		// cout << mid << endl;
		for (int i: ps) {
			int _x = -2, _y = -2;
			if (x != -2 && i - mid <= a[x]) _x = max(_x, max(i + 1, x));
			if (y != -2 && i - mid <= y && i - mid <= a[prev + 1 + mid]) _x = max(_x, max(i + 1, prev + 1 + mid));
			if (x != -2) _y = max(_y, a[x]);
			if (x != -2 && i <= a[x]) _y = max(_y, N);
			if (y != -2) _y = max(_y, min(y, a[prev + 1 + mid] < i ? a[prev + 1 + mid] : N));
			x = _x, y = _y, prev = i;
			// cout << x << ' ' << y << endl;
		}
		// cout << endl;
		bool ok = false;
		if (x != -2 && a[x] == N) ok = true;
		if (y != -2 && prev < y && a[prev + 1 + mid] == N) ok = true;
		if (ok) ub = mid;
		else lb = mid;
	}
	cout << star << ' ' << ub << endl;
}