/*
 * f.cpp
 *
 *  Created on: 2012-4-28
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 100 + 10;

int c2[MAX_N];

int n, k;

const int INF = ~0U >> 2;

struct Trie {
	Trie*ch[26];
	Trie() {
		memset(ch, 0, sizeof ch);
		cnt = 0;
	}
	Trie* get(int a) {
		if (ch[a] == 0)
			ch[a] = new Trie;
		return ch[a];
	}

	int am[MAX_N];
	int cnt;

	void solve() {
		for (int i = 0; i < 26; ++i) {
			if (ch[i])
				ch[i]->solve();
		}

		static int nxt[MAX_N];
		for (int i = 0; i <= k; ++i) {
			if (i <= cnt)
				am[i] = 0;
			else
				am[i] = -INF;
		}

		for (int i = 0; i < 26; ++i) {
			if (ch[i]) {
				fill(nxt, nxt + k + 1, -INF);
				int*a = am, *b = ch[i]->am;
				for (int p = 0; p <= k; ++p) {
					if (am[p] > -INF) {
						int eq = k - p;
						for (int q = 0; q <= eq; ++q) {
							nxt[p + q] = max(nxt[p + q], a[p] + b[q]);
						}
					}
				}
				memcpy(am, nxt, sizeof(int) * (k + 1));
			}
		}

		for (int i = 0; i <= k; ++i) {
			am[i] += c2[i];
		}
	}
};

int main() {
	cin >> n >> k;
	for (int i = 0; i < MAX_N; ++i) {
		c2[i] = i * (i - 1) / 2;
	}

	Trie*rt = new Trie;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		Trie*t = rt;
		for (int j = 0; j < s.size(); ++j) {
			t = t->get(s[j] - 'a');
		}
		t->cnt++;
	}

	rt->solve();
	cout << rt->am[k] - c2[k] << endl;
	return 0;
}