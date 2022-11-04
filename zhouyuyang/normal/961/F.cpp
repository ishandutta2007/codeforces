#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M = 233333, P = 998244353;
const int V = 1000010;
#define get getchar
void Read(char *s, int &len) {
	len = 0; static char c;
	for (; !islower(c); c = get());
	for (; islower(c); s[len++] = c, c = get());
}
LL Pw[V], Ha[V];
int n;
char s[V];
void Pre() {
	Pw[0] = 1;
	for (int i = 1; i <= n; i++) Pw[i] = (Pw[i - 1] * M) % P;
	for (int i = 1; i <= n; i++) Ha[i] = (Ha[i - 1] * M + s[i]) % P;
}
LL Str(int l, int r) {
	return (Ha[r] - Ha[l - 1] * Pw[r - l + 1] % P + P) % P;
}

vector<int> G;
int main() {
	Read(s + 1, n); Pre();
	int len = -1, L, l, r;
	if (n % 2 == 0) {
		L = 2; l = n / 2, r = n / 2 + 1; len = 1;
	} else {
		L = 1; l = r = (n + 1) / 2; len = -1;
	}
	for (int i = 1; i <= (n + 1) / 2; i++) {
		len = min(len, r - l + 1);
		while (len > 0 && Str(l, l + len - 1) != Str(r - len + 1, r)) len -= 2;
		G.push_back(len);
		l--; r++; len += 2;
	}
	reverse(G.begin(), G.end());
	for (int i = 0; i < G.size(); i++) cout << G[i] << ' '; cout << endl;
	return 0;
}