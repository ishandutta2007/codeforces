#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 300054;

int n;
char a[N], b[N], c[N], s[N];
int A0, A1, B0, B1, C0, C1;
bool Ag, Bg, Cg;

void work() {
	int i, j, k; char w;
	cin >> n >> a >> b >> c;
	A0 = std::count(a, a + 2 * n, '0'), A1 = 2 * n - A0;
	B0 = std::count(b, b + 2 * n, '0'), B1 = 2 * n - B0;
	C0 = std::count(c, c + 2 * n, '0'), C1 = 2 * n - C0;
	Ag = A1 >= A0, Bg = B1 >= B0, Cg = C1 >= C0;
	if (Ag == Bg);
	else if (Bg == Cg) memcpy(a, c, 2 * n);
	else if (Ag == Cg) memcpy(b, c, 2 * n);
	else throw "gg";
	A0 = std::count(a, a + 2 * n, '0'), A1 = 2 * n - A0;
	B0 = std::count(b, b + 2 * n, '0'), B1 = 2 * n - B0;
	C0 = std::count(c, c + 2 * n, '0'), C1 = 2 * n - C0;
	Ag = A1 >= A0, Bg = B1 >= B0, Cg = C1 >= C0;
	w = Ag ? '1' : '0';
	for (i = j = k = 0; i < 2 * n || j < 2 * n; ) {
		if (i == 2 * n) s[k++] = b[j++];
		else if (j == 2 * n) s[k++] = a[i++];
		else if (a[i] == b[j]) s[k++] = a[i++], ++j;
		else if (a[i] == w) s[k++] = b[j++];
		else s[k++] = a[i++];
	}
	s[3 * n] = 0, cout << s << '\n';
	fprintf(stderr, "a = %s, b = %s\n", a, b);
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}