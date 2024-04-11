#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n, k, p;
const int MAX_N = int(1e5) + 10;
vector<int> E[MAX_N];
int depcnt[MAX_N], maxdep;

void dfs(int u, int par, int d) {
	maxdep = max(maxdep, d);
	depcnt[d]++;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (*e != par) {
			dfs(*e, u, d + 1);
		}
}

int main() {
	cin >> n >> k >> p;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}

	maxdep = -1;
	dfs(0, -1, 0);

	int usedCoin = 0, usedWater = 0, j = maxdep;
	int ans = 0;

	for (int i = maxdep; i >= 0; --i) {
		while (j >= 1 && 1LL * (i - j) * depcnt[j] + usedCoin <= p
				&& usedWater + depcnt[j] <= k) {
			usedCoin += (i - j) * depcnt[j];
			usedWater += depcnt[j];
			--j;
		}
		//(j,i]
		ans = max(ans, usedWater);
		if (j >= 1) {
			int rem = k - usedWater;
			if (i != j)
				rem = min(rem, (p - usedCoin) / (i - j));
			ans = max(ans, usedWater + rem);
		}
		if (j < i) {
			//erase i
			usedWater -= depcnt[i];
		}
		//i->i-1
		usedCoin -= usedWater;
	}

	cout << ans << endl;
}