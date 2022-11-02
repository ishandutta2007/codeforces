#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

typedef long long int64;
int64 n;

vector<int64> a;
vector<int> pw;
int64 pws[1000][100];

//(a+b)(a+c)(b+c)=n/3

int64 ans;

void rec(int i, int64 A, int64 B, int64 C) {
	if (i == (int) a.size()) {
		int64 tot = A + B + C;
		if (tot % 2 != 0)
			return;
		tot /= 2;
		int64 x = tot - A, y = tot - B, z = tot - C;
		if (x <= 0 || y <= 0 || z <= 0)
			return;
		++ans;
		return;
	}

	int64*p = pws[i];
	for (int a = 0; a <= pw[i]; ++a) {
		for (int b = 0; a + b <= pw[i]; ++b) {
			int c = pw[i] - a - b;
			rec(i + 1, A * p[a], B * p[b], C * p[c]);
		}
	}
}

int main() {
	cin >> n;
	if (n % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	n /= 3;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				++cnt;
				n /= i;
			}
			a.push_back(i);
			pw.push_back(cnt);
		}
	}

	if (n > 1) {
		a.push_back(n);
		pw.push_back(1);
	}

	for (int i = 0; i < a.size(); ++i) {
		pws[i][0] = 1;
		for (int j = 1; j <= pw[i]; ++j) {
			pws[i][j] = pws[i][j - 1] * a[i];
		}
	}

	rec(0, 1, 1, 1);
	cout << ans << endl;
}