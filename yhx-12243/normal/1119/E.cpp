#include <bits/stdc++.h>

typedef long long ll;
const int N = 300054;

int n;
int a[N];
int la[N], cnt[N], top = 0;
ll ans = 0;

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < n; ++i) {
		if (!a[i]) continue;
		else if (a[i] == 1) la[++top] = i, cnt[top] = 1;
		else {
			for (; top && a[i] >= 2; ) {
				++ans, a[i] -= 2;
				if (!--cnt[top]) --top;
			}
			ans += a[i] / 3;
			if (a[i] %= 3) la[++top] = i, cnt[top] = a[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}

//1 2 4 8 8 8 8 8 8