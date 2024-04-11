# include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector <int> L, R;
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		L.push_back(l);
		R.push_back(r);
	}
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	long long ans = n;
	for (int i = 0; i < n; ++i)
		ans += max(L[i], R[i]);
	printf("%lld\n", ans);
}