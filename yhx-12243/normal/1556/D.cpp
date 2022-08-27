#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;
using std::endl;

const int N = 10054;

int n, K;
int a[N];

inline int And(int x, int y) {return cout << "and " << x << ' ' << y << endl, cin >> x, x;}
inline int Or(int x, int y) {return cout << "or " << x << ' ' << y << endl, cin >> x, x;}
inline int sum(int x, int y) {
	int a = And(x, y), b = Or(x, y);
	return a + b;
}

int main() {
	int i, ab, bc, ca; long long abc;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> K, --K;
	ab = sum(1, 2), bc = sum(2, 3), ca = sum(1, 3), abc = ((long long)ab + bc + ca) / 2,
	*a = abc - bc, a[1] = abc - ca, a[2] = abc - ab;
	for (i = 3; i < n; ++i) a[i] = sum(1, 1 + i) - *a;
	std::nth_element(a, a + K, a + n),
	cout << "finish " << a[K] << '\n';
	return 0;
}