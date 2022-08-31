#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef std::pair <int, int> pr;
const int N = 108;

int n;
int a[N][N];
vector <pr> A, B;

void work(vector <pr> &S, int c) {
	int i, j;
	std::tie(i, j) = S.back(), S.pop_back(),
	cout << c << ' ' << i + 1 << ' ' << j + 1 << endl;
}

int main() {
	int i, j, c;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if ((i ^ j) & 1) B.emplace_back(i, j);
			else A.emplace_back(i, j);
	for (i = 0; i < n * n; ++i) {
		cin >> c;
		if (!(A.empty() || B.empty())) {
			if (c == 1) work(B, 2);
			else work(A, 1);
		} else if (!A.empty()) {
			if (c == 1) work(A, 3);
			else work(A, 1);
		} else if (!B.empty()) {
			if (c == 2) work(B, 3);
			else work(B, 2);
		}
	}
	return 0;
}