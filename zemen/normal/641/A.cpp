#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

const int maxn = 111111;

int n, a[maxn], used[maxn];
char s[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int x = 0;
	while (0 <= x && x < n && !used[x]) {
		used[x] = 1;
		if (s[x] == '>') x += a[x];
		else if (s[x] == '<') x -= a[x];
	}
	if (0 <= x && x < n) cout << "INFINITE\n";
	else cout << "FINITE\n";
  return 0;
}