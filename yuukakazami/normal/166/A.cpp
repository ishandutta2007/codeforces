#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <utility>
using namespace std;

bool cmp(pair<int, int> a,pair<int, int> b) {
	if (a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);
	int cnt = count(a.begin(), a.end(), a[k - 1]);
	cout << cnt << endl;
	return 0;
}