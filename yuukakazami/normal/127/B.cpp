#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	int np = 0;
	for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
		np += it->second / 2;
	}
	cout << np / 2 << endl;
	return 0;
}