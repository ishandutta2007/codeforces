#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
const int maxn = 1e6;
int n, a[maxn + 3], top, st[maxn + 3];
ll s[maxn + 3];
db res[maxn + 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	st[++top] = 0;
	for (int i = 1; i <= n; i++) {
		while (top >= 2 && (s[i] - s[st[top]]) * (st[top] - st[top - 1]) < (s[st[top]] - s[st[top - 1]]) * (i - st[top])) {
			top--;
		}
		st[++top] = i;
	}
	for (int i = 1; i < top; i++) {
		db x = 1. * (s[st[i + 1]] - s[st[i]]) / (st[i + 1] - st[i]);
		for (int j = st[i] + 1; j <= st[i + 1]; j++) {
			res[j] = x;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%.12lf\n", res[i]);
	}
	return 0;
}