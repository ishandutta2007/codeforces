#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 30054;

int n;
int a[N], b[N], c[N];
 
void work() {
	int i;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	b[1] = a[1];
	for (i = 2; i <= n; ++i)
		if (a[i - 1] < a[i])
			b[i] = b[i - 1];
		else {
			b[i] = b[i - 1] + a[i] - a[i - 1];
			if (b[i] < 0) {
				cout << "NO\n"; return;
			}
		}
	cout << "YES\n";
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}