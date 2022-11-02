#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;
 
const int maxn = 1000;
int n, m;
pair<int, int> a[maxn + 5];
pair<pair<int, int>, int> pr[maxn + 5];
 
int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i].first), a[i].second = i;
	int c = 0;
	rep(i, 1, n) rep(j, i + 1, n) c += a[i] > a[j];
	printf("%d\n", c);
	rep(i, 1, n) {
		m = 0;
		rep(j, i + 1, n) if (a[j] < a[i]) pr[++m] = make_pair(a[j], j);
		sort(pr + 1, pr + m + 1), reverse(pr + 1, pr + m + 1);
		rep(j, 1, m) {
			int t = pr[j].second;
			swap(a[i], a[t]);
			printf("%d %d\n", i, t);
		}
	}
	return 0;
}