#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

struct BipartiteMatch {
	bool edge[201][200000];
	int nX, nY;

	void init(int _nX, int _nY) {
		nX = _nX;
		nY = _nY;
		memset(edge, false, sizeof edge);
	}

	void addMatch(int x, int y) {
		edge[x][y] = true;
	}

	int linkY[200000];
	int linkX[200000];
	bool visited[200000];
	bool dfs(int x) {
		if (visited[x])
			return false;
		visited[x] = true;
		for (int y = 0; y < nY; ++y) {
			if (edge[x][y] && (linkY[y] == -1 || dfs(linkY[y])))
				return linkX[x] = y, linkY[y] = x, true;
		}
		return false;
	}
	int calcMaxMatch() {
		memset(linkY, -1, sizeof linkY);
		int cnt = 0;
		for (int x = 0; x < nX; ++x) {
			memset(visited, false, sizeof visited);
			if (dfs(x))
				++cnt;
		}

		return cnt;
	}
} s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	set<string> subs;
	int n;
	cin >> n;
	set<string> my[1000];
	set<string> all;

	for (int i = 0; i < n; ++i) {
		string a;
		cin >> a;
		set<string>&c = my[i];

		for (int s = 0; s < (1 << a.size()); ++s) {
			int cnt = 0;
			for (int j = 0; j < a.size(); ++j) {
				if (s >> j & 1)
					++cnt;
			}
			if (cnt < 1 || cnt > 4)
				continue;
			string cur;
			for (int j = 0; j < a.size(); ++j) {
				if (s >> j & 1)
					cur += a[j];
			}
			c.insert(cur);
		}

		all.insert(c.begin(), c.end());
	}

	map<string, int> id;
	int cur = 0;
	for (set<string>::iterator e = all.begin(); e != all.end(); ++e) {
		id[*e] = cur++;
	}

	s.init(n, all.size());
	for (int i = 0; i < n; ++i) {
		for (set<string>::iterator e = my[i].begin(); e != my[i].end(); ++e) {
			int c = id[*e];
			s.addMatch(i, c);
		}
	}

	vector<string> v(all.begin(), all.end());

	if (s.calcMaxMatch() == n) {
		for (int i = 0; i < n; ++i) {
			cout << v[s.linkX[i]] << endl;
		}
	} else {
		cout << -1 << endl;
	}
}