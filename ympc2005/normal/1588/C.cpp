#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10, inf = 1e9;

int n, tot, mx[N][20], mn[N][20], c[N];

ll a[N], b[N], ans;

vector <int> id[N];

int max_(int l, int r) {
	int k = c[r - l + 1];
	return max(mx[l][k], mx[r - (1<<k) + 1][k]);
}

int min_(int l, int r) {
	int k = c[r - l + 1];
	return min(mn[l][k], mn[r - (1<<k) + 1][k]);
}

void init_() {
	scanf("%d", &n);
	ans = a[0] = b[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] = a[i - 1] + (i&1 ? a[i] : -a[i]);
		b[i] = a[i];
	}
	
	sort(b, b + n + 1);
	tot = unique(b, b + n + 1) - b;
	
	for (int i = 0; i <= tot; i++) {
		id[i].clear();
	}
	
	for (int i = 0; i <= n; i++) {
		a[i] = lower_bound(b, b + tot, a[i]) - b;
		id[a[i]].push_back(i);
	}
	
	for (int i = 2; i <= n; i++) {
		c[i] = c[i>>1] + 1;
	}
		
	for (int i = 1; i <= n; i++) {
		if (i&1) {
			mn[i][0] = a[i];
			mx[i][0] = -inf;
		} else {
			mx[i][0] = a[i];
			mn[i][0] = inf;
		}
	}
		
	for (int k = 1; k <= c[n]; k++) {
		for (int i = 1; i + (1<<k) - 1 <= n; i++) {
			mx[i][k] = max(mx[i][k - 1], mx[i + (1<<k - 1)][k - 1]);
			mn[i][k] = min(mn[i][k - 1], mn[i + (1<<k - 1)][k - 1]);
		}
	}
}

void work_() {	
	for (int i = 0; i < n; i++) {
		int l = i + 1, r = n;
		
		while (l < r) {
			int mid = (l + r + 1)>>1;
			
			if (a[i] <= min_(i + 1, mid) && a[i] >= max_(i + 1, mid)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		
		ans += upper_bound(id[a[i]].begin(), id[a[i]].end(), l) - id[a[i]].begin();
		ans -= upper_bound(id[a[i]].begin(), id[a[i]].end(), i) - id[a[i]].begin();
	}
	
	printf("%lld\n", ans);
}

int main() {
	//freopen("1.in", "r", stdin);
	
	int T; scanf("%d", &T);
	
	while (T--) {
		init_();
		work_();
	}
	
	return 0;
}