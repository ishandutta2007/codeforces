#include <bits/stdc++.h>
#define N 1000054

int A0, A1, B0, B1, C0, C1;
int ns, nt;
char s[N], t[N], u[N];
int f[N];

int main() {
	int i, j, b, fag = 0;
	scanf("%s%s", s, t); ns = strlen(s); nt = strlen(t);
	A0 = std::count(s, s + ns, '0'), A1 = std::count(s, s + ns, '1');
	B0 = std::count(t, t + nt, '0'), B1 = std::count(t, t + nt, '1');
	f[0] = -1, f[1] = j = 0;
	for (i = 1; i < nt; f[++i] = ++j)
		for (; j >= 0 && t[j] != t[i]; j = f[j]);
	b = f[nt];
//	fprintf(stderr, "b = %d\n", b);
	C0 = std::count(t, t + b, '0'), C1 = std::count(t, t + b, '1');
	assert(C0 + C1 == b && B0 + B1 == nt && A0 + A1 == ns);
	for (i = 0; i < ns; ) {
		if (A0 >= B0 && A1 >= B1) {
			memcpy(u + i, t, nt); A0 -= B0, A1 -= B1;
			i += nt - b, A0 += C0, A1 += C1;
			fag = 1;
		} else {
			if (fag) i += b, A0 -= C0, A1 -= C1;
			memset(u + i, 48, A0);
			memset(u + i + A0, 49, A1);
			break;
		}
	}
	u[ns] = 0;
	puts(u);
	return 0;
}