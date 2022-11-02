/*
 * e.cpp
 *
 *  Created on: 2012-3-12
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <map>
#include <vector>
#include <ctime>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int t;

const int MAX_V = int(1e5);

bool is[MAX_V];

struct Trie {
	Trie*ch[10];
	int cnt;
	Trie() {
		cnt = 0;
		memset(ch, 0, sizeof ch);
	}
	Trie*get(int w) {
		if (ch[w] == 0) {
			ch[w] = new Trie();
			++cnt;
		}
		return ch[w];
	}
}*root[6];

void prep() {
	fill(is, is + MAX_V, true);
	for (int i = 2; i < MAX_V; ++i) {
		if (is[i]) {
			for (int j = i + i; j < MAX_V; j += i)
				is[j] = false;
		}
	}

	for (int i = 1; i <= 5; ++i) {
		root[i] = new Trie();
	}

	for (int i = 2; i < MAX_V; ++i) {
		if (is[i]) {
			int l = 0, x = i;
			static int ds[100];
			while (x != 0)
				ds[l++] = x % 10, x /= 10;
			reverse(ds, ds + l);
			Trie*cur = root[l];
			for (int i = 0; i < l; ++i) {
				cur = cur->get(ds[i]);
			}
			for (int bl = l + 1; bl <= 5; ++bl) {
				Trie*cur = root[bl];
				for (int i = 0; i < bl - l; ++i) {
					cur = cur->get(0);
				}
				for (int i = 0; i < l; ++i) {
					cur = cur->get(ds[i]);
				}
			}
		}
	}
}

string s;

Trie*row[6];
int n;

int ans;

map<vector<Trie*>, int> mp[10];

int dfs(int r, int c) {
	if (r == n - 1) {
		return row[n - 1]->cnt;
	}

	if (c == n) {
		return dfs(r + 1, r + 1);
	}

	if (r == c && r < n - 2) {
		vector<Trie*> v;
		for (int i = r; i < n; ++i) {
			v.push_back(row[i]);
		}
		if (mp[n].count(v))
			return mp[n][v];
	}

	int ret = 0;

	for (int d = 0; d < 10; ++d) {
		if (row[r]->ch[d] && row[c]->ch[d]) {
			Trie*oldr = row[r], *oldc = row[c];
			row[r] = row[r]->ch[d];
			if (r != c)
				row[c] = row[c]->ch[d];
			ret += dfs(r, c + 1);
			row[r] = oldr;
			row[c] = oldc;
		}
	}

	if (r == c && r < n - 2) {
		vector<Trie*> v;
		for (int i = r; i < n; ++i) {
			v.push_back(row[i]);
		}
		return mp[n][v] = ret;
	}

	return ret;
}

void work() {
	ans = 0;
	for (int i = 0; i < n; ++i) {
		row[i] = root[n];
	}
	for (int i = 0; i < n; ++i) {
		row[0] = row[0]->ch[s[i] - '0'];
	}
	for (int i = 1; i < n; ++i) {
		row[i] = row[i]->ch[s[i] - '0'];
	}
	cout << dfs(1, 1) << endl;
}

int main() {
//	freopen("in", "r", stdin);
	prep();
//	int cnt = 0;
//	for (int i = int(1e4); i < MAX_V && cnt < 30; ++i) {
//		if (is[i]) {
//			cout << i << endl;
//			++cnt;
//		}
//	}
	int start = clock();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> s;
		n = s.size();
		work();
	}
//	cout << (clock() - start) / (CLOCKS_PER_SEC * 1.0) << endl;
	return 0;
}