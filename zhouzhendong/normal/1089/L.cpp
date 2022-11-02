#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, k;
int a[N], v[N];
vector<int> vec[N], tmp;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);		
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &v[i]);
	}
	for (int i = 1; i <= n; ++i) {
		vec[a[i]].push_back(v[i]);
	}
	for (int i = 1; i <= k; ++i) {
		sort(vec[i].begin(), vec[i].end());
		int t = vec[i].size() - 1;
		for (int j = 0; j < t; ++j) {
			tmp.push_back(vec[i][j]);
		}
	}
	sort(tmp.begin(), tmp.end());
	long long ans = 0;
	for (int i = 1, j = 0; i <= k; ++i) {
		if (vec[i].size() == 0) {
			ans += tmp[j];
			++j;
		}
	}
	cout << ans << endl;
}