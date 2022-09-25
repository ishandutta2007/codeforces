#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

const int maxn = 222222;

int n, k, q, t[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < n; ++i) cin >> t[i];
	set<int, greater<int> > foo;
	for (int i = 0; i < q; ++i) {
		int type, id;
		cin >> type >> id;
		if (type == 1) {
			foo.insert(t[id - 1]);
			while ((int) foo.size() > k)
				foo.erase(--foo.end());
		} else {
			puts(foo.count(t[id - 1]) ? "YES" : "NO");
		}
	}
  return 0;
}