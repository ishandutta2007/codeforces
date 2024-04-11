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
const int MAXN = 100000 + 10;

vector<PII> ret;
VI level[MAXN];
int deg[MAXN];
int n, k;

bool solve(int md) {
	for (int i = 0; i <= md; ++ i)
		if (level[i].size() == 0) return false;
	if (level[0].size() > 1) return false;
	ret.clear();
	for (int i = 1; i <= md; ++ i) {
		int a = level[i - 1].size();
		int b = level[i].size();
		VI &A = level[i - 1];
		VI &B = level[i];
		int j, k, ttt = 0;
		for (j = 0, k = 0; j < b && k < a; ++ j) {
			while (k < a && deg[A[k]] == 0) k ++;
			if (k < a && deg[A[k]]) {
				ret.push_back(make_pair(A[k], B[j]));
				deg[A[k]] --;
				deg[B[j]] --;
				ttt ++;
			}
		}
		if (ttt < b) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i) {
		level[i].clear();
	}
	int md = 0;
	for (int i = 1, x; i <= n; ++ i) {
		scanf("%d", &x); deg[i] = k;
		level[x].push_back(i);
		md = max(md, x);
	}
	if (!solve(md)) puts("-1");
	else {
		printf("%d\n", (int)ret.size());
		for (int i = 0; i < (int)ret.size(); ++ i) {
			printf("%d %d\n", ret[i].first, ret[i].second);
		}
	}
	return 0;
}