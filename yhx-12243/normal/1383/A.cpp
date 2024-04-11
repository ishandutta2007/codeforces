#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054;

int n;
int p[20];
char A[N], B[N];
bool G[20][20], H[20][20];

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

void work() {
	int i, j, ans = 0;
	cin >> n >> A >> B;
	memset(G, false, sizeof G);
	for (i = 0; i < 20; ++i) p[i] = i;
	for (i = 0; i < n; ++i) {
		A[i] -= 97, B[i] -= 97;
		if (A[i] > B[i]) {cout << "-1\n"; return;}
		p[ancestor(A[i])] = ancestor(B[i]);
	}
	for (i = 0; i < 20; ++i) ans += p[i] != i;
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}