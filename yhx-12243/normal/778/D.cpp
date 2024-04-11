#include <bits/stdc++.h>

typedef std::pair <int, int> pr;
const int N = 54;
typedef char map[N][N], (*pmap)[N];

int R, C;
map A, B;
pr op[1000000], *l = op, *cp = op + 500000, *r = cp;

void readmap(pmap M) {for (int i = 0; i < R; ++i) scanf("%s", M[i]);}

bool normal(pmap M) {
	int i, j; bool U = false, L = false;
	for (i = 0; i < R; ++i)
		for (j = 0; j < C; ++j) U |= M[i][j] == 85, L |= M[i][j] == 76;
	return !(U && L);
}

#define op(name, a, b, c, d, e, f, g, h) \
	void name(pmap M, pr *&o) { \
		int i, j; \
		for (i = 1; i < R; ++i) \
			for (j = 1; j < C; ++j) \
				if (M[i - 1][j - 1] == a && M[i - 1][j] == b && M[i][j - 1] == c && M[i][j] == d) \
					*o++ = pr(i, j), M[i - 1][j - 1] = e, M[i - 1][j] = f, M[i][j - 1] = g, M[i][j] = h; \
	}

op(hor, 76, 82, 76, 82, 85, 85, 68, 68)
op(ver, 85, 85, 68, 68, 76, 82, 76, 82)

int main() {
	int i, j; pr *p;
	scanf("%d%d", &R, &C), readmap(A), readmap(B);
	for (; !normal(A); ver(A, l)) if (hor(A, l), normal(A)) break;
	for (; !normal(B); ver(B, r)) if (hor(B, r), normal(B)) break;
	if (**A != **B)
		for (i = 1; i < R; i += 2) for (j = 1; j < C; j += 2) *l++ = pr(i, j);
	printf("%d\n", int((l - op) + (r - cp)));
	for (p = op; p != l; printf("%d %d\n", p->first, p->second), ++p);
	for (p = r; p != cp; --p, printf("%d %d\n", p->first, p->second));
	return 0;
}