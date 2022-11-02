#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t;
	int a[200][200], b[200][200], d[200][200] = { };
	vector<string> my[200];
	string name[200];
	vector<pair<int, int> > cards; //idx,comp
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> a[i][j] >> b[i][j];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> name[i];
		int c;
		cin >> c;
		cards.push_back(make_pair(i, c));
	}

	int cur = 0;
	while (cards.size()) {
		int rem = t;
		while (cards.size()) {
			if (rem == 0)
				break;
			int st = cur / n, team = cur % n;
			pair<int, int> cd = cards.front();
			int T = max(cd.second - (a[team][st] + b[team][1 - st]) - d[team][cd.first], 1);
			if (T <= rem) {
				rem -= T;
				cards.erase(cards.begin());
				my[team].push_back(name[cd.first]);
			} else {
				cards.erase(cards.begin());
				cards.push_back(cd);
				d[team][cd.first] += rem;
				break;
			}
		}
		++cur;
		if (cur >= 2 * n)
			cur -= 2 * n;
	}

	for (int i = 0; i < n; ++i) {
		cout << my[i].size() << " ";
		for (int j = 0; j < my[i].size(); ++j) {
			cout << my[i][j] << " ";
		}
		cout << endl;
	}
}