#include <bits/stdc++.h>

const int N = 254;

int R, C;
int a[N][N];
bool rf[N], cf[N];

inline void flipRow(int r) {rf[r] = !rf[r]; for (int j = 0; j < C; ++j) a[r][j] ^= 1;}
inline void flipCol(int c) {cf[c] = !cf[c]; for (int i = 0; i < R; ++i) a[i][c] ^= 1;}

int success() {
	int i; puts("YES");
	for (i = 0; i < R; ++i) putchar(rf[i] | 48); putchar(10);
	for (i = 0; i < C; ++i) putchar(cf[i] | 48); putchar(10);
	return 0;
}

bool checkDown() {
	int i, s; bool flag = false;
	for (i = 1; i < R; ++i) {
		if (s = std::count(a[i], a[i] + C, 1), flag) {
			if (!s) flipRow(i);
			else if (s == C) ;
			else return false;
		} else {
			if (!s) ;
			else if (s == C) flipRow(i);
			else if (std::count(a[i] + (C - s), a[i] + C, 1) == s) flag = true;
			else if (std::count(a[i], a[i] + s, 1) == s) flipRow(i), flag = true;
			else return false;
		}
	}
	return true;
}

bool checkUp() {
	int i, s; bool flag = false;
	for (i = R - 1; i >= 0; --i) {
		if (s = std::count(a[i], a[i] + C, 1), flag) {
			if (!s) ;
			else if (s == C) flipRow(i);
			else return false;
		} else {
			if (!s) flipRow(i);
			else if (s == C) ;
			else if (std::count(a[i] + (C - s), a[i] + C, 1) == s) flag = true;
			else if (std::count(a[i], a[i] + s, 1) == s) flipRow(i), flag = true;
			else return false;
		}
	}
	return true;
}

int main() {
	int i, j;
	scanf("%d%d", &R, &C);
	for (i = 0; i < R; ++i)
		for (j = 0; j < C; ++j) scanf("%d", a[i] + j);

	for (j = 0; j < C; ++j) if (a[0][j]) flipCol(j);
	if (checkDown()) return success();

	for (j = 0; j < C; ++j) flipCol(j);
	if (flipRow(0), checkDown()) return success();

	for (j = 0; j < C; ++j) if (!a[R - 1][j]) flipCol(j);
	if (checkUp()) return success();

	for (j = 0; j < C; ++j) flipCol(j);
	if (flipRow(R - 1), checkUp()) return success();

	return puts("NO"), 0;
}