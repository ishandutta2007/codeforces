/*
 * a.cpp
 *
 *  Created on: 2012-2-24
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int INF = ~0U >> 3;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int k;
	cin >> k;
	bool bad[30][30] = { };
	for (int i = 0; i < k; ++i) {
		string t;
		cin >> t;
		int a = t[0] - 'a', b = t[1] - 'a';
		bad[a][b] = bad[b][a] = true;
	}
	vector<int> am(27, INF);
	am[26] = 0;
	for (int i = 0; i < n; ++i) {
		int me = s[i] - 'a';
		vector<int> nam(27, INF);
		for (int i = 0; i < 27; ++i) {
			if (!bad[i][me])
				nam[me] = min(nam[me], am[i]);
		}
		for (int i = 0; i < 27; ++i) {
			nam[i] = min(nam[i], am[i] + 1);
		}
		am = nam;
	}
	cout << *min_element(am.begin(), am.end()) << endl;
}