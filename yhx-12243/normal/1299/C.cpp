#include <bits/stdc++.h>

typedef long long ll;
const int N = 1000054;

int n;
int a[N];
ll s[N];
int top = 0, stack[N];

inline double avg(int l, int r) {return double(s[r] - s[l - 1]) / double(r - l + 1);}

int main() {
	int i, j = 1; double t;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	for (i = 1; i <= n; ++i) {
		for (; top && avg(stack[top] + 1, i) <= avg(stack[top - 1] + 1, stack[top]); --top);
		stack[++top] = i;
	}
	for (i = 1; i <= top; ++i) {
		t = avg(stack[i - 1] + 1, stack[i]);
		for (; j <= stack[i]; ++j) printf("%.12lg\n", t);
	}
	return 0;
}