#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, k;
int g[N][N];
void work(int l, int r, int a, int b) {
	r = min(n + 1, r);
	for (int i = l; i < r; i += a)
		for (int j = i; j < i + a; ++j) 
			for (int k = i + a; k < r; ++k)
				g[j][k] = b;
}
int main() { 
	cin >> n >> k;
	int a = 1, b = 1;
	while (a < n) {
		for (int i = 1; i <= n; i += a * k)
			work(i, i + a * k, a, b);
		a *= k;
		++b;
	}
	cout << b - 1 << endl;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			cout << g[i][j] << " ";
	return 0;
}