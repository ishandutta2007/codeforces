#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000;

vector<int> V[MAXN];
bool G[MAXN][MAXN];

int main() {
	int K, L; scanf("%d", &K);
	for (L = 0; ; ++ L) {
		if ((1 << L) > K) break;
	}
	memset(G, 0, sizeof(G));
	V[0].clear(); V[0].push_back(1);
	int n = 3;
	for (int i = 1; i <= L; ++ i) {
		V[i].clear();
		for (int j = 0; j < i + 1; ++ j) {
			V[i].push_back(n ++);
		}
		G[V[i - 1][0]][V[i][0]] = G[V[i][0]][V[i - 1][0]]= 1;
		for (int j = 1; j <(int)V[i].size(); ++ j) {
			for (int k = 0; k < j; ++ k)
				G[V[i][j]][V[i - 1][k]] = G[V[i - 1][k]][V[i][j]] = 1;
		}
	}
	for (int i = 1; K; K >>= 1, ++ i) {
		if (K & 1) {
			G[2][V[L][i]] = G[V[L][i]][2] = 1;
		}
	}
	printf("%d\n", n - 1);
	for (int i = 1; i < n; ++ i) {
		for (int j = 1; j < n; ++ j) {
			if (G[i][j]) putchar('Y');
			else putchar('N');
		}
		puts("");
	}
	return 0;
}