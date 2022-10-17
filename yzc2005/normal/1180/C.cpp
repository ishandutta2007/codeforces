#include <bits/stdc++.h>
using namespace std;

int n, q, a[100005], x[100005], y[100005], b[100005];
deque <int> deq;
long long m;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i], deq.push_back(a[i]);
	for(int i = 1; i < n; ++i) {
		int a = deq.front(); deq.pop_front();
		int b = deq.front(); deq.pop_front();
		x[i] = a, y[i] = b;
		if(a < b) swap(a, b);
		deq.push_front(a), deq.push_back(b);
	}
	int mx = deq.front(); deq.pop_front();
	for(int i = 1; i < n; ++i) b[i] = deq.front(), deq.pop_front();
	while(q--) {
		cin >> m;
		if(m <= n - 1) cout << x[m] << " " << y[m] << endl;
		else cout << mx << " " << b[(m - 1) % (n - 1) + 1] << endl;
	}
	return 0;
}