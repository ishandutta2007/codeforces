#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n;
int a[N];
ll U[N], V[N];

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	if (n == 1) return cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[1] << '\n', 0;
	for (i = 1; i <= n; ++i) U[i] = (n - 1ll) * a[i], V[i] = -(ll)n * a[i];
	cout << "1 1\n" << U[1] << '\n';
	cout << "2 " << n << '\n';
	for (i = 2; i <= n; ++i)
		cout << U[i] << (i == n ? '\n' : ' ');
	cout << "1 " << n << '\n';
	for (i = 1; i <= n; ++i)
		cout << V[i] << (i == n ? '\n' : ' ');
	return 0;
}