#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int a, b;
	cin >> a >> b;
	vector<pair<int, int> > ps(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ps[i] = make_pair(x * a + y * b, i);
	}
	sort(ps.begin(), ps.end());
	int cnt = 0;
	for (int i = 0; i < ps.size(); ++i) {
		d -= ps[i].first;
		if (d >= 0)
			++cnt;
		else
			break;
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i) {
		printf("%d ", ps[i].second + 1);
	}
	puts("");
	return 0;
}