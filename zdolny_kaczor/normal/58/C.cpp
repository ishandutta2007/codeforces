# include <cstdio>
# include <map>
using namespace std;
int main() {
	map <int, int> used;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		used[x - min(i, n - i + 1)]++;
	}
	int best = 0;
	for (auto v : used) {
		if (v.first >= 0) {
			best = max(best, v.second);
		}
	}
	printf("%d\n", n - best);
}