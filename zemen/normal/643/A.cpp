#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int maxn = 111111;

int n, a[maxn], cnt[maxn];
int ans[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cnt[j] = 0;
		}
		int mx = 0;
		for (int j = i; j < n; ++j) {
			cnt[a[j]]++;
			if (mp(cnt[a[j]], -a[j]) > mp(cnt[mx], -mx)) {
				mx = a[j];
			}
			ans[mx]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
  return 0;
}