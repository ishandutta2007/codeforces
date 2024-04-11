#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 300 + 10;

int n;
int l[MAX_N], c[MAX_N];

int main() {
	cin >> n;

	vector<pair<int, int> > am, nam;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 0; i < n; ++i) {

		nam.clear();

		nam = am;
		nam.push_back(make_pair(l[i], c[i]));

		for (vector<pair<int, int> >::iterator e = am.begin(); e != am.end();
				++e) {
			int u = e->first, v = e->second;
			nam.push_back(make_pair(__gcd(l[i], u), v + c[i]));
		}

		sort(nam.begin(), nam.end());
		int cnt = 0;
		for (int i = 0; i < nam.size(); ++i) {
			if (cnt == 0 || nam[i].first != nam[cnt - 1].first)
				nam[cnt++] = nam[i];
		}
		nam.resize(cnt);
		am = nam;
	}

	if (nam[0].first == 1)
		cout << nam[0].second << endl;
	else
		cout << -1 << endl;
}