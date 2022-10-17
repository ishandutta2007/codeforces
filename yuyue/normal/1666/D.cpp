#include <bits/stdc++.h>

#define LL long long
#define ull unsigned long long
#define F(i,j,k) for(int i = j; i <= k; ++i)
#define DF(i,j,k) for(int i = j; i >= k; --i)

using namespace std;

template <typename T> inline void read(T &n) {
	T w = 1;
	n = 0;
	char ch = getchar();
	while (!isdigit(ch) && ch != EOF) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch) && ch!=EOF) {
		n = (n << 3) + (n << 1) + (ch ^ 48);
		ch = getchar();
	}
	n *= w;
}

template <typename T> inline void write(T x) {
	ull y = 0;
	T l = 0;
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (!x) {
		putchar(48);
		return;
	}
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
		++l;
	}
	while (l) {
		putchar(y%10+48);
		y /= 10;
		--l;
	}
}

template <typename T> inline void writeln(T x) {
	write(x);
	puts("");
}

template <typename T> inline void writes(T x) {
	write(x);
	putchar(' ');
}

template <typename T> inline void checkmax(T &a,T b) { a = a > b ? a : b; }

template <typename T> inline void checkmin(T &a,T b) { a = a < b ? a : b; }

int a[110], ok[110];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int T;
	read(T);
	while (T--) {
		string st1, st2, st3;
		cin >> st1 >> st2; st3 = "";
		memset(a, 0, sizeof(a));
		memset(ok, 0, sizeof(ok));
		F(i, 0, int(st2.size()) - 1) a[int(st2[i]) - 64]++;
		DF(i, int(st1.size()) - 1, 0) {
			if (a[int(st1[i]) - 64]) {
				--a[int(st1[i]) - 64];
				ok[i] = 1;
			}
		}
		F(i, 0, int(st1.size()) - 1) if (ok[i]) st3 += st1[i];
		puts(st3 == st2 ? "YES" : "NO");
	}
	
	return 0;
}