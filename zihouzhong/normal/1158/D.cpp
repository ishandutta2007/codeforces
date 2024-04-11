#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n;
pair<int, int> p[maxn];
bool vis[maxn];
char s[maxn];

pair<int, int> operator - (pair<int, int> x, pair<int, int> y) {
	return {x.first - y.first, x.second - y.second};
}

long long operator * (pair<int, int> x, pair<int, int> y) {
	return 1LL * x.first * y.second - 1LL * x.second * y.first;
}

int main() {
	scanf("%d", &n);
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
		if (p[i].first < p[cur].first) cur = i;
	}
	scanf("%s", s + 1);
	printf("%d ", cur), vis[cur] = 1;
	for (int i = 1; i < n; i++) {
		vector<int> V;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) V.push_back(j);
		}
		sort(V.begin(), V.end(), [&](int x, int y) {
			return (p[x] - p[cur]) * (p[y] - p[cur]) > 0;
		});
		cur = s[i] == 'L' ? V[0] : V.back();
		printf("%d ", cur), vis[cur] = 1;
	}
	return 0;
}