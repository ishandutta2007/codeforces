#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n, m, k;
const int MAX_N = 1000 + 10;
int a[MAX_N][MAX_N];

bool rt[MAX_N][MAX_N]; //i,j - i,j+1
bool down[MAX_N][MAX_N]; //i,j - i+1,j

bool get() {
	char c;
	for (;;) {
		c = getchar();
		if (c != 'N' && c != 'E')
			continue;
		break;
	}
	return c == 'E';
}

int calc(int c) { //c and c+1
	int cnt = 0;
	for (int r = 0; r < n; ++r) {
		if (rt[r][c] == (a[r][c] == a[r][c + 1]))
			++cnt;
	}
	return cnt;
}

int calc2(int r) { //r and r+1
	int cnt = 0;
	for (int c = 0; c < m; ++c) {
		if (down[r][c] == (a[r][c] == a[r + 1][c]))
			++cnt;
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;

	int tot = 0;

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c + 1 < m; ++c) {
			rt[r][c] = get();
			++tot;
		}
		if (r + 1 < n) {
			for (int c = 0; c < m; ++c) {
				down[r][c] = get();
				++tot;
			}
		}
	}

	if (k == 1) {
		int cntE = 0;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c + 1 < m; ++c) {
				cntE += rt[r][c];
			}
			if (r + 1 < n) {
				for (int c = 0; c < m; ++c) {
					cntE += down[r][c];
				}
			}
		}
		//cntE/tot >= 3/4?
		if (cntE * 4 >= tot * 3) {
			puts("YES");
			for (int r = 0; r < n; ++r) {
				for (int c = 0; c < m; ++c) {
					putchar('1');
					putchar(' ');
				}
				puts("");
			}
		} else {
			puts("NO");
		}
		return 0;
	}

	//k>=2
	if (n > m) {
		for (int c = 0; c < m; ++c) {
			a[0][c] = 1;
			for (int r = 0; r + 1 < n; ++r) {
				if (down[r][c])
					a[r + 1][c] = a[r][c];
				else
					a[r + 1][c] = 3 - a[r][c];
			}
		}

		for (int c = 0; c + 1 < m; ++c) {
			int x = calc(c), y = n - x;
			if (x < y) { //filp c+1
				for (int r = 0; r < n; ++r) {
					a[r][c + 1] = 3 - a[r][c + 1];
				}
			}
//			ans += max(x, y);
		}

//	cerr << 1.0 * ans / tot << endl;
	} else {
		for (int r = 0; r < n; ++r) {
			a[r][0] = 1;
			for (int c = 0; c + 1 < m; ++c) {
				if (rt[r][c])
					a[r][c + 1] = a[r][c];
				else
					a[r][c + 1] = 3 - a[r][c];
			}
		}

		for (int r = 0; r + 1 < n; ++r) {
			//r and r+1
			int x = calc2(r), y = m - x;
			if (x < y) { //filpe r+1
				for (int c = 0; c < m; ++c) {
					a[r + 1][c] = 3 - a[r + 1][c];
				}
			}
		}
	}

	puts("YES");
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			putchar(char('0' + a[r][c]));
			putchar(' ');
		}
		puts("");
	}
	return 0;
}