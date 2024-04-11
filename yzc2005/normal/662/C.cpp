#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20, M = 100000;
int n, m, mask[M];
ll a[1 << N], b[1 << N];
char ch[M];

inline void XOR(ll *a, int n, bool rev) {
	for(int k = 2, m = 1; k <= n; k <<= 1, m <<= 1) {
		for(int j = 0; j < n; j += k) for(int i = 0; i < m; ++i) {
			ll x = a[j + i], y = a[j + i + m];
			if(!rev) {
				a[j + i] = x + y;
				a[j + i + m] = x - y;
			} else {
				a[j + i] = x + y >> 1;
				a[j + i + m] = x - y >> 1;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%s", ch);
		for(int j = 0; j < m; ++j) mask[j] |= (ch[j] - '0') << i;
	}
	for(int i = 0; i < m; ++i) ++a[mask[i]];
	for(int i = 0; i < 1 << n; ++i) b[i] = b[i >> 1] + (i & 1);
	for(int i = 0; i < 1 << n; ++i) b[i] = min(b[i], n - b[i]);
	XOR(a, 1 << n, 0), XOR(b, 1 << n, 0);
	for(int i = 0; i < 1 << n; ++i) a[i] *= b[i];
	XOR(a, 1 << n, 1);	
	printf("%lld\n", *min_element(a, a + (1 << n)));
	return 0;
}