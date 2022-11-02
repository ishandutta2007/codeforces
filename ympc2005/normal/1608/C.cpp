#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e5 + 10;

int n, T, A[N], B[N], f[N];

pii a[N], b[N];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i].first);
			a[i].second = i;
			a[i].first *= -1;
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i].first);
			b[i].second = i;
			b[i].first *= -1;
		}

		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);

		for (int i = 1; i <= n; i++) {
			A[a[i].second] = i;
			B[b[i].second] = i;
			f[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			f[min(A[i], B[i])]++;
			f[max(A[i], B[i])]--;
		}

		int pos = n;

		for (int i = 1; i <= n; i++) {
			f[i] += f[i - 1];

			if (!f[i]) {
				pos = i;
				break;
			}
		}

		for (int i = 1; i <= n; i++) {
			printf("%d", min(A[i], B[i]) <= pos);
		}

		puts("");
	}
}