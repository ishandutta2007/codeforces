#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long int64;

int main() {
	int n, m, k;
	double pk;
	cin >> n >> m >> pk;
	k = int(pk * 100 + 1e-8);
	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		string a;
		int b;
		cin >> a >> b;
		b = b * k / 100;
		if (b >= 100) {
			mp[a] = b;
		}
	}
	for (int i = 0; i < m; ++i) {
		string a;
		cin >> a;
		if (!mp.count(a))
			mp[a] = 0;
	}
	cout << mp.size() << endl;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}