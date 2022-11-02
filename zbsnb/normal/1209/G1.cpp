#include<iostream>
#include<algorithm>
using namespace std;

int a[200010];
int num[200010];
int nxt[200010];
int pre[200010];

int main() {

	int n, t; cin >> n >> t;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (pre[a[i]] != 0)nxt[pre[a[i]]] = i;
		pre[a[i]] = i;
		num[a[i]]++;
	}
	//for (int i = 1; i <= n; i++)cout << i << " " << nxt[i] << endl;

	int ans = 0;
	int p = 1, q = nxt[1];
	while (p <= n) {

		if (q == 0) {
			p++; q = nxt[p];
			continue;
		}

		for (int i = p; i <= q; i++) {
			q = max(q, nxt[i]);
		}
		int maxn = 0;
		for (int i = p; i <= q; i++) {
			maxn = max(maxn, num[a[i]]);
		}
		ans += q - p + 1 - maxn;
		//cout << p << " " << q << endl;
		p = q + 1; q = nxt[p];
	}
	cout << ans << endl;
}