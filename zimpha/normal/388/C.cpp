#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 110;

vector<int> C[MAXN];
vector<int> S;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n; scanf("%d", &n);
	S.clear();
	int Ciel = 0, Jiro = 0;
	for (int i = 0, s, x; i < n; ++ i) {
		C[i].clear();
		scanf("%d", &s); C[i].push_back(s);
		while (s --) {
			scanf("%d", &x);
			C[i].push_back(x);
		}
		for (int j = 1; j <= C[i][0] / 2; ++ j) Ciel += C[i][j];
		for (int j = (C[i][0] + 3) / 2; j <= C[i][0]; ++ j) Jiro += C[i][j];
		if (C[i][0] & 1) S.push_back(C[i][C[i][0] / 2 + 1]);
	}
	sort(S.begin(), S.end(), cmp);
	for (int i = 0; i < (int)S.size(); ++ i) {
		if (i & 1) Jiro += S[i];
		else Ciel += S[i];
	}
	printf("%d %d\n", Ciel, Jiro);
	return 0;
}