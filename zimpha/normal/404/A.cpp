#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

char g[400][400];
int n;

bool check() {
	for (int i = 0; i < n; ++ i)
		if (g[i][i] != g[0][0]) return false;
	for (int i = 0; i < n; ++ i) 
		if (g[0][0] != g[i][n - i - 1]) return false;
	if (g[0][0] == g[0][1]) return false;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			if (i == j || i + j == n - 1) continue;
			if (g[i][j] != g[0][1]) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%s", g[i]);
	if (check()) puts("YES");
	else puts("NO");
	return 0;
}