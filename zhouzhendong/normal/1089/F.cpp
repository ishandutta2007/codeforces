#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, k, cnt;
int divi[N];

void check(int x, int y) {
	int sum = n / y * y;
	while (sum >= 0) {
		if ((n - sum) % x == 0) {
			int a = (n - sum) / x;
			int b = sum / y;
			puts("YES");
			puts("2");
			printf("%d %d\n", a, y);
			printf("%d %d\n", b, x);
			exit(0);
		}
		sum -= y;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			divi[++cnt] = i;
			if (i * i != n) {
				divi[++cnt] = n / i;
			}
		}
	}
	sort(divi + 1, divi + cnt + 1);
	--n;
	for (int i = 2; i + i <= cnt; ++i) {
		int x = divi[i], y = divi[cnt - i + 1];
		if (__gcd(x, y) == 1) {
			check(x, y);
		}
	}
	puts("NO");
	return 0;
}